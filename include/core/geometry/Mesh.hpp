#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include "../../common/Alias.hpp"

#include "../math/Vector.hpp"

#include "../../graphics/platform/opengl/GLBuffer.hpp"
#include "../../graphics/platform/opengl/GLVertexArray.hpp"
#include "../../graphics/RendererCommand.hpp"

namespace re
{
    class Mesh
    {
    private:    
        UI32 vbo_ptr;
        UI32 vao_ptr;

    private:
        std::vector<UI32> m_triangles;
        std::vector<FVec3> m_positions;
        std::vector<FVec3> m_normals;
        std::vector<FVec2> m_uvs;

    public:
        RenderMode m_topology;

    public:
        Mesh();
        Mesh(std::vector<FVec3> positions, std::vector<UI32> triangles);
        Mesh(std::vector<FVec3> positions, std::vector<FVec3> normals, std::vector<UI32> triangles);
        Mesh(std::vector<FVec3> positions, std::vector<FVec3> normals, std::vector<FVec2> uvs, std::vector<UI32> triangles);

    public:
        UI32 GetVertexCount();
        UI32 GetVertexArrayPtr();

    public:
        std::vector<UI32> GetTriangles();
        std::vector<FVec3> GetPositions();
        std::vector<FVec3> GetNormals();
        std::vector<FVec2> GetUVs();

    public:
        void SetTriangles(std::vector<UI32> triangles);
        void SetPositions(std::vector<FVec3> positions);
        void SetNormals(std::vector<FVec3> normals);
        void SetUVs(std::vector<FVec2> uvs);

    public:
        void Clear();
        void Finalize();
    };
}

#endif