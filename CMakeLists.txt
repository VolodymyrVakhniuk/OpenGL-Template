cmake_minimum_required(VERSION 3.17.3)
project(opgl_t)

# Setting c++ version to c++ 11
set (CMAKE_CXX_STANDARD 11)

# Adding source files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/Source/*.c
    ${CMAKE_SOURCE_DIR}/Source/*.cpp)

# Adding header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/Source/*.h
	${CMAKE_SOURCE_DIR}/Source/*.hpp)
    
# Define the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})


# We need a CMAKE_DIR with some code to find external dependencies
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Adding glm
find_package(glm REQUIRED)

# Adding glfw3
find_package(glfw3 REQUIRED)

# Adding glad
set(GLAD_DIR "Source/glad")
add_library(glad "${GLAD_DIR}/glad.c")

# Define the include directories
target_include_directories(glad PRIVATE "Source/glad")
target_include_directories(${PROJECT_NAME} PUBLIC ${GLM_INCLUDE_DIRS} PRIVATE "${GLAD_DIR}")

message(STATUS "GLAD DIR = ${GLAD_DIR}")
message(STATUS "GLFW DIR = ${GLFW3_INCLUDE_DIR}")
message(STATUS "GLM DIR = ${GLM_INCLUDE_DIR}")

# Link libraries
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)