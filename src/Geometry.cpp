#include "Geometry.hpp"
#include "Cube.hpp"

Geometry::Geometry(glm::vec3 positon) : Object3d(positon)
{
    m_Vericies = Cube::GetCubeOnPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    m_Indecies = Cube::GetIndeciesOfNthCube(0);
}