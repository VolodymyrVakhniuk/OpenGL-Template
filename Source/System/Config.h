#ifndef Config_h
#define Config_h

#include <string>

struct Config
{   
    int window_width = 2880;
    int window_height = 1800;

    int opengl_version_major = 4;
    int opengl_version_minor = 1;

    int fov = 90;

    bool is_full_screen = false;
    std::string window_title = "default title";
};

#endif /* Config_h */