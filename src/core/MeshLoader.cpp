#include "core/MeshLoader.hpp"

#define _CRT_SECURE_NO_WARNINGS

namespace re
{
    void MeshLoader::LoadFile(std::string filepath, 
            std::vector<FVec3>& positions, 
            std::vector<FVec3>& normals, 
            std::vector<FVec2>& uvs, 
            std::vector<UI32>& triangles)
    {
        std::string format = filepath.substr(filepath.size() - 4, 4);
        if(format.c_str() == ".obj")
        {
            printf("Failed to load file of format : %s\n", format.c_str());
            exit(EXIT_FAILURE);
        }

        FILE* filestream;
        fopen_s(&filestream, filepath.c_str(), "r");
        if(!filestream)
        {
            printf("Failed to open file\n");
            exit(EXIT_FAILURE);
        }

        while(!feof(filestream))
        {
            std::string curr_line = ReadLine(filestream);

            if(FirstToken(curr_line) == "v")
            {
                FVec3 v_position;

                std::vector<std::string> s_position = SplitString(curr_line, " ");

                v_position.x = std::stof(s_position[1]);
                v_position.y = std::stof(s_position[2]);
                v_position.z = std::stof(s_position[3]);

                positions.push_back(v_position);
            }
            if(FirstToken(curr_line) == "vn")
            {
                FVec3 v_normal;

                std::vector<std::string> s_normal = SplitString(curr_line, " ");

                v_normal.x = std::stof(s_normal[1]);
                v_normal.y = std::stof(s_normal[2]);
                v_normal.z = std::stof(s_normal[3]);

                normals.push_back(v_normal);
            }
            if(FirstToken(curr_line) == "vt")
            {
                FVec2 v_uv;

                std::vector<std::string> s_uv = SplitString(curr_line, " ");

                v_uv.x = std::stof(s_uv[1]);
                v_uv.y = std::stof(s_uv[2]);

                uvs.push_back(v_uv);
            }
            if(FirstToken(curr_line) == "f")
            {
                std::vector<std::string> s_triangles = SplitString(curr_line, " ");

                for(int i = 1; i < s_triangles.size(); i++)
                {
                    std::vector<std::string> s_triangle_vertices = SplitString(s_triangles[i], "/");

                    triangles.push_back(atoi(s_triangle_vertices[0].c_str()) - 1);
                    triangles.push_back(atoi(s_triangle_vertices[1].c_str()) - 1);
                    triangles.push_back(atoi(s_triangle_vertices[2].c_str()) - 1);
                }
            }
        }

        fclose(filestream);
    }
}