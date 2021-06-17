#pragma once
#include "GL/glew.h"

class IndexBuffer{
    unsigned int m_BufferID;
    unsigned int m_Count;

    public:
        IndexBuffer(const void* data, unsigned int count);
        ~IndexBuffer();

        void Bind();
        void Unbind();
        unsigned int GetCount();
};