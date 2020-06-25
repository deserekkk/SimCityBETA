cmake_minimum_required(VERSION 3.16)
project(SimCityBETA)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimCityBETA main.cpp GameState.cpp GameState.h Game.cpp Game.h Gameplay.cpp Gameplay.h Tile.cpp Tile.h City.cpp City.h Map.cpp Map.h)

find_package(ImGui-SFML REQUIRED)
target_link_libraries(SimCityBETA PRIVATE ImGui-SFML::ImGui-SFML)
