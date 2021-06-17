#pragma once

#include "Camera.hpp"
#include <vector>

class State{
    static State* m_State;
    State();
    Camera m_Camera;
    std::vector<char> m_InputStack;
    public:
        static State* GetInstance();
        Camera* GetCamera();
        void PushInput(char);
        void ReleseInput(char);
        std::vector<char> GetInput();
        bool CheckInput(char);
};