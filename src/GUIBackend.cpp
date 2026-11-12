// Manages SDL and ImGui initialization, GUI event processing, GUI rendering, and shutdown
// Standard libraries and internal headers
#include <iostream> // Used for debug prints
#include "GameInfo.h" // Used for game name in SDL window creation
#include "GameState.h" // Used for holding feedback screen
#include "GUIBackend.h" // Used for InitializeGUI() declaration
#include "GUIHelpers.h" // Used for back navigations
#include "GUIStyle.h" // Used for LoadGUIStyle(), ui_scale and feedback durations
#include "platform/Paths.h" // Used to get asset paths
// External libraries and headers
#include "imgui.h" // ImGUI API
#include "backends/imgui_impl_sdl3.h" // ImGui SDL link
#include "backends/imgui_impl_vulkan.h" // ImGui Vulkan link
#include <SDL3/SDL.h> // SDL API
#include <SDL3_mixer/SDL_mixer.h> // Used for audio system
#include "Vulkan.h" // Used for many Vulkan calls throughout the file

// Window configuration
static constexpr int window_width = 1280;
static constexpr int window_height = 720;

static constexpr SDL_WindowFlags sdl_window_flags =
    SDL_WINDOW_VULKAN |
    SDL_WINDOW_RESIZABLE;

// Handles
SDL_Window *window = nullptr;
MIX_Mixer* sdl_mixer = nullptr;
MIX_Audio *button_press_sound = nullptr;
ImFont *custom_font = nullptr;

// Try to initialize SDL, SDL Mixer, Vulkan and ImGui, closes game if any fails
bool InitializeEverything() {
// If on windows, add the library dir before trying to load them
#ifdef _WIN32
    if (!Paths::AddLibraryDirectoryToDllSearchPath()) {
        std::cerr << "Failed to add library directory to DLL search path." << std::endl;
        return false;
    }
#endif

    // SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    std::cout << "SDL initialized successfully." << std::endl;

    // The window to be created
    window = SDL_CreateWindow(game_info.game_name.c_str(), window_width, window_height, sdl_window_flags);
    if (window == nullptr) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    std::cout << "SDL window created successfully." << std::endl;

    // Load and set window icon
    SDL_Surface* icon = SDL_LoadBMP(Paths::GetAssetPath("icons/GTAVVoicelineGuesser_Icon.bmp").string().c_str());

    if (icon) {
        SDL_SetWindowIcon(window, icon);
        SDL_DestroySurface(icon);
        std::cout << "Window icon loaded successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to load window icon: " << SDL_GetError() << std::endl;
    }
  
    // SDL Mixer for audio
    if (!MIX_Init()) {
        std::cerr << "Failed to initialize SDL Mixer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
  
    sdl_mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);

    if (sdl_mixer == nullptr) {
        std::cerr << "Failed to create SDL Mixer: " << SDL_GetError() << std::endl;
        MIX_Quit();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    std::cout << "SDL Mixer initialized successfully." << std::endl;

    // Vulkan
    if (!InitializeVulkan(window)) {
        std::cerr << "Vulkan initialization failed." << std::endl;
        MIX_Quit();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    std::cout << "Vulkan initialized successfully." << std::endl;

    // ImGui
    if (!InitializeGUI(window)) {
        std::cerr << "ImGui initialization failed." << std::endl;
        ShutdownVulkan();
        MIX_Quit();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }  
    std::cout << "ImGui initialized successfully." << std::endl;
    return true;
}

// Vulkan error callback for ImGui
static void CheckImGuiVulkanResult(VkResult result) {
    if (result == VK_SUCCESS) {
        return;
    }
    std::cerr << "[ImGui Vulkan] VkResult = " << result << std::endl;
}

// Initialize ImGui and Vulkan
bool InitializeGUI(SDL_Window *window) {
    // Create ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    // UI scale needs to be updated before GUI style is loaded
    UpdateUIScale(window);
    // Load GUI style right after init
    LoadGUIStyle();
    // Custom font needs to be loaded here
    custom_font = ImGui::GetIO().Fonts->AddFontFromFileTTF(Paths::GetAssetPath("fonts/SquadaOne-Regular.ttf").string().c_str(), font_base_size);
    ImGuiIO& io = ImGui::GetIO();
    // Prevent creation of imgui.ini
    io.IniFilename = nullptr;

    // Enable keyboard navigation (tabbing, enter etc)
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Load sound and adjust volume
    button_press_sound = MIX_LoadAudio(sdl_mixer, Paths::GetAssetPath("audio/button_press_sound.mp3").string().c_str(), false);
    MIX_SetMixerGain(sdl_mixer, 0.25);

    // Initialize SDL3 backend
    if (!ImGui_ImplSDL3_InitForVulkan(window)) {
        std::cerr << "Failed to initialize ImGui SDL3 backend." << std::endl;
        ImGui::DestroyContext();
        return false;
    }

    // Configure Vulkan backend
    ImGui_ImplVulkan_InitInfo init_info{};
    init_info.ApiVersion = VK_API_VERSION_1_3;
    init_info.Instance = GetVulkanInstance();
    init_info.PhysicalDevice = GetVulkanPhysicalDevice();
    init_info.Device = GetVulkanDevice();
    init_info.QueueFamily = GetVulkanGraphicsQueueFamily();
    init_info.Queue = GetVulkanGraphicsQueue();
    // Give ImGui plenty of headroom
    init_info.DescriptorPoolSize = 1000;
    init_info.MinImageCount = GetVulkanSwapchainImageCount();
    init_info.ImageCount = GetVulkanSwapchainImageCount();
    init_info.CheckVkResultFn = CheckImGuiVulkanResult;
    // Use dynamic rendering as its simpler
    init_info.UseDynamicRendering = true;
    init_info.PipelineInfoMain.MSAASamples = VK_SAMPLE_COUNT_1_BIT;
    VkFormat swapchain_format = GetVulkanSwapchainImageFormat();
    init_info.PipelineInfoMain.PipelineRenderingCreateInfo = {};
    init_info.PipelineInfoMain.PipelineRenderingCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO;
    init_info.PipelineInfoMain.PipelineRenderingCreateInfo.colorAttachmentCount = 1;
    init_info.PipelineInfoMain.PipelineRenderingCreateInfo.pColorAttachmentFormats = &swapchain_format;

    // Initialize Vulkan backend
    if (!ImGui_ImplVulkan_Init(&init_info)) {
        std::cerr << "Failed to initialize ImGui Vulkan backend." << std::endl;
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
        return false;
    }

    // Load menu background
    if (!LoadVulkanBackgroundTexture(Paths::GetAssetPath("images/menu_background.png").string().c_str())) {
        std::cerr << "Failed to load menu background." << std::endl;
        ImGui_ImplVulkan_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
        return false;
    }

    std::cout << "ImGui initialized successfully." << std::endl;
    return true;
}

// Process GUI
void ProcessGUIEvent(const SDL_Event &event) {
    ImGui_ImplSDL3_ProcessEvent(&event);
}

// Handles toggling between fullscreen and windowed using F11
// Has an issue on Windows where the initial 720p window briefly appears when fullscreen is ended
// while the window is maximized. Looks like SDL intended behavior:
// https://github.com/libsdl-org/SDL/blob/main/src/video/windows/SDL_windowswindow.c#L1365
void ToggleFullscreen(SDL_Window *window) {
    Uint32 flags = SDL_GetWindowFlags(window);
    if (flags & SDL_WINDOW_FULLSCREEN) {
        SDL_SetWindowFullscreen(window, false);
    }
    else {
        SDL_SetWindowFullscreen(window, true);
    }
}

// Updates UI to scale ImGui elements to current resolution
void UpdateUIScale(SDL_Window* window) {
    int pixel_width = 0;
    int pixel_height = 0;
    SDL_GetWindowSizeInPixels(window, &pixel_width, &pixel_height);
    ui_scale = static_cast<float>(pixel_height) / reference_height;
}

// SDL event runner, for keybind handling etc
SDL_Event event;
void SDLEventRunner(bool &game_running) {
    while (SDL_PollEvent(&event)) {
      ProcessGUIEvent(event);

      if (event.type == SDL_EVENT_QUIT) {
          game_running = false;
      }

      // Detects when the window resolution changed and makes vulkan and the UI update to it
      if (event.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED) {
        MarkVulkanSwapchainOutdated();
        UpdateUIScale(window);
      }

      // Toggles between fullscreen and windowed with F11
      if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_F11) {
        ToggleFullscreen(window);
      }

      // Pressing enter (either main enter or numpad enter) during gameplay confirms the entered answer
      if (game_state.in_gameplay_screen && event.type == SDL_EVENT_KEY_DOWN && (event.key.key == SDLK_RETURN || event.key.key == SDLK_KP_ENTER)) {
        ConfirmAnswer();
      }

      // Pressing enter (either main enter or numpad enter) during settings confirms the selected settings
      // Needs to be placed after answer confirmation or the first round will have its answer instantly confirmed
      if (game_state.in_settings_screen && event.type == SDL_EVENT_KEY_DOWN && (event.key.key == SDLK_RETURN || event.key.key == SDLK_KP_ENTER)) {
        ConfirmSettings();
      }

      // Pressing escape key during main screen quits game
      // Needs to be first among escape key handlers or else pressing escape in any menu quits 
      // the game because the next checks run quicker than ImGui considers the key to be released
      if (game_state.in_main_screen && event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
        QuitGame();
      }

      // Pressing escape key during gameplay goes back to main
      if (game_state.in_gameplay_screen && event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
        GameplayExit();
      }

      // Pressing escape key during credits goes back to main
      if (game_state.in_credits_screen && event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
        CreditsBack();
      }

      // Pressing escape key during help goes back to main
      if (game_state.in_help_screen && event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
        HelpBack();
      }

      // Pressing escape key during results goes back to main
      if (game_state.in_results_screen && event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
        ResultsExit();
      }

      // Pressing escape key during settings goes back to main
      if (game_state.in_settings_screen && event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
        SettingsBack();
      }
    }
}

// Timer to hold the gameplay screen for some time to show correctness of inputs before continuing to next round
namespace {
    float answer_feedback_timer = 0.0f;
}
void StartAnswerFeedback() {
    game_state.in_answer_feedback = true;

    if (game_state.debug_enabled) {
        answer_feedback_timer = answer_feedback_duration_debug;
    }
    else {
        answer_feedback_timer = answer_feedback_duration;
    }
}

// Begin GUI Frame
void BeginGUIFrame() {
    ImGui_ImplVulkan_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    // Timer logic for input correctness display
    if (answer_feedback_timer > 0.0f) {
        answer_feedback_timer -= ImGui::GetIO().DeltaTime;

        // Timer is finished
        if (answer_feedback_timer <= 0.0f) {
            answer_feedback_timer = 0.0f;
            game_state.answer_feedback_finished = true;
        }
    }
}

// Render GUI
void RenderGUI(VkCommandBuffer command_buffer) {
    ImGui::Render();
    ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), command_buffer);
}

// Render GUI Frame
void RenderGUIFrame() {
    if (!BeginVulkanFrame())
        return;
    BeginVulkanRendering();
    RenderGUI(GetCurrentVulkanCommandBuffer());
    EndVulkanRendering();
    EndVulkanFrame();
}

// Properly shut everything down to close the game
void ShutdownEverything() {
    vkDeviceWaitIdle(GetVulkanDevice());
    DestroyImGuiTexture();
    ImGui_ImplVulkan_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
    ShutdownVulkan();
    MIX_DestroyMixer(sdl_mixer);
    MIX_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
}
