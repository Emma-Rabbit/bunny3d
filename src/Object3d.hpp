#include "glm/glm.hpp"

struct Vertex{
    glm::vec3 position;
    glm::vec3 textureCoord;
};

class Object3d{
    glm::vec3 m_Position;
    glm::mat4 m_ModelMatrix;

    public:
        Object3d(glm::vec3 positon);
};