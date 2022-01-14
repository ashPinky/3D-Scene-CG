#ifndef GL_SHADER_HPP
#define GL_SHADER_HPP

#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>

#include <glew/glew.h>

#include "../../../common/Alias.hpp"

#include "../../../core/math/Vector.hpp"
#include "../../../core/math/Matrix.hpp"
#include "../../../core/math/Operations.hpp"

#include "GLDebug.hpp"

namespace re
{
    class GLShader
    {   
    private:
        GLShader() = delete;
       ~GLShader() = delete;

    private:
        static std::string INTERNAL_PARSE_SHADER(PCSTR filepath);
        static void INTERNAL_CREATE_SHADER(UI32 id, PCSTR filepath, int shader_type);

    public:
        static const UI32 GenerateShader(PCSTR vert_path, PCSTR frag_path);

    public:
        static void ActivateShader(const UI32 id);
        static void DeactivateShader();
        static void ReleaseShader(const UI32 id);
    
    public:
        static void SetInt(const UI32 id, PCSTR var_name, SI32 value);
        static void SetFloat(const UI32 id, PCSTR var_name, F32 value);
        static void SetVec2i(const UI32 id, PCSTR var_name, IVec2 v);
        static void SetVec2f(const UI32 id, PCSTR var_name, FVec2 v);
        static void SetVec3i(const UI32 id, PCSTR var_name, IVec3 v);
        static void SetVec3f(const UI32 id, PCSTR var_name, FVec3 v);
        static void SetVec4i(const UI32 id, PCSTR var_name, IVec4 v);
        static void SetVec4f(const UI32 id, PCSTR var_name, FVec4 v);
        static void SetMat4f(const UI32 id, PCSTR var_name, FMat4 m);
    };
}

#endif