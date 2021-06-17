#include "InputManager.hpp"
#include "State.hpp"
#include <iostream>

bool InputManager::toggle_cursor = true;

void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    State& state = *State::GetInstance();
    Camera& camera = *state.GetCamera();

    for(int i = GLFW_KEY_A; i <= GLFW_KEY_Z; i++){
        if(key == i && action == GLFW_PRESS){
            state.PushInput((char)i);
        }
        if(key == i && action == GLFW_RELEASE){
            state.ReleseInput((char)i);
        }
    }

    if (key == GLFW_KEY_C && action == GLFW_PRESS)
        if(toggle_cursor){
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            glfwSetCursorPosCallback(window, nullptr);
            toggle_cursor = false;
        }
        else{
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetCursorPosCallback(window, mouse_callback);
            toggle_cursor = true;
        }
}

float InputManager::lastX = 400.0f;
float InputManager::lastY = 300.0f;
const float InputManager::sensitivity = 0.1f;
void InputManager::mouse_callback(GLFWwindow* window, double xpos, double ypos){
    State& state = *State::GetInstance();
    Camera& camera = *state.GetCamera();

    std::cout << "Mouse x: " << xpos << ", Mouse y: " << ypos << '\n';
    float Xoffset = xpos - lastX;
    float Yoffset = ypos - lastY;

    lastX = xpos;
    lastY = ypos;

    Xoffset *= sensitivity;
    Yoffset *= sensitivity;

    camera.CursorRotateVertically(Yoffset);
    camera.CursorRotateHorizontally(Xoffset);
}

void InputManager::Bind(WindowManager& wm){
    glfwSetKeyCallback(wm.getWindowHandler(), key_callback);
    glfwSetCursorPosCallback(wm.getWindowHandler(), mouse_callback);
    glfwSetInputMode(wm.getWindowHandler(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    std::cout << "Input bound\n";
}
