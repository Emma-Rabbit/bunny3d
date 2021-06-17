#include "State.hpp"

State* State::m_State = 0;

State::State(){
}

State* State::GetInstance(){
    if(!m_State)
        m_State = new State();
    return m_State;
}

Camera* State::GetCamera(){
    return &m_Camera;
}

void State::PushInput(char value){
    m_InputStack.push_back(value);
}

void State::ReleseInput(char value){
    for(int i = 0; i < m_InputStack.size(); i++){
        if(m_InputStack[i] == value)
            m_InputStack.erase(m_InputStack.begin() + i);
    }
}

std::vector<char> State::GetInput(){
    return m_InputStack;
}

bool State::CheckInput(char value){
    for(char c : m_InputStack){
        if(c == value)
            return true;
    }
    return false;
}