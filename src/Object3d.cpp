#include "Object3d.hpp"

Object3d::Object3d(glm::vec3 position)
    : m_Position{position}
{
    m_ModelMatrix = glm::mat4(1.0f);
}