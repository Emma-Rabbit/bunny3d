#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(const void* data, unsigned int size){
    glGenBuffers(1, &m_BufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &m_BufferID);
}

void VertexBuffer::AddLayout(unsigned int count, unsigned int type, unsigned int normalized){
    VBLayout layout;
    layout.count = count;
    layout.type = type;
    layout.normalized = normalized;
    layout.stride = sizeof(float)*count;
    layouts.push_back(layout);
}

std::vector<VBLayout> VertexBuffer::GetLayouts(){
    return layouts;
}

void VertexBuffer::Bind(){
    glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
    bound = true;
}

void VertexBuffer::Unbind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    bound = false;
}