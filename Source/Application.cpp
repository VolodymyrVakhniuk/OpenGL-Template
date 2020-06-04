#include "Application.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "System/Config.h"
#include "Shader/ShaderLoader.h"

#include <iostream>

Application::Application(const Config &config)
    : m_context(config)
{

}


void Application::apploop()
{   
    auto window = m_context.get_window();

    // background color
    GLfloat background_color[] = {0.0, 0.0, 0.0, 1.0};

    // Creating shader program
    char error_buffer[1024];
    GLuint vs = load_compile_shader("BasicShaders/Basic.vs", GL_VERTEX_SHADER);
    GLuint fs = load_compile_shader("BasicShaders/Basic.fs", GL_FRAGMENT_SHADER);

    GLuint m_render_program = glCreateProgram();
    glAttachShader(m_render_program, vs);
    glAttachShader(m_render_program, fs);

    glLinkProgram(m_render_program);

    glGetShaderInfoLog(vs, 1024, NULL, error_buffer);
    glGetProgramInfoLog(m_render_program, 1024, NULL, error_buffer);

    std::cout << error_buffer << std::endl;

    glDeleteShader(vs);
    glDeleteShader(fs);

    // Setup code for rendering simple triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(0);

    // rendering loop
    while(!glfwWindowShouldClose(window))
    {
        glClearBufferfv(GL_COLOR, 0, background_color);

        processWindowInput();

        // rendering
        glUseProgram(m_render_program);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //

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