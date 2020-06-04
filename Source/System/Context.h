#ifndef Context_h
#define Context_h

class Config;
class GLFWwindow;

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
