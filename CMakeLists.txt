cmake_minimum_required(VERSION 3.17.3)
project(opgl_t)

# setting c++ version to c++ 11
set (CMAKE_CXX_STANDARD 11)

# adding source files
file(GLOB_RECURSE SOURCES "Source/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# adding GLFW3
find_package(glfw3)
target_link_libraries(${PROJECT_NAME} glfw)

# adding glad
add_library(glad "Source/glad/glad.c")
target_link_libraries(${PROJECT_NAME} glad)