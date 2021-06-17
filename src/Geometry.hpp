#include "Object3d.hpp"
#include <vector>

class Geometry: public Object3d{
    std::vector<float> m_Vericies;
    std::vector<unsigned int> m_Indecies;

    public:
        Geometry(glm::vec3 positon);
};