set(CMAKE_CXX_STANDARD 17)

set(HEADERS src/main.hpp)
set(SOURCES src/main.cpp)

add_executable(Game ${HEADERS} ${SOURCES})
target_link_libraries (Game PUBLIC Renderer)
