#include "graphics/platform/opengl/GLShader.hpp"

namespace re
{
    std::string GLShader::INTERNAL_PARSE_SHADER(PCSTR filepath)
    {
        std::fstream file(filepath, std::ios::in);
    
        if(!file)
        {
            printf("Failed to open shader file.");
            return std::string();
        }
        
        std::string line;
        std::stringstream ss;
    
        while(getline(file, line))
            ss << line << '\n';
        
        return ss.str();
    }
    void GLShader::INTERNAL_CREATE_SHADER(UI32 id, PCSTR filepath, SI32 shader_type)
    {
        std::string source = INTERNAL_PARSE_SHADER(filepath);
        if(source.empty())
            return;

        PCSTR source_cstr = source.c_str();

        SI32 shader = GLCALL(glCreateShader(shader_type))
        GLCALL(glShaderSource(shader, 1, &source_cstr, nullptr))
        GLCALL(glCompileShader(shader))

        SI32 result;
        char buffer[512];
        GLCALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &result))

        if(result == 0)
        {
            GLCALL(glGetShaderInfoLog(shader, 512, nullptr, buffer))
            switch(shader_type)
            {
                case GL_VERTEX_SHADER: printf("Failed to compile Vertex Shader.\n%s", buffer); return;
                case GL_FRAGMENT_SHADER: printf("Failed to compile Fragment Shader.\n%s", buffer); return;
            }
        }

        GLCALL(glAttachShader(id, shader))
        GLCALL(glDeleteShader(shader))
    }

    const UI32 GLShader::GenerateShader(PCSTR vert_path, PCSTR frag_path)
    {
        UI32 id = GLCALL(glCreateProgram())

        CORE_ASSERT_LOG(id != 0, "Failed to create shader program")

        INTERNAL_CREATE_SHADER(id, vert_path, GL_VERTEX_SHADER);
        INTERNAL_CREATE_SHADER(id, frag_path, GL_FRAGMENT_SHADER);

        GLCALL(glLinkProgram(id))
        GLCALL(glValidateProgram(id))

        SI32 result;
        CHAR buffer[512];
        GLCALL(glGetProgramiv(id, GL_LINK_STATUS, &result))

        if(result == 0)
        {
            GLCALL(glGetProgramInfoLog(id, 512, nullptr, buffer))
            printf("Failed to link Shader\n%s", buffer);
            return 0;
        }

        return id;
    }

    void GLShader::ActivateShader(const UI32 id)
    {
        GLCALL(glUseProgram(id))
    }
    void GLShader::DeactivateShader()
    {
        GLCALL(glUseProgram(0))
    }
    void GLShader::ReleaseShader(const UI32 id)
    {
        GLCALL(glDeleteProgram(id))
    } 

    void GLShader::SetInt(const UI32 id, PCSTR var_name, SI32 value)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniform1i(uniformId, value))
    }
    void GLShader::SetFloat(const UI32 id, PCSTR var_name, F32 value)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniform1f(uniformId, value))
    }
    void GLShader::SetVec2i(const UI32 id, PCSTR var_name, IVec2 v)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniform2i(uniformId, v.x, v.y))
    }
    void GLShader::SetVec2f(const UI32 id, PCSTR var_name, FVec2 v)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniform2f(uniformId, v.x, v.y))
    }
    void GLShader::SetVec3i(const UI32 id, PCSTR var_name, IVec3 v)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniform3i(uniformId, v.x, v.y, v.z))
    }
    void GLShader::SetVec3f(const UI32 id, PCSTR var_name, FVec3 v)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniform3f(uniformId, v.x, v.y, v.z))
    }
    void GLShader::SetVec4i(const UI32 id, PCSTR var_name, IVec4 v)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniform4i(uniformId, v.x, v.y, v.z, v.w))
    }
    void GLShader::SetVec4f(const UI32 id, PCSTR var_name, FVec4 v)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniform4f(uniformId, v.x, v.y, v.z, v.w))
    }
    void GLShader::SetMat4f(const UI32 id, PCSTR var_name, FMat4 m)
    {
        SI32 uniformId = GLCALL(glGetUniformLocation(id, var_name))
        GLCALL(glUniformMatrix4fv(uniformId, 1, false, m.m_data))
    }
}
