#pragma once
#include "glm/glm.hpp"
#include <vector>

class Cube{
    const static float m_Verticies[8 * 5];
    const static unsigned int m_Indecies[36];

    public:
        static std::vector<float> GetCubeOnPosition(glm::vec3 position);
        static std::vector<unsigned int> GetIndeciesOfNthCube(unsigned int number);
};