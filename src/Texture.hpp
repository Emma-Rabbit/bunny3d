#include <filesystem>
#include "GL/glew.h"

class Texture{
    unsigned int m_TextureID;
    std::filesystem::path m_Filepath;
    unsigned char* m_LocalBuffer;
    int m_Width, m_Height, m_BPP;

    public:
        Texture(std::filesystem::path);
        ~Texture();

        void Bind(unsigned int slot = 0);
};