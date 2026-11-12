// Interface for Vulkan.cpp
#pragma once
// External libraries and headers
#include <SDL3/SDL.h> // SDL API
#include <vulkan/vulkan.h> // Vulkan API

bool InitializeVulkan(SDL_Window* window);
void DestroyImGuiTexture();
void ShutdownVulkan();

void MarkVulkanSwapchainOutdated();

VkInstance GetVulkanInstance();
VkPhysicalDevice GetVulkanPhysicalDevice();
VkDevice GetVulkanDevice();
VkQueue GetVulkanGraphicsQueue();
VkQueue GetVulkanPresentQueue();
VkSurfaceKHR GetVulkanSurface();

uint32_t GetVulkanGraphicsQueueFamily();

VkCommandPool GetVulkanCommandPool();
VkCommandBuffer GetVulkanCommandBuffer(uint32_t index);

VkSemaphore GetVulkanImageAvailableSemaphore();
VkSemaphore GetVulkanRenderFinishedSemaphore();
VkFence GetVulkanInFlightFence();

uint32_t GetVulkanSwapchainImageCount();
VkFormat GetVulkanSwapchainImageFormat();
VkExtent2D GetVulkanSwapchainExtent();

bool BeginVulkanFrame();
bool EndVulkanFrame();

void BeginVulkanRendering();
void EndVulkanRendering();

VkCommandBuffer GetCurrentVulkanCommandBuffer();

bool LoadVulkanBackgroundTexture(const char* filename);
void UnloadVulkanBackgroundTexture();
VkDescriptorSet GetVulkanBackgroundTexture();

