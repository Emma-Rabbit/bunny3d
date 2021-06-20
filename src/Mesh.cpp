#include "Mesh.hpp"

Mesh::Mesh(glm::vec3 position, Material& mat) 
    : Geometry(position), m_Material{mat}
{
    
}
