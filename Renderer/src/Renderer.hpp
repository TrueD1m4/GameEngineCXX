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

    enum AppType {
        DEBUG,
        RELEASE
    };

    class Renderer {
    public:
        Renderer(int32_t width, int32_t height, std::string title, AppType type);
        void Run();

    private:
        void InitWindow();
        void InitVulkan();
        void MainLoop();
        void Cleanup();

    private:
        int32_t m_Width, m_Height;
        std::string m_Title;
        GLFWwindow* m_Window;
    };

} // GraphicsEngine

#endif //GAME_RENDERER_HPP
