#pragma once

#include <glm/glm.hpp>

class Camera{
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 m_CameraPos;
    glm::vec3 m_CameraTarget;
    glm::vec3 m_CameraFront;
    glm::vec3 m_CameraDirection;
    glm::vec3 m_CameraRight;
    glm::vec3 m_CameraUp;

    float m_Yaw;
    float m_Pitch;

    glm::mat4 m_ProjectionMatrix, m_ViewMatrix, m_ModelMatrix;

    float m_CameraSpeed;

    public:
        Camera();
        glm::mat4 Update();

        void SetModelMatrix();
        void SetViewMatrix();
        void UpdateDirection();
        void Input();

        void MoveRight();
        void MoveLeft();
        void MoveUp();
        void MoveDown();
        void MoveForward();
        void MoveBackward();
        void RotateLeft();
        void RotateRight();
        void RotateUpward();
        void RotateDownward();

        void CursorRotateHorizontally(float);
        void CursorRotateVertically(float);
};