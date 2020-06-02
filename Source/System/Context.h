#ifndef Context_h
#define Context_h

#include "../glad/glad.h"
#include <GLFW/glfw3.h>

#include "Config.h"

class Context
{
public:
    Context(const Config &config);

    GLFWwindow* get_window() const
    {
        return m_window;
    }

private:
     GLFWwindow* m_window = nullptr;
};

#endif /* Context_h */
