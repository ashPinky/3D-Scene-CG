#ifndef GL_BUFFER_HPP
#define GL_BUFFER_HPP

#include "glew/glew.h"

#include "../../../common/Alias.hpp"

#include "GLDebug.hpp"

namespace re
{
    enum class BufferType
    {
        INDEX_BUFFER   = 0x8893,
        VERTEX_BUFFER  = 0x8892,
        TEXTURE_BUFFER = 0x8C2A,
        UNIFORM_BUFFER = 0x8A11
    };

    enum class BufferUsage
    {
        STATIC_DRAW  = 0x88E4,
        STREAM_DRAW  = 0x88E0,
        DYNAMIC_DRAW = 0x88E8
    };

    class GLBuffer
    {
    private:
        GLBuffer() = delete;
       ~GLBuffer() = delete;
    
    public:
        static const UI32 GenerateBuffer(BufferType type, PVOID data, SIZE bytes, BufferUsage usage);

    public:
        static void UpdateBuffer(BufferType type, const UI32 id, SIZE offset_bytes, SIZE bytes, PCVOID data);
        static void ActivateBuffer(BufferType type, const UI32 id);
        static void DeactivateBuffer(BufferType type);
        static void ReleaseBuffer(const UI32 id);
    };
}

#endif