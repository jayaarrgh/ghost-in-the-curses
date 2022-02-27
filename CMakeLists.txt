cmake_minimum_required(VERSION 3.5)

project(ghost-in-the-curses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${PROJECT_BINARY_DIR}/src")

target_link_libraries(${CMAKE_PROJECT_NAME} ncurses)
target_link_libraries(${CMAKE_PROJECT_NAME} espeak-ng)
