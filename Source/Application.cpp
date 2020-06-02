#include "Application.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

Application::Application(const Config &config)
    : m_context(config)
{

}

void Application::apploop()
{   
    auto window = m_context.get_window();

    static const GLfloat background_color[] = {1.0, 0.5, 1.0, 1.0};

    while(!glfwWindowShouldClose(window))
    {
        glClearBufferfv(GL_COLOR, 0, background_color);

        processWindowInput();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::processWindowInput()
{
    auto window = m_context.get_window();
    
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}