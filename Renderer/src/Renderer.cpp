#include "Renderer.hpp"

#include <utility>

namespace GraphicsEngine {

    bool CheckValidationLayerSupport() {
        uint32_t layersCount;
        vkEnumerateInstanceLayerProperties(&layersCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layersCount);
        vkEnumerateInstanceLayerProperties(&layersCount, availableLayers.data());

        for (const char* layerName : validationLayers) {
            bool layerFound = false;

            for (const auto &layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName)) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                return false;
            }
        }
        return true;
    }

    Renderer::Renderer(int32_t width, int32_t height, std::string title)
                       : m_Width(width), m_Height(height), m_Title(std::move(title)) {
        m_Window = nullptr;
    }

    void Renderer::Run() {
        InitWindow();
        InitVulkan();
        MainLoop();
        Cleanup();
    }

    void Renderer::InitWindow() {
        glfwInit();
        //Setting false to can't resize window and set no api for not using opengl
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        //Creating window
        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
    }

    void Renderer::MainLoop() {
        while(!glfwWindowShouldClose(m_Window)) {
            glfwPollEvents();
        }
    }

    void Renderer::Cleanup() {
        vkDestroyInstance(m_VulkanInstance, nullptr);

        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Renderer::InitVulkan() {
        if (!CheckValidationLayerSupport()) {
            throw std::runtime_error("Validation layers requested, but not available!");
        }
        CreateInstance();
    }

    void Renderer::CreateInstance() {
        VkApplicationInfo applicationInfo{};
        applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        applicationInfo.pApplicationName = m_Title.c_str();
        applicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        applicationInfo.pEngineName = "EngineX";
        applicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        applicationInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &applicationInfo;

        uint32_t  glfwExtensionsCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionsCount);

        createInfo.enabledExtensionCount = glfwExtensionsCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;

        if (vkCreateInstance(&createInfo, nullptr, &m_VulkanInstance) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create Vulkan Instance");
        }
    }

} // GraphicsEngine