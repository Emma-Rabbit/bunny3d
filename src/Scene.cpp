#include "Scene.hpp"
#include <vector>

Scene::Scene(){

}

void Scene::AddObject(std::vector<float> ver, std::vector<unsigned int> ind){
    for(float v : ver){
        m_Verticies.push_back(v);
    }
    for(unsigned int i : ind){
        m_Indecies.push_back(i);
    }
}

void* Scene::GetVerticies(){
    return m_Verticies.data();
}

void* Scene::GetIndecies(){
    return m_Indecies.data();
}

unsigned int Scene::GetVerticiesSize(){
    return m_Verticies.size() * sizeof(float);
}

unsigned int Scene::GetIndeciesSize(){
    return m_Indecies.size() * sizeof(unsigned int);
}