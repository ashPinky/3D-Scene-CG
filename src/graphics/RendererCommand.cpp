#include "graphics/RendererCommand.hpp"
using namespace re;

void RendererCommand::OnStart(Window* window)
{
    SetBlend(true);
    SetDepth(true);

    SetBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    SetClearColor(0.0f, 0.0f, 0.0f);

    SetViewport(0, 0, window->GetWidth(), window->GetHeight());
}

void RendererCommand::SetCull(bool value)
{
    value ? glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);
}
void RendererCommand::SetBlend(bool value)
{
    value ? glEnable(GL_BLEND) : glDisable(GL_BLEND);
}
void RendererCommand::SetDepth(bool value)
{
    value ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
}
void RendererCommand::SetCullFace(UI32 face)
{
    glCullFace(face);
}
void RendererCommand::SetBlendFunc(UI32 src, UI32 dst)
{
    glBlendFunc(src, dst);
}
void RendererCommand::SetClearColor(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f);
}
void RendererCommand::SetViewport(SI32 x, SI32 y, SI32 w, SI32 h)
{
    glViewport(x, y, w, h);
}

void RendererCommand::ClearBuffers(UI32 buffers)
{
    glClear(buffers);
}
void RendererCommand::DrawArrays(RenderMode mode, UI32 vao, UI32 vertex_count)
{
    GLVertexArray::ActivateVertexArray(vao);
    glDrawArrays((UI32)mode, 0, vertex_count);
    GLVertexArray::DeactivateVertexArray();
}
void RendererCommand::DrawElements(RenderMode mode, UI32 vao, UI32 ibo, UI32 index_count)
{
    GLVertexArray::ActivateVertexArray(vao);
    GLBuffer::ActivateBuffer(BufferType::INDEX_BUFFER, ibo);
    glDrawElements((UI32)mode, index_count, GL_UNSIGNED_INT, nullptr);
    GLBuffer::DeactivateBuffer(BufferType::INDEX_BUFFER);
    GLVertexArray::DeactivateVertexArray();
}