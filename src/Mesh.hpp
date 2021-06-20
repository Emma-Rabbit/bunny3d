#include "Geometry.hpp"
#include "Material.hpp"
#include "filesystem"

class Mesh : public Geometry{
    Material& m_Material;

    public:
        Mesh(glm::vec3 position, Material& mat);
        
};