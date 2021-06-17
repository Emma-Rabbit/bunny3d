#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"

Texture::Texture(std::filesystem::path filepath)
: m_TextureID(0), 
m_Filepath(filepath), 
m_LocalBuffer(nullptr), 
m_Width(0), 
m_Height(0),
m_BPP(0)
{
    stbi_set_flip_vertically_on_load(1);
    m_LocalBuffer = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_BPP, 4);

    glGenTextures(1, &m_TextureID);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);

    glBindTexture(GL_TEXTURE_2D, 0);
    
    if(m_LocalBuffer)
        stbi_image_free(m_LocalBuffer);
}

Texture::~Texture(){
    glDeleteTextures(1, &m_TextureID);
}

void Texture::Bind(unsigned int slot){
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
}