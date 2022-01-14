#ifndef VERTEX_LAYOUT_HPP
#define VERTEX_LAYOUT_HPP

#include <vector>

#include "glew/glew.h"

#include "../common/Alias.hpp"

namespace re
{
    struct Layout
    {
        UI32 type;
        SI32 format;
        bool normalized;

        static SIZE GetSizeOfType(UI32 type)
        {
            switch(type)
            {
                case GL_FLOAT         : return sizeof(float);
                case GL_UNSIGNED_INT  : return sizeof(UI32);
                case GL_UNSIGNED_BYTE : return sizeof(BYTE);
            }
        }
    };
}

namespace re
{
    typedef std::vector<Layout> Layouts;
}

namespace re
{
    class VertexLayout
    {
    public:
        VertexLayout();
       ~VertexLayout();
    
    private:
        SIZE m_stride;
        Layouts m_layouts;
    
    public:
        SIZE GetStride() const;
        Layouts GetLayouts() const;

    public:
        template<typename T>
        void RegisterLayout(UI32 format, bool normalized = false)
        {
            if(std::is_same<T, float>::value)
            {
                Layout layout;
                layout.type = GL_FLOAT;
                layout.format = format;
                layout.normalized = normalized;

                m_stride += format * sizeof(float);

                m_layouts.push_back(layout);
            }
            else if(std::is_same<T, UI32>::value)
            {
                Layout layout;
                layout.type = GL_UNSIGNED_INT;
                layout.format = format;
                layout.normalized = normalized;

                m_stride += format * sizeof(UI32);

                m_layouts.push_back(layout);
            }
            else if(std::is_same<T, BYTE>::value)
            {
                Layout layout;
                layout.type = GL_UNSIGNED_BYTE;
                layout.format = format;
                layout.normalized = normalized;

                m_stride += format * sizeof(BYTE);

                m_layouts.push_back(layout);
            }
            else
            {
                printf("Failed to add buffer layout due to being an unsupported type\n");
                return;
            }
        }
    };
}

#endif