#include "Renderer.hpp"

Renderer::Renderer(VertexArray& va, IndexBuffer& ib, ShaderProgram& shader)
: m_va{va}, m_ib{ib}, m_shader{shader}
{
    m_va.Bind();
    m_ib.Bind();
    m_shader.Bind();
}

void Renderer::Draw(){
    glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, 0);
    // glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Renderer::Clear(){
    glClearColor(0.58f, 0.99f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}