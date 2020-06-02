cmake_minimum_required(VERSION 3.12)
project(opgl_t)

# setting c++ version to c++ 11
set (CMAKE_CXX_STANDARD 11)

# adding source files
file(GLOB_RECURSE SOURCES "Source/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# adding GLFW3
set(GLFW_DIR "/usr/local/Cellar/glfw/3.3/include")
include_directories(GLFW_DIR)
find_package(glfw3)
target_link_libraries(${PROJECT_NAME} glfw)

# adding glad
set(GLAD_DIR "Source/glad")
add_library(glad "${GLAD_DIR}/glad.c")
target_include_directories(glad PRIVATE "${GLAD_DIR}")
target_link_libraries(${PROJECT_NAME} glad "${CMAKE_DL_LIBS}")