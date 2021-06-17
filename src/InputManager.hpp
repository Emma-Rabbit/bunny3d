#include "WindowManager.hpp"

class InputManager{

    static bool toggle_cursor;
    static float lastX, lastY;
    static const float sensitivity;
    
    public:
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
        static void Bind(WindowManager&);
};