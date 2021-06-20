#include "Geometry.hpp"
#include "Cube.hpp"

Geometry::Geometry(glm::vec3 positon) : Object3d(positon)
{
    InitCube();
    m_Indecies = Cube::GetIndeciesOfNthCube(0);
}

void Geometry::InitCube(){
    Vertex cube[8];

    cube[0].position = {0.0f, 0.0f, 0.0f};
    cube[1].position = {0.0f, 1.0f, 0.0f};
    cube[2].position = {1.0f, 1.0f, 0.0f};
    cube[3].position = {1.0f, 0.0f, 0.0f};
    cube[4].position = {0.0f, 0.0f, 1.0f};
    cube[5].position = {0.0f, 1.0f, 1.0f};
    cube[6].position = {1.0f, 1.0f, 1.0f};
    cube[7].position = {1.0f, 0.0f, 1.0f};

    for(Vertex vertex : cube){
        m_Vericies.push_back(vertex);
    }
}