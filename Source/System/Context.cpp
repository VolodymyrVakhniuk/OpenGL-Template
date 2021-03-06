#include "Context.h"

#include "../glad/glad.h"
#include "GLFW/glfw3.h"

#include "Config.h"

#include <string>

namespace 
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}

Context::Context(const Config &config)
{
    if(glfwInit() == GL_FALSE)
        throw std::runtime_error("Error during glfw initialization\n");
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, config.opengl_version_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, config.opengl_version_minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    m_window = glfwCreateWindow(config.window_width, config.window_height, config.window_title.c_str(), nullptr, nullptr);
    if (m_window == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("Can not create a window\n");
    }
    
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
    //glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD\n");
    }
}


