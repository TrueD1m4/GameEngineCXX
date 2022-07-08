#include "Renderer.hpp"

#include <utility>

namespace GraphicsEngine {

    Renderer::Renderer(int32_t width, int32_t height,
                       std::string title, AppType type)
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
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Renderer::InitVulkan() {

    }

} // GraphicsEngine