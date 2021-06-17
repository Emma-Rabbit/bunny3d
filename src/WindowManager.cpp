#include "WindowManager.hpp"

WindowManager::WindowManager(int wid, int hei, std::string name)
: width{wid}, height{hei}, windowName{name}
{
    initWindow();
}

WindowManager::~WindowManager(){
    glfwDestroyWindow(window);
    glfwTerminate();
}

void WindowManager::initWindow(){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

int WindowManager::shouldClose(){
    return glfwWindowShouldClose(window);
}

GLFWwindow* WindowManager::getWindowHandler(){
    return window;
}