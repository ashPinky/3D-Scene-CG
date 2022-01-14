#ifndef GL_DEBUG_HPP
#define GL_DEBUG_HPP

#include <glew/glew.h>

#include "../../../common/Alias.hpp"
#include "../../../common/Assert.hpp"

namespace re
{
    inline void GLClearError()
    {
        while(glGetError() != GL_NO_ERROR);
    }
    inline bool GLRegisterError()
    {
        GLenum errorCode;
        while((errorCode = glGetError()) != GL_NO_ERROR)
        {
            PCSTR error = nullptr;
            switch(errorCode)
            {
                case GL_INVALID_ENUM:                  error = "INVALID_ENUM\0"; break;
                case GL_INVALID_VALUE:                 error = "INVALID_VALUE\0"; break;
                case GL_INVALID_OPERATION:             error = "INVALID_OPERATION\0"; break;
                case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW\0"; break;
                case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW\0"; break;
                case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY\0"; break;
                case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION\0"; break;
            }

            printf("OpenGL Error: %s\n", error);
            GLClearError();
            return false;
        }

        GLClearError();
        return true;
    }

    #define GLCALL(EXPR)\
        EXPR;\
        CORE_ASSERT(GLRegisterError())
}

#endif