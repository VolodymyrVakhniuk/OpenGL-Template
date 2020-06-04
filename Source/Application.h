#ifndef Application_h
#define Application_h

#include "System/Context.h"

class Config;

class Application
{
public:
    Application(const Config &config);

    void apploop();

private:
    void processWindowInput();

private:
    Context m_context;
};


#endif /* Application_h */