#include "ShaderProgram.hpp"
#include "Texture.hpp"

class Material{
    ShaderProgram& m_Shader;
    Texture* m_Texture;
    public:
        Material(ShaderProgram& sp, Texture* tx = nullptr);
        void AttachTexture(Texture& tx);
};