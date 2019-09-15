cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SpaceGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR} src)

add_executable(SpaceGame src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/player.cpp src/entity.cpp src/bullet.cpp src/enemy.cpp src/audio.cpp src/graphics.cpp)
target_link_libraries(SpaceGame ${SDL2_LIBRARIES} -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

#Create a symbolic link for my resources folder
set (source "${CMAKE_SOURCE_DIR}/res")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/res")
add_custom_command(
 TARGET ${PROJECT_NAME} POST_BUILD
 COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
 DEPENDS ${destination}
 COMMENT "symbolic link resources folder from ${source} => ${destination}"
)