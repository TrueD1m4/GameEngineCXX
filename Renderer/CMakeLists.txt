set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CURRENT_SOURCE_DIR src)

set(HEADERS
        src/Renderer.hpp)

set(SOURCES
        src/Renderer.cpp)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

add_library(Renderer STATIC ${HEADERS} ${SOURCES})

target_link_libraries(Renderer PUBLIC glfw)
target_link_libraries(Renderer PUBLIC glm::glm)
target_link_libraries(Renderer PUBLIC Vulkan::Vulkan)

target_include_directories(Renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})