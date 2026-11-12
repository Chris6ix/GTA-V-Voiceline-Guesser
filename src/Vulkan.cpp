// Manages Vulkan initialization, GPU resources, rendering synchronization, frame submission, and presentation
// Standard libraries and internal headers
#include <iostream> // Used for debug prints
#include <algorithm> // Used in ChooseSwapExtent()
#include <limits> // Used in ChooseSwapExtent()
#include <vector> // Used for vectors e.g in CreateLogicalDevice()
#include <cstring> // Used for extension comparison
#include "Vulkan.h" // Used for forward declarations
#include "GameInfo.h" // Provides game name
// External libraries and headers
#include <SDL3/SDL.h> // SDL API
#include <SDL3/SDL_vulkan.h> // SDL Vulkan link
#include <vulkan/vulkan.h> // Vulkan API
#include "backends/imgui_impl_vulkan.h" // Required for ImGui_ImplVulkan_SetMinImageCount()
#define STB_IMAGE_IMPLEMENTATION // Used for rendering background image
#include "stb_image.h" // Used for rendering background image

// -----------------------------------------------------------------------------
// Vulkan objects owned by this file
// -----------------------------------------------------------------------------

static VkInstance vulkan_instance = VK_NULL_HANDLE;
static VkSurfaceKHR vulkan_surface = VK_NULL_HANDLE;

static VkPhysicalDevice vulkan_physical_device = VK_NULL_HANDLE;
static VkDevice vulkan_device = VK_NULL_HANDLE;

static VkQueue graphics_queue = VK_NULL_HANDLE;
static VkQueue present_queue = VK_NULL_HANDLE;

// -----------------------------------------------------------------------------
// Swapchain
// -----------------------------------------------------------------------------

static VkSwapchainKHR swapchain = VK_NULL_HANDLE;

static SDL_Window* vulkan_window = nullptr;
static bool swapchain_outdated = false;

static std::vector<VkImage> swapchain_images;
static std::vector<VkImageView> swapchain_image_views;

static VkFormat swapchain_image_format = VK_FORMAT_UNDEFINED;
static VkExtent2D swapchain_extent{};
static uint32_t current_swapchain_image = 0;

// -----------------------------------------------------------------------------
// Command infrastructure
// -----------------------------------------------------------------------------

static VkCommandPool command_pool = VK_NULL_HANDLE;

static std::vector<VkCommandBuffer> command_buffers;

static VkSemaphore image_available_semaphore = VK_NULL_HANDLE;
static VkSemaphore render_finished_semaphore = VK_NULL_HANDLE;

static VkFence in_flight_fence = VK_NULL_HANDLE;

// -----------------------------------------------------------------------------
// Background texture
// -----------------------------------------------------------------------------

static VkImage background_image = VK_NULL_HANDLE;
static VkDeviceMemory background_image_memory = VK_NULL_HANDLE;
static VkImageView background_image_view = VK_NULL_HANDLE;

static VkDescriptorSet background_texture = VK_NULL_HANDLE;

static int background_image_width = 0;
static int background_image_height = 0;

// -----------------------------------------------------------------------------
// Required device extensions
// -----------------------------------------------------------------------------

const std::vector<const char*> device_extensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

// -----------------------------------------------------------------------------
// Queue family information
// -----------------------------------------------------------------------------

struct QueueFamilyIndices {
    uint32_t graphics_family = UINT32_MAX;
    uint32_t present_family = UINT32_MAX;
    bool IsComplete() const {
        return graphics_family != UINT32_MAX && present_family != UINT32_MAX;
    }
};

// -----------------------------------------------------------------------------
// Swapchain support information
// -----------------------------------------------------------------------------

struct SwapchainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities{};
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> present_modes;
};

// -----------------------------------------------------------------------------
// Texture helper functions
// -----------------------------------------------------------------------------

static uint32_t FindMemoryType(uint32_t type_filter, VkMemoryPropertyFlags properties);

static bool CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, 
                        VkBuffer& buffer, VkDeviceMemory& buffer_memory);

static VkCommandBuffer BeginSingleTimeCommands();

static bool EndSingleTimeCommands(VkCommandBuffer command_buffer);

static bool TransitionImageLayout(VkCommandBuffer command_buffer, VkImage image, VkImageLayout old_layout, VkImageLayout new_layout);

static bool CopyBufferToImage(VkCommandBuffer command_buffer, VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

static bool CreateBackgroundTexture(const char* filename);

static void DestroyBackgroundTexture();

// -----------------------------------------------------------------------------
// Find suitable Vulkan memory type
// -----------------------------------------------------------------------------

static uint32_t FindMemoryType(uint32_t type_filter, VkMemoryPropertyFlags properties) {
    VkPhysicalDeviceMemoryProperties memory_properties{};
    vkGetPhysicalDeviceMemoryProperties(vulkan_physical_device, &memory_properties);

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i) {
        if ((type_filter & (1u << i)) && (memory_properties.memoryTypes[i].propertyFlags & properties) == properties) {
            return i;
        }
    }

    return UINT32_MAX;
}

// -----------------------------------------------------------------------------
// Create Vulkan buffer
// -----------------------------------------------------------------------------

static bool CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties,
                        VkBuffer& buffer, VkDeviceMemory& buffer_memory) {
    VkBufferCreateInfo buffer_info{};
    buffer_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.size = size;
    buffer_info.usage = usage;
    buffer_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    VkResult result = vkCreateBuffer(vulkan_device, &buffer_info, nullptr, &buffer);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan buffer. Error: "
                  << result << std::endl;
        return false;
    }

    VkMemoryRequirements memory_requirements{};
    vkGetBufferMemoryRequirements(vulkan_device, buffer, &memory_requirements);

    uint32_t memory_type = FindMemoryType(memory_requirements.memoryTypeBits, properties);

    if (memory_type == UINT32_MAX) {
        std::cerr << "Failed to find suitable buffer memory type." << std::endl;
        vkDestroyBuffer(vulkan_device, buffer, nullptr);
        buffer = VK_NULL_HANDLE;
        return false;
    }

    VkMemoryAllocateInfo allocate_info{};
    allocate_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize = memory_requirements.size;
    allocate_info.memoryTypeIndex = memory_type;
    result = vkAllocateMemory(vulkan_device, &allocate_info, nullptr, &buffer_memory);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to allocate Vulkan buffer memory. Error: "
                  << result << std::endl;
        vkDestroyBuffer(vulkan_device, buffer, nullptr);
        buffer = VK_NULL_HANDLE;
        return false;
    }

    result = vkBindBufferMemory(vulkan_device, buffer, buffer_memory, 0);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to bind Vulkan buffer memory. Error: "
                  << result << std::endl;
        vkFreeMemory(vulkan_device, buffer_memory, nullptr);
        vkDestroyBuffer(vulkan_device, buffer, nullptr);
        buffer_memory = VK_NULL_HANDLE;
        buffer = VK_NULL_HANDLE;
        return false;
    }

    return true;
}

// -----------------------------------------------------------------------------
// Begin one-time command buffer
// -----------------------------------------------------------------------------

static VkCommandBuffer BeginSingleTimeCommands() {
    VkCommandBufferAllocateInfo allocate_info{};
    allocate_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocate_info.commandPool = command_pool;
    allocate_info.commandBufferCount = 1;
    VkCommandBuffer command_buffer = VK_NULL_HANDLE;
    VkResult result = vkAllocateCommandBuffers(vulkan_device, &allocate_info, &command_buffer);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to allocate temporary Vulkan command buffer. "
                  << "Error: " << result << std::endl;
        return VK_NULL_HANDLE;
    }

    VkCommandBufferBeginInfo begin_info{};
    begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    result = vkBeginCommandBuffer(command_buffer, &begin_info);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to begin temporary Vulkan command buffer. "
                  << "Error: " << result << std::endl;
        vkFreeCommandBuffers(vulkan_device, command_pool, 1, &command_buffer);
        return VK_NULL_HANDLE;
    }

    return command_buffer;
}

// -----------------------------------------------------------------------------
// Finish one-time command buffer
// -----------------------------------------------------------------------------

static bool EndSingleTimeCommands(VkCommandBuffer command_buffer) {
    VkResult result = vkEndCommandBuffer(command_buffer);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to end temporary Vulkan command buffer. "
                  << "Error: " << result << std::endl;
        vkFreeCommandBuffers(vulkan_device, command_pool, 1, &command_buffer);
        return false;
    }

    VkSubmitInfo submit_info{};
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers = &command_buffer;
    result = vkQueueSubmit(graphics_queue, 1, &submit_info, VK_NULL_HANDLE);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to submit temporary Vulkan command buffer. "
                  << "Error: " << result << std::endl;
        vkFreeCommandBuffers(vulkan_device, command_pool, 1, &command_buffer);
        return false;
    }

    // The texture is loaded during initialization, so waiting here is
    // perfectly acceptable and keeps the upload code simple.
    result = vkQueueWaitIdle(graphics_queue);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed waiting for texture upload. "
                  << "Error: " << result << std::endl;
        vkFreeCommandBuffers(vulkan_device, command_pool, 1, &command_buffer);
        return false;
    }

    vkFreeCommandBuffers(vulkan_device, command_pool, 1, &command_buffer);
    return true;
}

// -----------------------------------------------------------------------------
// Transition Vulkan image layout
// -----------------------------------------------------------------------------

static bool TransitionImageLayout(VkCommandBuffer command_buffer, VkImage image, VkImageLayout old_layout, VkImageLayout new_layout) {
    VkImageMemoryBarrier2 barrier{};
    barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2;
    barrier.oldLayout = old_layout;
    barrier.newLayout = new_layout;
    barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.image = image;
    barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    barrier.subresourceRange.baseMipLevel = 0;
    barrier.subresourceRange.levelCount = 1;
    barrier.subresourceRange.baseArrayLayer = 0;
    barrier.subresourceRange.layerCount = 1;

    if (old_layout == VK_IMAGE_LAYOUT_UNDEFINED && new_layout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) {
        barrier.srcStageMask = VK_PIPELINE_STAGE_2_NONE;
        barrier.srcAccessMask = VK_ACCESS_2_NONE;
        barrier.dstStageMask = VK_PIPELINE_STAGE_2_COPY_BIT;
        barrier.dstAccessMask = VK_ACCESS_2_TRANSFER_WRITE_BIT;
    }
    else if (old_layout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL && new_layout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL) {
        barrier.srcStageMask = VK_PIPELINE_STAGE_2_COPY_BIT;
        barrier.srcAccessMask = VK_ACCESS_2_TRANSFER_WRITE_BIT;
        barrier.dstStageMask = VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT;
        barrier.dstAccessMask = VK_ACCESS_2_SHADER_SAMPLED_READ_BIT;
    }
    else {
        std::cerr << "Unsupported image layout transition." << std::endl;
        return false;
    }

    VkDependencyInfo dependency_info{};
    dependency_info.sType = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
    dependency_info.imageMemoryBarrierCount = 1;
    dependency_info.pImageMemoryBarriers = &barrier;
    vkCmdPipelineBarrier2(command_buffer, &dependency_info);
    return true;
}

// -----------------------------------------------------------------------------
// Copy staging buffer into Vulkan image
// -----------------------------------------------------------------------------

static bool CopyBufferToImage(VkCommandBuffer command_buffer, VkBuffer buffer, VkImage image, uint32_t width, uint32_t height) {
    VkBufferImageCopy region{};
    region.bufferOffset = 0;
    region.bufferRowLength = 0;
    region.bufferImageHeight = 0;
    region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    region.imageSubresource.mipLevel = 0;
    region.imageSubresource.baseArrayLayer = 0;
    region.imageSubresource.layerCount = 1;
    region.imageOffset = {0, 0, 0};
    region.imageExtent = {
        width,
        height,
        1
    };

    vkCmdCopyBufferToImage(command_buffer, buffer, image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &region);
    return true;
}

// -----------------------------------------------------------------------------
// Create background texture
// -----------------------------------------------------------------------------

static bool CreateBackgroundTexture(const char* filename) {
    std::cout << "Loading background texture: "
              << filename << std::endl;
    int width = 0;
    int height = 0;
    int channels = 0;
    stbi_uc* pixels = stbi_load(filename, &width, &height, &channels, STBI_rgb_alpha);

    if (pixels == nullptr) {
        std::cerr << "Failed to load background image: "
                  << filename << std::endl
                  << "stb_image error: "
                  << stbi_failure_reason()
                  << std::endl;
        return false;
    }

    const VkDeviceSize image_size = static_cast<VkDeviceSize>(width) * static_cast<VkDeviceSize>(height) * 4;
    background_image_width = width;
    background_image_height = height;

    // -------------------------------------------------------------------------
    // Create staging buffer
    // -------------------------------------------------------------------------

    VkBuffer staging_buffer = VK_NULL_HANDLE;
    VkDeviceMemory staging_buffer_memory = VK_NULL_HANDLE;

    if (!CreateBuffer(image_size, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
        staging_buffer, staging_buffer_memory)) {
            stbi_image_free(pixels);
            return false;
    }

    // Copy image pixels into staging buffer.
    void* mapped_data = nullptr;
    VkResult result = vkMapMemory(vulkan_device, staging_buffer_memory, 0, image_size, 0, &mapped_data);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to map staging buffer memory. Error: "
                  << result << std::endl;
        vkDestroyBuffer(vulkan_device, staging_buffer, nullptr);
        vkFreeMemory(vulkan_device, staging_buffer_memory, nullptr);
        stbi_image_free(pixels);
        return false;
    }

    std::memcpy(mapped_data, pixels, static_cast<size_t>(image_size));
    vkUnmapMemory(vulkan_device, staging_buffer_memory);
    stbi_image_free(pixels);

    // -------------------------------------------------------------------------
    // Create Vulkan image
    // -------------------------------------------------------------------------

    VkImageCreateInfo image_info{};
    image_info.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_info.imageType = VK_IMAGE_TYPE_2D;
    // Use sRGB because this is a normal color image/background.
    image_info.format = VK_FORMAT_R8G8B8A8_SRGB;
    image_info.extent.width = static_cast<uint32_t>(width);
    image_info.extent.height = static_cast<uint32_t>(height);
    image_info.extent.depth = 1;
    image_info.mipLevels = 1;
    image_info.arrayLayers = 1;
    image_info.samples = VK_SAMPLE_COUNT_1_BIT;
    image_info.tiling = VK_IMAGE_TILING_OPTIMAL;
    image_info.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
    image_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    image_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    result = vkCreateImage(vulkan_device, &image_info, nullptr, &background_image);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create background Vulkan image. Error: "
                  << result << std::endl;
        vkDestroyBuffer(vulkan_device, staging_buffer, nullptr);
        vkFreeMemory(vulkan_device, staging_buffer_memory, nullptr);
        return false;
    }

    // -------------------------------------------------------------------------
    // Allocate image memory
    // -------------------------------------------------------------------------

    VkMemoryRequirements memory_requirements{};
    vkGetImageMemoryRequirements(vulkan_device, background_image, &memory_requirements);
    uint32_t memory_type = FindMemoryType(memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

    if (memory_type == UINT32_MAX) {
        std::cerr << "Failed to find suitable background image memory."
                  << std::endl;
        vkDestroyImage(vulkan_device, background_image, nullptr);
        background_image = VK_NULL_HANDLE;
        vkDestroyBuffer(vulkan_device, staging_buffer, nullptr);
        vkFreeMemory(vulkan_device, staging_buffer_memory, nullptr);
        return false;
    }

    VkMemoryAllocateInfo memory_allocate_info{};
    memory_allocate_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    memory_allocate_info.allocationSize = memory_requirements.size;
    memory_allocate_info.memoryTypeIndex = memory_type;
    result = vkAllocateMemory(vulkan_device, &memory_allocate_info, nullptr, &background_image_memory);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to allocate background image memory. Error: "
                  << result << std::endl;
        vkDestroyImage(vulkan_device, background_image, nullptr);
        background_image = VK_NULL_HANDLE;
        vkDestroyBuffer(vulkan_device, staging_buffer, nullptr);
        vkFreeMemory(vulkan_device, staging_buffer_memory,nullptr);
        return false;
    }

    result = vkBindImageMemory(vulkan_device, background_image, background_image_memory, 0);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to bind background image memory. Error: "
                  << result << std::endl;
        vkFreeMemory(vulkan_device, background_image_memory, nullptr);
        vkDestroyImage(vulkan_device, background_image, nullptr);
        background_image_memory = VK_NULL_HANDLE;
        background_image = VK_NULL_HANDLE;
        vkDestroyBuffer(vulkan_device, staging_buffer, nullptr);
        vkFreeMemory(vulkan_device, staging_buffer_memory, nullptr);
        return false;
    }

    // -------------------------------------------------------------------------
    // Upload image to GPU
    // -------------------------------------------------------------------------

    VkCommandBuffer command_buffer = BeginSingleTimeCommands();

    if (command_buffer == VK_NULL_HANDLE) {
        return false;
    }

    if (!TransitionImageLayout(command_buffer, background_image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL)) {
        return false;
    }

    CopyBufferToImage(command_buffer, staging_buffer, background_image, static_cast<uint32_t>(width), static_cast<uint32_t>(height));

    if (!TransitionImageLayout(command_buffer, background_image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL)) {
        return false;
    }

    if (!EndSingleTimeCommands(command_buffer)) {
        return false;
    }

    // The staging buffer is no longer needed.
    vkDestroyBuffer(vulkan_device, staging_buffer, nullptr);
    vkFreeMemory(vulkan_device, staging_buffer_memory, nullptr);

    // -------------------------------------------------------------------------
    // Create image view
    // -------------------------------------------------------------------------

    VkImageViewCreateInfo view_info{};
    view_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    view_info.image = background_image;
    view_info.viewType = VK_IMAGE_VIEW_TYPE_2D;
    view_info.format = VK_FORMAT_R8G8B8A8_SRGB;
    view_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    view_info.subresourceRange.baseMipLevel = 0;
    view_info.subresourceRange.levelCount = 1;
    view_info.subresourceRange.baseArrayLayer = 0;
    view_info.subresourceRange.layerCount = 1;
    result = vkCreateImageView( vulkan_device, &view_info, nullptr, &background_image_view);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create background image view. Error: "
                  << result << std::endl;
        DestroyBackgroundTexture();
        return false;
    }

    // -------------------------------------------------------------------------
    // Register texture with Dear ImGui
    // -------------------------------------------------------------------------

    background_texture = ImGui_ImplVulkan_AddTexture(background_image_view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

    if (background_texture == VK_NULL_HANDLE) {
        std::cerr << "Failed to register background texture with ImGui."
                  << std::endl;
        DestroyBackgroundTexture();
        return false;
    }

    std::cout << "Background texture loaded successfully: "
              << width << "x" << height
              << std::endl;
    return true;
}

// -----------------------------------------------------------------------------
// Destroy background texture
// -----------------------------------------------------------------------------

// Destroy the ImGui texture before shutting down ImGui to avoid an access violation.
void DestroyImGuiTexture() {
    if (background_texture != VK_NULL_HANDLE) {
        ImGui_ImplVulkan_RemoveTexture(background_texture);
        background_texture = VK_NULL_HANDLE;
    }
}

static void DestroyBackgroundTexture() {
    if (vulkan_device == VK_NULL_HANDLE) {
        return;
    }

    if (background_image_view != VK_NULL_HANDLE) {
        vkDestroyImageView(vulkan_device, background_image_view, nullptr);
        background_image_view = VK_NULL_HANDLE;
    }

    if (background_image != VK_NULL_HANDLE) {
        vkDestroyImage(vulkan_device, background_image, nullptr);
        background_image = VK_NULL_HANDLE;
    }

    if (background_image_memory != VK_NULL_HANDLE) {
        vkFreeMemory(vulkan_device, background_image_memory, nullptr);
        background_image_memory = VK_NULL_HANDLE;
    }

    background_image_width = 0;
    background_image_height = 0;
}

// -----------------------------------------------------------------------------
// Find queue families
// -----------------------------------------------------------------------------

static QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device) {
    QueueFamilyIndices indices;
    uint32_t queue_family_count = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_count, nullptr);
    std::vector<VkQueueFamilyProperties> queue_families(queue_family_count);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_count, queue_families.data());

    for (uint32_t i = 0; i < queue_family_count; ++i) {
        if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphics_family = i;
        }

        VkBool32 present_support = VK_FALSE;
        VkResult result = vkGetPhysicalDeviceSurfaceSupportKHR(device, i, vulkan_surface, &present_support);

        if (result == VK_SUCCESS && present_support) {
            indices.present_family = i;
        }

        if (indices.IsComplete()) {
            break;
        }
    }
    return indices;
}

// -----------------------------------------------------------------------------
// Check device extension support
// -----------------------------------------------------------------------------

static bool CheckDeviceExtensionSupport(VkPhysicalDevice device) {
    uint32_t extension_count = 0;
    VkResult result = vkEnumerateDeviceExtensionProperties(device, nullptr, &extension_count, nullptr);

    if (result != VK_SUCCESS) {
        return false;
    }

    std::vector<VkExtensionProperties> available_extensions(extension_count);
    result = vkEnumerateDeviceExtensionProperties(device, nullptr, &extension_count, available_extensions.data());

    if (result != VK_SUCCESS) {
        return false;
    }

    for (const char* required_extension : device_extensions) {
        bool found = false;

        for (const auto& extension : available_extensions) {
            if (strcmp(required_extension, extension.extensionName) == 0) {
                found = true;
                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    return true;
}

// -----------------------------------------------------------------------------
// Query swapchain support
// -----------------------------------------------------------------------------

static SwapchainSupportDetails QuerySwapchainSupport(VkPhysicalDevice device) {
    SwapchainSupportDetails details;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, vulkan_surface, &details.capabilities);
    uint32_t format_count = 0;
    vkGetPhysicalDeviceSurfaceFormatsKHR(device, vulkan_surface, &format_count, nullptr);

    if (format_count != 0) {
        details.formats.resize(format_count);
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, vulkan_surface, &format_count, details.formats.data());
    }

    uint32_t present_mode_count = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(device, vulkan_surface, &present_mode_count, nullptr);

    if (present_mode_count != 0) {
        details.present_modes.resize(present_mode_count);
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, vulkan_surface, &present_mode_count, details.present_modes.data());
    }

    return details;
}

// -----------------------------------------------------------------------------
// Check whether physical device is suitable
// -----------------------------------------------------------------------------

static bool IsDeviceSuitable(VkPhysicalDevice device) {
    QueueFamilyIndices indices = FindQueueFamilies(device);
    bool extensions_supported = CheckDeviceExtensionSupport(device);
    bool swapchain_adequate = false;

    if (extensions_supported) {
        SwapchainSupportDetails swapchain_support = QuerySwapchainSupport(device);
        swapchain_adequate = !swapchain_support.formats.empty() && !swapchain_support.present_modes.empty();
    }

    return indices.IsComplete() && extensions_supported && swapchain_adequate;
}

// -----------------------------------------------------------------------------
// Choose swapchain surface format
// -----------------------------------------------------------------------------

static VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& available_formats) {
    for (const auto& available_format : available_formats) {
        if (available_format.format == VK_FORMAT_B8G8R8A8_SRGB 
            && available_format.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
            return available_format;
        }
    }

    return available_formats[0];
}

// -----------------------------------------------------------------------------
// Choose presentation mode
// -----------------------------------------------------------------------------

static VkPresentModeKHR ChooseSwapPresentMode(
    const std::vector<VkPresentModeKHR>& available_present_modes)
{
    for (VkPresentModeKHR mode : available_present_modes) {
        if (mode == VK_PRESENT_MODE_IMMEDIATE_KHR) {
            return mode;
        }
    }
    // FIFO (Vsync) is guaranteed by Vulkan
    return VK_PRESENT_MODE_FIFO_KHR;
}


// -----------------------------------------------------------------------------
// Choose swapchain extent
// -----------------------------------------------------------------------------

static VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, SDL_Window* window) {
    if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
        return capabilities.currentExtent;
    }

    int width = 0;
    int height = 0;
    SDL_GetWindowSizeInPixels(window, &width, &height);
    VkExtent2D actual_extent {
        static_cast<uint32_t>(width),
        static_cast<uint32_t>(height)
    };

    actual_extent.width = std::clamp(actual_extent.width, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
    actual_extent.height = std::clamp(actual_extent.height, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);
    return actual_extent;
}

// -----------------------------------------------------------------------------
// Create swapchain image views
// -----------------------------------------------------------------------------

static bool CreateSwapchainImageViews() {
    swapchain_image_views.resize(swapchain_images.size());

    for (size_t i = 0; i < swapchain_images.size(); ++i) {
        VkImageViewCreateInfo create_info{};
        create_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        create_info.image = swapchain_images[i];
        create_info.viewType = VK_IMAGE_VIEW_TYPE_2D;
        create_info.format = swapchain_image_format;
        create_info.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        create_info.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        create_info.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        create_info.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        create_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        create_info.subresourceRange.baseMipLevel = 0;
        create_info.subresourceRange.levelCount = 1;
        create_info.subresourceRange.baseArrayLayer = 0;
        create_info.subresourceRange.layerCount = 1;
        VkResult result = vkCreateImageView(vulkan_device, &create_info, nullptr, &swapchain_image_views[i]);

        if (result != VK_SUCCESS) {
            std::cerr << "Failed to create swapchain image view. "
                      << "Error: " << result << std::endl;
            return false;
        }
    }

    std::cout << "Swapchain image views created: "
         << swapchain_image_views.size()
         << std::endl;
    return true;
}

// -----------------------------------------------------------------------------
// Create swapchain
// -----------------------------------------------------------------------------

static bool CreateSwapchain(SDL_Window* window) {
    SwapchainSupportDetails swapchain_support = QuerySwapchainSupport(vulkan_physical_device);
    VkSurfaceFormatKHR surface_format = ChooseSwapSurfaceFormat(swapchain_support.formats);
    VkPresentModeKHR present_mode = ChooseSwapPresentMode(swapchain_support.present_modes);
    VkExtent2D extent = ChooseSwapExtent(swapchain_support.capabilities, window);

    // Ask for one more image than the minimum.
    uint32_t image_count = swapchain_support.capabilities.minImageCount + 1;

    if (swapchain_support.capabilities.maxImageCount > 0 && image_count > swapchain_support.capabilities.maxImageCount) {
        image_count = swapchain_support.capabilities.maxImageCount;
    }

    VkSwapchainCreateInfoKHR create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    create_info.surface = vulkan_surface;
    create_info.minImageCount = image_count;
    create_info.imageFormat = surface_format.format;
    create_info.imageColorSpace = surface_format.colorSpace;
    create_info.imageExtent = extent;
    create_info.imageArrayLayers = 1;
    create_info.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    QueueFamilyIndices queue_family_indices = FindQueueFamilies(vulkan_physical_device);
    uint32_t queue_family_indices_array[] = {queue_family_indices.graphics_family, queue_family_indices.present_family};

    if (queue_family_indices.graphics_family != queue_family_indices.present_family) {
        create_info.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        create_info.queueFamilyIndexCount = 2;
        create_info.pQueueFamilyIndices = queue_family_indices_array;
    }
    else {
        create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    }

    create_info.preTransform = swapchain_support.capabilities.currentTransform;
    create_info.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    create_info.presentMode = present_mode;
    create_info.clipped = VK_TRUE;
    create_info.oldSwapchain = VK_NULL_HANDLE;

    VkResult result = vkCreateSwapchainKHR(vulkan_device, &create_info, nullptr, &swapchain);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan swapchain. "
                  << "Error: " << result << std::endl;
        return false;
    }

    // Retrieve the actual swapchain images.
    uint32_t actual_image_count = 0;
    vkGetSwapchainImagesKHR(vulkan_device, swapchain, &actual_image_count, nullptr);
    swapchain_images.resize(actual_image_count);
    vkGetSwapchainImagesKHR(vulkan_device, swapchain, &actual_image_count, swapchain_images.data());
    swapchain_image_format = surface_format.format;
    swapchain_extent = extent;
    std::cout << "Vulkan swapchain created successfully." << std::endl
              << "  Image count: " << swapchain_images.size() << std::endl
              << "  Resolution: " << swapchain_extent.width << "x" << swapchain_extent.height << std::endl
              << "  Format: " << swapchain_image_format << std::endl
              << "  Present mode: " << (present_mode == VK_PRESENT_MODE_IMMEDIATE_KHR ? "IMMEDIATE" : "FIFO") << std::endl;

    return CreateSwapchainImageViews();
}

// -----------------------------------------------------------------------------
// Recreate swapchain after window resize
// -----------------------------------------------------------------------------

static bool CreateCommandBuffers();

static bool RecreateSwapchain() {
    if (vulkan_device == VK_NULL_HANDLE || vulkan_window == nullptr) {
        return false;
    }

    int width = 0;
    int height = 0;
    SDL_GetWindowSizeInPixels(vulkan_window, &width, &height);

    // The window may temporarily have a zero-sized drawable area when minimized.
    if (width == 0 || height == 0) {
        return false;
    }

    VkResult result = vkDeviceWaitIdle(vulkan_device);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed waiting for Vulkan device during swapchain recreation. "
                  << "Error: " << result << std::endl;
        return false;
    }

    // Free old command buffers before allocating new ones.
    if (!command_buffers.empty()) {
        vkFreeCommandBuffers(
            vulkan_device,
            command_pool,
            static_cast<uint32_t>(command_buffers.size()),
            command_buffers.data()
        );
        command_buffers.clear();
    }

    // Destroy old image views.
    for (VkImageView image_view : swapchain_image_views) {
        vkDestroyImageView(vulkan_device, image_view, nullptr);
    }

    swapchain_image_views.clear();
    swapchain_images.clear();

    // Destroy the old swapchain.
    if (swapchain != VK_NULL_HANDLE) {
        vkDestroySwapchainKHR(vulkan_device, swapchain, nullptr);
        swapchain = VK_NULL_HANDLE;
    }

    // Create the new swapchain.
    if (!CreateSwapchain(vulkan_window)) {
        std::cerr << "Failed to recreate Vulkan swapchain." << std::endl;
        return false;
    }

    // Command buffers depend on the number of swapchain images.
    if (!CreateCommandBuffers()) {
        std::cerr << "Failed to recreate Vulkan command buffers." << std::endl;
        return false;
    }

    // Tell ImGui about the new swapchain image count.
    ImGui_ImplVulkan_SetMinImageCount(GetVulkanSwapchainImageCount());

    current_swapchain_image = 0;

    std::cout << "Vulkan swapchain recreated successfully." << std::endl
              << "  Resolution: " << swapchain_extent.width << "x"
              << swapchain_extent.height << std::endl;

    return true;
}


// -----------------------------------------------------------------------------
// Pick physical device
// -----------------------------------------------------------------------------

static bool PickPhysicalDevice() {
    uint32_t device_count = 0;
    VkResult result = vkEnumeratePhysicalDevices(vulkan_instance, &device_count, nullptr);

    if (result != VK_SUCCESS || device_count == 0) {
        std::cerr << "Failed to find any Vulkan-compatible GPU." << std::endl;
        return false;
    }

    std::vector<VkPhysicalDevice> devices(device_count);
    result = vkEnumeratePhysicalDevices(vulkan_instance, &device_count, devices.data());

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to enumerate Vulkan physical devices." << std::endl;
        return false;
    }

    std::cout << std::endl
              << "Available Vulkan GPUs:" << std::endl;

    for (VkPhysicalDevice device : devices) {
        VkPhysicalDeviceProperties properties{};
        vkGetPhysicalDeviceProperties(device, &properties);
        std::cout << "  " << properties.deviceName << std::endl
                  << "    Vulkan API: " << VK_VERSION_MAJOR(properties.apiVersion) 
                  << "." << VK_VERSION_MINOR(properties.apiVersion)
                  << "." << VK_VERSION_PATCH(properties.apiVersion) << std::endl;
        QueueFamilyIndices indices = FindQueueFamilies(device);
        std::cout << "    Graphics queue family: ";

        if (indices.graphics_family != UINT32_MAX) {
            std::cout << indices.graphics_family << std::endl;
        }
        else {
            std::cout << "None" << std::endl;
        }

        std::cout << "    Present queue family: ";

        if (indices.present_family != UINT32_MAX) {
            std::cout << indices.present_family << std::endl;
        }
        else {
            std::cout << "None" << std::endl;
        }

        std::cout << "    Swapchain support: " << (IsDeviceSuitable(device) ? "Yes" : "No") << std::endl
                  << std::endl;
    }

    // Prefer a suitable discrete GPU.
    for (VkPhysicalDevice device : devices) {
        VkPhysicalDeviceProperties properties{};
        vkGetPhysicalDeviceProperties(device, &properties);

        if (properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU && IsDeviceSuitable(device)) {
            vulkan_physical_device = device;
            break;
        }
    }

    // Fall back to any suitable GPU.
    if (vulkan_physical_device == VK_NULL_HANDLE) {
        for (VkPhysicalDevice device : devices) {
            if (IsDeviceSuitable(device)) {
                vulkan_physical_device = device;
                break;
            }
        }
    }

    if (vulkan_physical_device == VK_NULL_HANDLE) {
        std::cerr << "No suitable Vulkan GPU was found." << std::endl;
        return false;
    }

    VkPhysicalDeviceProperties selected_properties{};
    vkGetPhysicalDeviceProperties(vulkan_physical_device, &selected_properties);
    QueueFamilyIndices selected_indices = FindQueueFamilies(vulkan_physical_device);
    std::cout << "Selected GPU: " << selected_properties.deviceName << std::endl
              << "Graphics queue family: " << selected_indices.graphics_family << std::endl
              << "Present queue family: " << selected_indices.present_family << std::endl;
    return true;
}

// -----------------------------------------------------------------------------
// Create logical device and queues
// -----------------------------------------------------------------------------

static bool CreateLogicalDevice() {
    QueueFamilyIndices indices = FindQueueFamilies(vulkan_physical_device);
    std::vector<uint32_t> unique_queue_families = {indices.graphics_family};

    if (indices.present_family != indices.graphics_family) {
        unique_queue_families.push_back(indices.present_family);
    }

    const float queue_priority = 1.0f;
    std::vector<VkDeviceQueueCreateInfo> queue_create_infos;

    for (uint32_t queue_family : unique_queue_families) {
        VkDeviceQueueCreateInfo queue_create_info{};
        queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queue_create_info.queueFamilyIndex = queue_family;
        queue_create_info.queueCount = 1;
        queue_create_info.pQueuePriorities = &queue_priority;
        queue_create_infos.push_back(queue_create_info);
    }

    VkPhysicalDeviceFeatures device_features{};
    VkPhysicalDeviceDynamicRenderingFeatures dynamic_rendering_features{};
    dynamic_rendering_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES;
    dynamic_rendering_features.dynamicRendering = VK_TRUE;
    VkDeviceCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    create_info.queueCreateInfoCount = static_cast<uint32_t>(queue_create_infos.size());
    create_info.pQueueCreateInfos = queue_create_infos.data();
    create_info.enabledExtensionCount = static_cast<uint32_t>(device_extensions.size());
    create_info.ppEnabledExtensionNames = device_extensions.data();
    create_info.pEnabledFeatures = &device_features;
    create_info.pNext = &dynamic_rendering_features;
    VkResult result = vkCreateDevice(vulkan_physical_device, &create_info, nullptr, &vulkan_device);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan logical device. "
                  << "Error: " << result << std::endl;
        return false;
    }

    vkGetDeviceQueue(vulkan_device, indices.graphics_family, 0, &graphics_queue);
    vkGetDeviceQueue(vulkan_device, indices.present_family, 0, &present_queue);
    std::cout << "Vulkan logical device created successfully." << std::endl;
    return true;
}

// -----------------------------------------------------------------------------
// Create Command Pool
// -----------------------------------------------------------------------------

static bool CreateCommandPool() {
    QueueFamilyIndices queue_family_indices = FindQueueFamilies(vulkan_physical_device);
    VkCommandPoolCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    create_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex = queue_family_indices.graphics_family;
    VkResult result = vkCreateCommandPool(vulkan_device, &create_info, nullptr, &command_pool);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan command pool. "
                  << "Error: " << result << std::endl;
        return false;
    }

    std::cout << "Vulkan command pool created successfully." << std::endl;
    return true;
}

// -----------------------------------------------------------------------------
// Create Command Buffers
// -----------------------------------------------------------------------------

static bool CreateCommandBuffers() {
    command_buffers.resize(swapchain_images.size());
    VkCommandBufferAllocateInfo allocate_info{};
    allocate_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandPool = command_pool;
    allocate_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocate_info.commandBufferCount = static_cast<uint32_t>(command_buffers.size());
    VkResult result = vkAllocateCommandBuffers(vulkan_device, &allocate_info, command_buffers.data());

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to allocate Vulkan command buffers. "
                  << "Error: " << result << std::endl;
        return false;
    }

    std::cout << "Vulkan command buffers created: " << command_buffers.size() << std::endl;
    return true;
}

// -----------------------------------------------------------------------------
// Create Synchronization Object
// -----------------------------------------------------------------------------

static bool CreateSynchronizationObjects() {
    VkSemaphoreCreateInfo semaphore_info{};
    semaphore_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    VkFenceCreateInfo fence_info{};
    fence_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    // Start signaled so the first frame doesn't wait forever.
    fence_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;
    VkResult result = vkCreateSemaphore(vulkan_device, &semaphore_info, nullptr, &image_available_semaphore);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create image-available semaphore. "
                  << "Error: " << result << std::endl;
        return false;
    }

    result = vkCreateSemaphore(vulkan_device, &semaphore_info, nullptr, &render_finished_semaphore);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create render-finished semaphore. "
                  << "Error: " << result << std::endl;
        return false;
    }

    result = vkCreateFence(vulkan_device, &fence_info, nullptr, &in_flight_fence);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create in-flight fence. "
                  << "Error: " << result << std::endl;
        return false;
    }

    std::cout << "Vulkan synchronization objects created successfully." << std::endl;
    return true;
}

// -----------------------------------------------------------------------------
// Initialize Vulkan
// -----------------------------------------------------------------------------

bool InitializeVulkan(SDL_Window* window) {
    vulkan_window = window;
    // -------------------------------------------------------------------------
    // Get extensions required by SDL
    // -------------------------------------------------------------------------

    Uint32 extension_count = 0;
    const char* const* extensions = SDL_Vulkan_GetInstanceExtensions(&extension_count);

    if (extensions == nullptr) {
        std::cerr << "Failed to get SDL Vulkan extensions: " << SDL_GetError() << std::endl;
        return false;
    }

    // -------------------------------------------------------------------------
    // Application information
    // -------------------------------------------------------------------------

    VkApplicationInfo application_info{};
    application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pApplicationName = game_info.game_name.c_str();
    application_info.applicationVersion = VK_MAKE_VERSION(game_info.game_version[1], game_info.game_version[2], game_info.game_version[3]);
    application_info.pEngineName = game_info.game_name.c_str();
    application_info.engineVersion = VK_MAKE_VERSION(game_info.game_version[1], game_info.game_version[2], game_info.game_version[3]);
    application_info.apiVersion = VK_API_VERSION_1_3;

    // -------------------------------------------------------------------------
    // Create Vulkan instance
    // -------------------------------------------------------------------------

    VkInstanceCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo = &application_info;
    create_info.enabledExtensionCount = extension_count;
    create_info.ppEnabledExtensionNames = extensions;
    VkResult result = vkCreateInstance(&create_info, nullptr, &vulkan_instance);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance. "
                  << "Error: " << result << std::endl;
        return false;
    }

    std::cout << "Vulkan instance created successfully." << std::endl;

    // -------------------------------------------------------------------------
    // Create SDL Vulkan surface
    // -------------------------------------------------------------------------

    if (!SDL_Vulkan_CreateSurface(window, vulkan_instance, nullptr, &vulkan_surface)) {
        std::cerr << "Failed to create Vulkan surface: " << SDL_GetError() << std::endl;
        ShutdownVulkan();
        return false;
    }

    std::cout << "Vulkan surface created successfully." << std::endl;

    // -------------------------------------------------------------------------
    // Pick GPU
    // -------------------------------------------------------------------------

    if (!PickPhysicalDevice()) {
        ShutdownVulkan();
        return false;
    }

    // -------------------------------------------------------------------------
    // Logical device
    // -------------------------------------------------------------------------

    if (!CreateLogicalDevice()) {
        ShutdownVulkan();
        return false;
    }

    // -------------------------------------------------------------------------
    // Swapchain
    // -------------------------------------------------------------------------

    if (!CreateSwapchain(window)) {
    ShutdownVulkan();
    return false;
    }

    if (!CreateCommandPool()) {
        ShutdownVulkan();
        return false;
    }
    
    if (!CreateCommandBuffers()) {
        ShutdownVulkan();
        return false;
    }
    
    if (!CreateSynchronizationObjects()) {
        ShutdownVulkan();
        return false;
    }

return true;
}

// -----------------------------------------------------------------------------
// Shutdown Vulkan
// -----------------------------------------------------------------------------

void ShutdownVulkan() {
    if (vulkan_device != VK_NULL_HANDLE) {
        vkDeviceWaitIdle(vulkan_device);
        DestroyBackgroundTexture();
        if (in_flight_fence != VK_NULL_HANDLE) {
            vkDestroyFence(vulkan_device, in_flight_fence, nullptr);
            in_flight_fence = VK_NULL_HANDLE;
        }
        if (render_finished_semaphore != VK_NULL_HANDLE) {
            vkDestroySemaphore(vulkan_device, render_finished_semaphore, nullptr);
            render_finished_semaphore = VK_NULL_HANDLE;
        }
        if (image_available_semaphore != VK_NULL_HANDLE){
            vkDestroySemaphore(vulkan_device, image_available_semaphore, nullptr);
            image_available_semaphore = VK_NULL_HANDLE;
        }
        if (command_pool != VK_NULL_HANDLE) {
            vkDestroyCommandPool(vulkan_device, command_pool, nullptr);
            command_pool = VK_NULL_HANDLE;
        }
        
        command_buffers.clear();
        // Destroy image views first.
        for (VkImageView image_view : swapchain_image_views) {
            vkDestroyImageView(vulkan_device, image_view, nullptr);
        }
        
        swapchain_image_views.clear();
        swapchain_images.clear();
        // Then destroy the swapchain.

        if (swapchain != VK_NULL_HANDLE) {
            vkDestroySwapchainKHR(vulkan_device, swapchain, nullptr);
            swapchain = VK_NULL_HANDLE;
        }
        
        // Then destroy the logical device.
        vkDestroyDevice(vulkan_device, nullptr);
        vulkan_device = VK_NULL_HANDLE;
    }
    // Surface must be destroyed before the instance.
    
    if (vulkan_surface != VK_NULL_HANDLE) {
        vkDestroySurfaceKHR(vulkan_instance, vulkan_surface, nullptr);
        vulkan_surface = VK_NULL_HANDLE;
    }
    if (vulkan_instance != VK_NULL_HANDLE) {
        vkDestroyInstance(vulkan_instance, nullptr);
        vulkan_instance = VK_NULL_HANDLE;
    }

  vulkan_physical_device = VK_NULL_HANDLE;
  graphics_queue = VK_NULL_HANDLE;
  present_queue = VK_NULL_HANDLE;
}

void MarkVulkanSwapchainOutdated() {
    swapchain_outdated = true;
}

// -----------------------------------------------------------------------------
// Vulkan Begin Frame Handling
// -----------------------------------------------------------------------------

bool BeginVulkanFrame() {
    // Recreate the swapchain if the window size changed.
    if (swapchain_outdated) {
        if (!RecreateSwapchain()) {
            return false;
        }

        swapchain_outdated = false;
    }

    // Wait until the previous frame has finished.
    VkResult result = vkWaitForFences(vulkan_device, 1, &in_flight_fence, VK_TRUE, UINT64_MAX);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed waiting for Vulkan in-flight fence. "
                  << "Error: " << result << std::endl;
        return false;
    }

    // Ask Vulkan which swapchain image we should render into.
    result = vkAcquireNextImageKHR(vulkan_device, swapchain, UINT64_MAX, image_available_semaphore, VK_NULL_HANDLE, &current_swapchain_image);

    if (result == VK_ERROR_OUT_OF_DATE_KHR) {
        swapchain_outdated = true;
        return false;
    }

    if (result == VK_SUBOPTIMAL_KHR) {
        swapchain_outdated = true;
    }
    else if (result != VK_SUCCESS) {
        std::cerr << "Failed to acquire Vulkan swapchain image. "
                  << "Error: " << result << std::endl;
        return false;
    }

    // Reset the fence only after successfully acquiring an image.
    result = vkResetFences(vulkan_device, 1, &in_flight_fence);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to reset Vulkan in-flight fence. "
                  << "Error: " << result << std::endl;
        return false;
    }

    VkCommandBuffer command_buffer = command_buffers[current_swapchain_image];

    // Reset the command buffer.
    result = vkResetCommandBuffer(command_buffer, 0);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to reset Vulkan command buffer. "
                  << "Error: " << result << std::endl;
        return false;
    }

    // Begin recording commands.
    VkCommandBufferBeginInfo begin_info{};
    begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    result = vkBeginCommandBuffer(command_buffer, &begin_info);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to begin Vulkan command buffer. "
                  << "Error: " << result << std::endl;
        return false;
    }

    // -------------------------------------------------------------------------
    // Transition swapchain image:
    //
    // UNDEFINED → COLOR_ATTACHMENT_OPTIMAL
    // -------------------------------------------------------------------------

    VkImageMemoryBarrier2 image_barrier{};
    image_barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2;
    image_barrier.srcStageMask = VK_PIPELINE_STAGE_2_NONE;
    image_barrier.srcAccessMask = VK_ACCESS_2_NONE;
    image_barrier.dstStageMask = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT;
    image_barrier.dstAccessMask = VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT;
    image_barrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    image_barrier.newLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    image_barrier.image = swapchain_images[current_swapchain_image];
    image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    image_barrier.subresourceRange.baseMipLevel = 0;
    image_barrier.subresourceRange.levelCount = 1;
    image_barrier.subresourceRange.baseArrayLayer = 0;
    image_barrier.subresourceRange.layerCount = 1;
    VkDependencyInfo dependency_info{};
    dependency_info.sType = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
    dependency_info.imageMemoryBarrierCount = 1;
    dependency_info.pImageMemoryBarriers = &image_barrier;
    vkCmdPipelineBarrier2(command_buffer, &dependency_info);
    return true;
}


// -----------------------------------------------------------------------------
// Vulkan End Frame Handling
// -----------------------------------------------------------------------------

bool EndVulkanFrame() {
    VkCommandBuffer command_buffer = command_buffers[current_swapchain_image];

    // -------------------------------------------------------------------------
    // Transition:
    //
    // COLOR_ATTACHMENT_OPTIMAL → PRESENT_SRC_KHR
    // -------------------------------------------------------------------------

    VkImageMemoryBarrier2 image_barrier{};
    image_barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2;
    image_barrier.srcStageMask = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT;
    image_barrier.srcAccessMask = VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT;
    image_barrier.dstStageMask = VK_PIPELINE_STAGE_2_NONE;
    image_barrier.dstAccessMask = VK_ACCESS_2_NONE;
    image_barrier.oldLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    image_barrier.newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
    image_barrier.image = swapchain_images[current_swapchain_image];
    image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    image_barrier.subresourceRange.baseMipLevel = 0;
    image_barrier.subresourceRange.levelCount = 1;
    image_barrier.subresourceRange.baseArrayLayer = 0;
    image_barrier.subresourceRange.layerCount = 1;
    VkDependencyInfo dependency_info{};
    dependency_info.sType = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
    dependency_info.imageMemoryBarrierCount = 1;
    dependency_info.pImageMemoryBarriers = &image_barrier;
    vkCmdPipelineBarrier2(command_buffer, &dependency_info);

    // -------------------------------------------------------------------------
    // Finish command buffer
    // -------------------------------------------------------------------------

    VkResult result = vkEndCommandBuffer(command_buffer);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to end Vulkan command buffer. "
                  << "Error: " << result << std::endl;
        return false;
    }

    // -------------------------------------------------------------------------
    // Submit command buffer
    // -------------------------------------------------------------------------

    VkSemaphoreSubmitInfo wait_semaphore_info{};
    wait_semaphore_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
    wait_semaphore_info.semaphore = image_available_semaphore;
    wait_semaphore_info.stageMask = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT;
    VkSemaphoreSubmitInfo signal_semaphore_info{};
    signal_semaphore_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
    signal_semaphore_info.semaphore = render_finished_semaphore;
    signal_semaphore_info.stageMask = VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT;
    VkCommandBufferSubmitInfo command_buffer_info{};
    command_buffer_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO;
    command_buffer_info.commandBuffer = command_buffer;
    VkSubmitInfo2 submit_info{};
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO_2;
    submit_info.waitSemaphoreInfoCount = 1;
    submit_info.pWaitSemaphoreInfos = &wait_semaphore_info;
    submit_info.commandBufferInfoCount = 1;
    submit_info.pCommandBufferInfos = &command_buffer_info;
    submit_info.signalSemaphoreInfoCount = 1;
    submit_info.pSignalSemaphoreInfos = &signal_semaphore_info;

    result = vkQueueSubmit2(graphics_queue, 1, &submit_info, in_flight_fence);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to submit Vulkan command buffer. "
                  << "Error: " << result << std::endl;
        return false;
    }

    // -------------------------------------------------------------------------
    // Present
    // -------------------------------------------------------------------------

    VkPresentInfoKHR present_info{};
    present_info.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    present_info.waitSemaphoreCount = 1;
    present_info.pWaitSemaphores = &render_finished_semaphore;
    present_info.swapchainCount = 1;
    present_info.pSwapchains = &swapchain;
    present_info.pImageIndices = &current_swapchain_image;
    result = vkQueuePresentKHR(present_queue, &present_info);

    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR) {
        swapchain_outdated = true;
        return true;
    }

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to present Vulkan swapchain image. "
                  << "Error: " << result << std::endl;
        return false;
    }

    return true;
}

// -----------------------------------------------------------------------------
// Begin Vulkan Rendering
// -----------------------------------------------------------------------------

void BeginVulkanRendering() {
    VkCommandBuffer command_buffer = command_buffers[current_swapchain_image];
    VkRenderingAttachmentInfo color_attachment{};
    color_attachment.sType = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
    color_attachment.imageView = swapchain_image_views[current_swapchain_image];
    color_attachment.imageLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    color_attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    color_attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    VkClearValue clear_value{};
    clear_value.color.float32[0] = 0.02f;
    clear_value.color.float32[1] = 0.02f;
    clear_value.color.float32[2] = 0.02f;
    clear_value.color.float32[3] = 1.0f;
    color_attachment.clearValue = clear_value;
    VkRenderingInfo rendering_info{};
    rendering_info.sType = VK_STRUCTURE_TYPE_RENDERING_INFO;
    rendering_info.renderArea.offset = {0, 0};
    rendering_info.renderArea.extent = swapchain_extent;
    rendering_info.layerCount = 1;
    rendering_info.colorAttachmentCount = 1;
    rendering_info.pColorAttachments = &color_attachment;
    vkCmdBeginRendering(command_buffer, &rendering_info);
}

// -----------------------------------------------------------------------------
// End Vulkan Rendering
// -----------------------------------------------------------------------------

void EndVulkanRendering() {
    VkCommandBuffer command_buffer = command_buffers[current_swapchain_image];
    vkCmdEndRendering(command_buffer);
}

// -----------------------------------------------------------------------------
// Getters
// -----------------------------------------------------------------------------

VkInstance GetVulkanInstance() {
    return vulkan_instance;
}

VkPhysicalDevice GetVulkanPhysicalDevice() {
    return vulkan_physical_device;
}

VkDevice GetVulkanDevice() {
    return vulkan_device;
}

VkQueue GetVulkanGraphicsQueue() {
    return graphics_queue;
}

VkQueue GetVulkanPresentQueue() {
    return present_queue;
}

VkSurfaceKHR GetVulkanSurface() {
    return vulkan_surface;
}

VkCommandPool GetVulkanCommandPool() {
    return command_pool;
}

VkCommandBuffer GetVulkanCommandBuffer(uint32_t index) {
    return command_buffers[index];
}

VkSemaphore GetVulkanImageAvailableSemaphore() {
    return image_available_semaphore;
}

VkSemaphore GetVulkanRenderFinishedSemaphore() {
    return render_finished_semaphore;
}

VkFence GetVulkanInFlightFence() {
    return in_flight_fence;
}

uint32_t GetVulkanSwapchainImageCount() {
    return static_cast<uint32_t>(swapchain_images.size());
}

VkFormat GetVulkanSwapchainImageFormat() {
    return swapchain_image_format;
}

VkExtent2D GetVulkanSwapchainExtent() {
    return swapchain_extent;
}

uint32_t GetVulkanGraphicsQueueFamily() {
    QueueFamilyIndices indices = FindQueueFamilies(vulkan_physical_device);
    return indices.graphics_family;
}

VkCommandBuffer GetCurrentVulkanCommandBuffer() {
    return command_buffers[current_swapchain_image];
}

bool LoadVulkanBackgroundTexture(const char* filename) {
    // If we're replacing an existing background, remove the old one first.
    if (background_texture != VK_NULL_HANDLE) {
        vkDeviceWaitIdle(vulkan_device);
        DestroyBackgroundTexture();
    }

    return CreateBackgroundTexture(filename);
}

void UnloadVulkanBackgroundTexture() {
    if (vulkan_device == VK_NULL_HANDLE) {
        return;
    }

    vkDeviceWaitIdle(vulkan_device);
    DestroyBackgroundTexture();
}

VkDescriptorSet GetVulkanBackgroundTexture() {
    return background_texture;
}