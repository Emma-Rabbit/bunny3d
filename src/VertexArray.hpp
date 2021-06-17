#pragma once
#include "GL/glew.h"
#include "VertexBuffer.hpp"

class VertexArray{
    GLuint m_vaoID;

    public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(VertexBuffer&);

    void Bind();
    void Unbind();
};