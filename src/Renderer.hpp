#pragma once
#include "GL/glew.h"

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "ShaderProgram.hpp"

class Renderer{
    VertexArray& m_va;
    IndexBuffer& m_ib;
    ShaderProgram& m_shader;

    public:
        Renderer(VertexArray& va, IndexBuffer& ib, ShaderProgram& shader);
        void Clear();
        void Draw();
};