#ifndef MESH_LOADER_HPP
#define MESH_LOADER_HPP

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>

#include "../common/Alias.hpp"

#include "math/Vector.hpp"

#include "utilities/String.hpp"

namespace re
{
    class MeshLoader
    {
    private:
        MeshLoader() = delete;
       ~MeshLoader() = delete;

    public:
        static void LoadFile(std::string filepath, 
            std::vector<FVec3>& positions, 
            std::vector<FVec3>& normals, 
            std::vector<FVec2>& uvs, 
            std::vector<UI32>& triangles);        
    };
}

#endif