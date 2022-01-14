#include "core/geometry/Mesh.hpp"

namespace re
{
    Mesh::Mesh()
    {
        vao_ptr = 0;
        vbo_ptr = 0;

        m_topology = RenderMode::TRIANGLES;
    }
    Mesh::Mesh(std::vector<FVec3> positions, std::vector<UI32> triangles)
    {
        vao_ptr = 0;
        vbo_ptr = 0;

        m_positions = positions;
        m_triangles = triangles;

        m_topology = RenderMode::TRIANGLES;
    }
    Mesh::Mesh(std::vector<FVec3> positions, std::vector<FVec3> normals, std::vector<UI32> triangles)
    {
        vao_ptr = 0;
        vbo_ptr = 0;

        m_positions = positions;
        m_normals = normals;
        m_triangles = triangles;

        m_topology = RenderMode::TRIANGLES;
    }
    Mesh::Mesh(std::vector<FVec3> positions, std::vector<FVec3> normals, std::vector<FVec2> uvs, std::vector<UI32> triangles)
    {
        vao_ptr = 0;
        vbo_ptr = 0;

        m_positions = positions;
        m_normals = normals;
        m_uvs = uvs;
        m_triangles = triangles;

        m_topology = RenderMode::TRIANGLES;
    }

    UI32 Mesh::GetVertexCount()
    {
        return m_triangles.size() / 3;
    }
    UI32 Mesh::GetVertexArrayPtr()
    {
        return vao_ptr;
    }

    std::vector<UI32> Mesh::GetTriangles()
    {
        return m_triangles;
    }
    std::vector<FVec3> Mesh::GetPositions()
    {
        return m_positions;
    }
    std::vector<FVec3> Mesh::GetNormals()
    {
        return m_normals;
    }
    std::vector<FVec2> Mesh::GetUVs()
    {
        return m_uvs;
    }

    void Mesh::SetTriangles(std::vector<UI32> triangles)
    {
        m_triangles = triangles;
    }
    void Mesh::SetPositions(std::vector<FVec3> positions)
    {
        m_positions = positions;
    }   
    void Mesh::SetNormals(std::vector<FVec3> normals)
    {
        m_normals = normals;
    }
    void Mesh::SetUVs(std::vector<FVec2> uvs)
    {
        m_uvs = uvs;
    }

    void Mesh::Clear()
    {
        GLBuffer::ReleaseBuffer(vbo_ptr);
        GLVertexArray::ReleaseVertexArray(vao_ptr);

        vbo_ptr = 0;
        vao_ptr = 0;

        m_triangles.clear();
        m_positions.clear();
        m_normals.clear();
        m_uvs.clear();
    }
    void Mesh::Finalize()
    {
        if(!m_positions.size())
        {
            printf("Mesh has no vertex positions\n");
            return;
        }

        SIZE vert_size = (sizeof(FVec3) * static_cast<bool>(m_positions.size())) 
                       + (sizeof(FVec3) * static_cast<bool>(m_normals.size())) 
                       + (sizeof(FVec2) * static_cast<bool>(m_uvs.size()));
    
        SIZE mesh_size = (m_triangles.size() / 3) * vert_size;
        
        if(!vbo_ptr)
            vbo_ptr = GLBuffer::GenerateBuffer(BufferType::VERTEX_BUFFER, nullptr, mesh_size, BufferUsage::DYNAMIC_DRAW);

        if(!vao_ptr)
        {
            VertexLayout layout;
            layout.RegisterLayout<F32>(3);

            if(m_uvs.size())
                layout.RegisterLayout<F32>(2);
            if(m_normals.size())
                layout.RegisterLayout<F32>(3);
           
            vao_ptr = GLVertexArray::GenerateVertexArray();
            GLVertexArray::RegisterVertexBuffer(vao_ptr, vbo_ptr, layout);
        }

        std::vector<F32> data;
        for(int i = 0; i < m_triangles.size(); i += 3)
        {
            FVec3 v_position = m_positions[m_triangles[i]];

            data.push_back(v_position.x);
            data.push_back(v_position.y);
            data.push_back(v_position.z);
            
            if(m_uvs.size())
            {
                FVec2 v_uv = m_uvs[m_triangles[i + 1]];

                data.push_back(v_uv.x);
                data.push_back(v_uv.y);
            }

            if(m_normals.size())
            {
                FVec3 v_normal = m_normals[m_triangles[i + 2]];
                
                data.push_back(v_normal.x);
                data.push_back(v_normal.y);
                data.push_back(v_normal.z);
            }
        }

        GLBuffer::UpdateBuffer(BufferType::VERTEX_BUFFER, vbo_ptr, 0, mesh_size, data.data());
    }
}