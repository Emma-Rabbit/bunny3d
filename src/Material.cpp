#include "Material.hpp"

Material::Material(ShaderProgram& sp, Texture* tx = nullptr)
    : m_Shader{sp}
{
    m_Texture = tx;
}

void Material::AttachTexture(Texture& tx){
    m_Texture = &tx;
}