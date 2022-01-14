#include "graphics/platform/opengl/GLVertexArray.hpp"

namespace re
{
    const UI32 GLVertexArray::GenerateVertexArray()
    {
        UI32 id;
        GLCALL(glGenVertexArrays(1, &id))
        return id;
    }

    void GLVertexArray::RegisterVertexBuffer(const UI32 vao_id, const UI32 vbo_id, const VertexLayout& vertex_layout)
    {
        GLCALL(glBindVertexArray(vao_id))
        GLCALL(glBindBuffer(GL_ARRAY_BUFFER, vbo_id))

        auto layouts = vertex_layout.GetLayouts();

        int offset = 0;
        for(int index = 0; index < layouts.size(); index++)
        {
            Layout layout = layouts[index];

            GLCALL(glEnableVertexAttribArray(index))
            GLCALL(glVertexAttribPointer(index, layout.format, layout.type, layout.normalized, vertex_layout.GetStride(), (const void*)offset))
            offset += layout.format * Layout::GetSizeOfType(layout.type);
        }   

        GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0))
        GLCALL(glBindVertexArray(0))
    }
    void GLVertexArray::ActivateVertexArray(const UI32 id)
    {
        GLCALL(glBindVertexArray(id))
    }   
    void GLVertexArray::DeactivateVertexArray()
    {
        GLCALL(glBindVertexArray(0))
    }
    void GLVertexArray::ReleaseVertexArray(const UI32 id)
    {
        GLCALL(glDeleteVertexArrays(1, &id))
    }
}
