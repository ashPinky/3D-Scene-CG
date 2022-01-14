#ifndef GL_VERTEX_ARRAY_HPP
#define GL_VERTEX_ARRAY_HPP

#include "glew/glew.h"

#include "../../../common/Alias.hpp"

#include "GLDebug.hpp"
#include "../../VertexLayout.hpp"

namespace re
{
    class GLVertexArray
    {
    public:
        GLVertexArray() = delete;
       ~GLVertexArray() = delete;

    public:
        static const UI32 GenerateVertexArray();

    public:
        static void RegisterVertexBuffer(const UI32 vao_id, UI32 vbo_id, const VertexLayout& vertex_layout);
        static void ActivateVertexArray(const UI32 id);
        static void DeactivateVertexArray();
        static void ReleaseVertexArray(const UI32 id);
    };
}

#endif