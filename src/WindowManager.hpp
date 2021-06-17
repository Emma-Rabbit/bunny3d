#pragma once

#include <string>
#include <GLFW/glfw3.h> 

class WindowManager{

    const int width;
    const int height;
    std::string windowName;

    GLFWwindow* window;

    void initWindow();

    public:
        WindowManager(int, int, std::string);
        ~WindowManager();
        int shouldClose();
        GLFWwindow* getWindowHandler();
        
};