#include "main.hpp"

int main() {
    GraphicsEngine::Renderer ren = GraphicsEngine::Renderer(800, 600, "Bebra");
    try {
        ren.Run();
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}