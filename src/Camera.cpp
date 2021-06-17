#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "GLFW/glfw3.h"
#include <iostream>
#include "State.hpp"

Camera::Camera(){
    m_CameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    m_CameraTarget = glm::vec3(0.0f,0.0f,0.0f);

    m_Yaw = -90.0f;
    m_CameraSpeed = 0.1f;

    UpdateDirection();
    
    m_CameraRight = glm::normalize(glm::cross(up, m_CameraDirection));
    m_CameraUp = glm::cross(m_CameraDirection, m_CameraRight);

    // m_ProjectionMatrix = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
    m_ProjectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f);

    SetViewMatrix();
    SetModelMatrix();
}

glm::mat4 Camera::Update(){
    Input();
    UpdateDirection();
    SetViewMatrix();
    SetModelMatrix();
    return m_ProjectionMatrix * m_ViewMatrix * m_ModelMatrix;
}

void Camera::SetViewMatrix(){
    m_ViewMatrix = glm::lookAt(
                        m_CameraPos,
                        m_CameraPos + m_CameraFront,
                        up);
}

void Camera::SetModelMatrix(){
    m_ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,0.0f));
    m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(0.0f), glm::vec3(0.5f,2.0f,0.0f));
}

void Camera::UpdateDirection(){
    m_CameraDirection.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));  
    m_CameraDirection.y = sin(glm::radians(m_Pitch));
    m_CameraDirection.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

    m_CameraFront = glm::normalize(m_CameraDirection);
}

void Camera::Input(){
    State& state = *State::GetInstance();
    if      (state.CheckInput('I'))
        MoveUp();
     if (state.CheckInput('J'))
        MoveLeft();
     if (state.CheckInput('K'))
        MoveDown();
     if (state.CheckInput('L'))
        MoveRight();

     if (state.CheckInput('W'))
        MoveForward();
     if (state.CheckInput('S'))
        MoveBackward();
     if (state.CheckInput('A'))
        MoveLeft();
     if (state.CheckInput('D'))
        MoveRight();

     if (state.CheckInput('Q'))
        ;//RotateLeft();
     if (state.CheckInput('E'))
        ;//RotateRight();

     if (state.CheckInput('R'))
        //RotateUpward();
        MoveUp();
     if (state.CheckInput('F'))
        //RotateDownward();
        MoveDown();
}

void Camera::MoveRight(){
    m_CameraPos += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * m_CameraSpeed;
    std::cout << "x: " << m_CameraPos.x << ", y: " << m_CameraPos.y << ", z: " << m_CameraPos.z << '\n';
}

void Camera::MoveLeft(){
    m_CameraPos -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * m_CameraSpeed;
    std::cout << "x: " << m_CameraPos.x << ", y: " << m_CameraPos.y << ", z: " << m_CameraPos.z << '\n';
}

void Camera::MoveUp(){
    m_CameraPos -= m_CameraSpeed * glm::vec3(0.0f, -1.0f, 0.0f);
}

void Camera::MoveDown(){
    m_CameraPos += m_CameraSpeed * glm::vec3(0.0f, -1.0f, 0.0f);
}

void Camera::MoveForward(){
    m_CameraPos += m_CameraSpeed * m_CameraFront;
    std::cout << "x: " << m_CameraPos.x << ", y: " << m_CameraPos.y << ", z: " << m_CameraPos.z << '\n';
}

void Camera::MoveBackward(){
    m_CameraPos -= m_CameraSpeed * m_CameraFront;
    std::cout << "x: " << m_CameraPos.x << ", y: " << m_CameraPos.y << ", z: " << m_CameraPos.z << '\n';
}

void Camera::RotateLeft(){
    m_Yaw -= m_CameraSpeed;
}

void Camera::RotateRight(){
    m_Yaw += m_CameraSpeed;
}

void Camera::RotateUpward(){
    m_Pitch -= m_CameraSpeed;
}

void Camera::RotateDownward(){
    m_Pitch += m_CameraSpeed;
}

void Camera::CursorRotateHorizontally(float value){
    m_Yaw += value;
}

void Camera::CursorRotateVertically(float value){
    m_Pitch -= value;
}