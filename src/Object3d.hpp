#include "glm/glm.hpp"

class Object3d{
    glm::vec3 m_Position;
    glm::mat4 m_ModelMatrix;

    public:
        Object3d(glm::vec3 positon);
};