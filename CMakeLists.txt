cmake_minimum_required(VERSION 3.16)
project(raycaster LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics REQUIRED)

add_executable(raycaster
    src/main.cpp
    src/map.cpp
    src/player.cpp
    src/raycaster.cpp
    src/renderer.cpp
    src/input.cpp
)

target_link_libraries(raycaster PRIVATE SFML::Graphics)
