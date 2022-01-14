#include "graphics/VertexLayout.hpp"
using namespace re;

VertexLayout::VertexLayout()
{
    m_stride = 0;
}
VertexLayout::~VertexLayout()
{
    m_layouts.clear();
}

SIZE VertexLayout::GetStride() const
{
    return m_stride;
}
Layouts VertexLayout::GetLayouts() const
{
    return m_layouts;
}

