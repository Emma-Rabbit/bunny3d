#include "Cube.hpp"
#include <vector>

const float Cube::m_Verticies[] = {
        //  position              texture coords
        0.0f, 0.0f, 0.0f,     1.0f, 0.0f, //0
        0.0f, 1.0f, 0.0f,     1.0f, 1.0f, //1
        1.0f, 1.0f, 0.0f,     0.0f, 1.0f, //2
        1.0f, 0.0f, 0.0f,     0.0f, 0.0f, //3
        0.0f, 0.0f, 1.0f,     0.0f, 0.0f, //4
        0.0f, 1.0f, 1.0f,     0.0f, 1.0f, //5
        1.0f, 1.0f, 1.0f,     1.0f, 1.0f, //6
        1.0f, 0.0f, 1.0f,     1.0f, 0.0f, //7
};

const unsigned int Cube::m_Indecies[] = {
        0, 1, 2,
        2, 0, 3, //back

        3, 2, 6,
        6, 7, 3, //right

        3, 7, 0,
        0, 4, 7, //bottom

        7, 6, 4,
        4, 5, 6, //front

        6, 2, 1,
        1, 6, 5, //top

        5, 1, 0,
        0, 5, 4, //left
    };

std::vector<float> Cube::GetCubeOnPosition(glm::vec3 position){
    static float verticies[8*5];
    std::vector<float> v;
    for(int i = 0; i < 8; i++){
        verticies[5*i] = m_Verticies[5*i] + position.x;
        verticies[5*i + 1] = m_Verticies[5*i + 1] + position.y;
        verticies[5*i + 2] = m_Verticies[5*i + 2] + position.z;
        verticies[5*i + 3] = m_Verticies[5*i + 3];
        verticies[5*i + 4] = m_Verticies[5*i + 4];
    }
    for(int i = 0; i < 40; i++){
        v.push_back(verticies[i]);
    }
    return v;
}

std::vector<unsigned int> Cube::GetIndeciesOfNthCube(unsigned int number){
    static unsigned int indecies[36];
    std::vector<unsigned int> ind;
    for(int i = 0; i < 36; i++){
        indecies[i] = m_Indecies[i] + 8*number;
        ind.push_back(indecies[i]);
    }
    return ind;
}