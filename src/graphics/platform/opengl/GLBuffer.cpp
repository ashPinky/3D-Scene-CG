#include "graphics/platform/opengl/GLBuffer.hpp"

namespace re
{
    const UI32 GLBuffer::GenerateBuffer(BufferType type, PVOID data, SIZE bytes, BufferUsage usage)
    {
        UI32 id;
        GLCALL(glGenBuffers(1, &id))
        GLCALL(glBindBuffer((UI32)type, id))
        GLCALL(glBufferData((UI32)type, bytes, data, (UI32)usage))
        GLCALL(glBindBuffer((UI32)type, 0))
    
        return id;
    }

    void GLBuffer::UpdateBuffer(BufferType type, const UI32 id, SIZE offset_bytes, SIZE bytes, PCVOID data)
    {
        GLCALL(glBindBuffer((UI32)type, id))
        GLCALL(glBufferSubData((UI32)type, offset_bytes, bytes, data))
        GLCALL(glBindBuffer((UI32)type, 0))
    }
    void GLBuffer::ActivateBuffer(BufferType type, const UI32 id)
    {
        GLCALL(glBindBuffer((UI32)type, id))
    }
    void GLBuffer::DeactivateBuffer(BufferType type)
    {   
        GLCALL(glBindBuffer((UI32)type, 0))
    }
    void GLBuffer::ReleaseBuffer(const UI32 id)
    {
        GLCALL(glDeleteBuffers(1, &id))
    }
}