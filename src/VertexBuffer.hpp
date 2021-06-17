#pragma once
#include "GL/glew.h"
#include <vector>

struct VBLayout{
    unsigned int count;
    unsigned int type;
    unsigned int normalized;
    unsigned int stride;
};

class VertexBuffer{
    unsigned int m_BufferID;
    std::vector<VBLayout> layouts;
    bool bound = false;

    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void AddLayout(unsigned int, unsigned int, unsigned int);
        std::vector<VBLayout> GetLayouts();

        void Bind();
        void Unbind();
};