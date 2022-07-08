#ifndef GAME_RENDERER_HPP
#define GAME_RENDERER_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <optional>
#include <set>

#include <cstdlib>
#include <cstdint>
#include <cstring>

namespace GraphicsEngine {

    [[maybe_unused]] const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    [[maybe_unused]] bool CheckValidationLayerSupport();

    class Renderer {
    public:
        Renderer(int32_t width, int32_t height, std::string title);
        void Run();

    private:
        void InitWindow();
        void InitVulkan();
        void MainLoop();
        void Cleanup();

    private:
        void CreateInstance();

        //Window settings
    private:
        int32_t m_Width, m_Height;
        std::string m_Title;
        GLFWwindow* m_Window;

        //Vulkan-operator fields
    private:
        VkInstance m_VulkanInstance{};

    };

} // GraphicsEngine

#endif //GAME_RENDERER_HPP
