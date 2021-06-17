#include <vector>

class Scene{
    std::vector<float> m_Verticies;
    std::vector<unsigned int> m_Indecies;

    public:
        Scene();
        void AddObject(std::vector<float>, std::vector<unsigned int>);
        void* GetVerticies();
        void* GetIndecies();
        unsigned int GetVerticiesSize();
        unsigned int GetIndeciesSize();
};