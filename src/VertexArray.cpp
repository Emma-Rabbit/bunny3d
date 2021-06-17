#include "VertexArray.hpp"

VertexArray::VertexArray(){
    glGenVertexArrays(1, &m_vaoID);
}

VertexArray::~VertexArray(){

}

void VertexArray::Bind(){
    glBindVertexArray(m_vaoID);
}

void VertexArray::Unbind(){
    glBindVertexArray(0);
}

void VertexArray::AddBuffer(VertexBuffer& vb){
    Bind();
    vb.Bind();
    std::vector<VBLayout> layouts = vb.GetLayouts();
    unsigned int offset = 0;
    unsigned int stride = 0;
    for(VBLayout layout: layouts){
        stride += layout.count*sizeof(float);
    }
    int n = 0;
    for(VBLayout layout : layouts){
        glEnableVertexAttribArray(n);
        glVertexAttribPointer(n, layout.count, layout.type, layout.normalized, stride, (const void*)offset);
        n++;
        offset += layout.count * sizeof(float); //HARDCODED TO FLOAT!!!
    }
}