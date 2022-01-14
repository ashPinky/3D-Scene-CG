#ifndef GL_TEXTURE_HPP
#define GL_TEXTURE_HPP

#include <string.h>

#include "glew/glew.h"
#include "stb_image/stb_image.h"

#include "../../../common/Alias.hpp"

#include "GLDebug.hpp"

namespace re
{
    enum class WrapMode
    {
        REPEAT               = 0x2901,
        CLAMP_TO_EDGE        = 0x812F,
        CLAMP_TO_BORDER      = 0x812D,
        MIRRORED_REPEAT      = 0x8370,
        MIRROR_CLAMP_TO_EDGE = 0x8743
    }; 

    enum class FilterMode
    {
        LINEAR  = 0x2601,
        NEAREST = 0x2600
    };

    enum class TextureType
    {

    };

    enum class FormatType
    {
        R8			   = 0x8229,
        R8_SNORM	   = 0x8F94,		
        R16			   = 0x822A,
        R16_SNORM	   = 0x8F98,
        RG8	           = 0x822B,
        RG8_SNORM	   = 0x8F95,	
        RG16	       = 0x822C,
        RG16_SNORM	   = 0x8F99,
        R3_G3_B2	   = 0x2A10,
        RGB4	       = 0x804F,
        RGB5	       = 0x8050,
        RGB8	       = 0x8051,
        RGB8_SNORM	   = 0x8F95,	
        RGB10		   = 0x8052,
        RGB12		   = 0x8053,
        RGB16_SNORM	   = 0x8F9A,	
        RGBA2	       = 0x8055,
        RGBA4	       = 0x8056,
        RGB5_A1	       = 0x8057,
        RGBA8	       = 0x8058,
        RGBA8_SNORM	   = 0x8F97,
        RGB10_A2	   = 0x8059,	
        RGB10_A2UI	   = 0x906F,
        RGBA12	       = 0x805A,
        RGBA16	       = 0x805B,
        SRGB8	       = 0x8C41,
        SRGB8_ALPHA8   = 0x8C43,		
        R16F		   = 0x822D,	
        RG16F	       = 0x822F,
        RGB16F	       = 0x881B,
        RGBA16F	       = 0x881A,
        R32F		   = 0x822E,	
        RG32F	       = 0x8230,
        RGB32F	       = 0x8815,
        RGBA32F	       = 0x8814,
        R11F_G11F_B10F = 0x8C3A,		
        RGB9_E5	       = 0x8C3D,
        R8I			   = 0x8231,	
        R8UI		   = 0x8232,	 	
        R16I		   = 0x8233,	
        R16UI		   = 0x8234,		
        R32I		   = 0x8235,	
        R32UI		   = 0x8236,		
        RG8I		   = 0x8237,
        RG8UI          = 0x8238,
        RG16I          = 0x8239,
        RG16UI         = 0x823A,
        RG32I          = 0x823B,
        RG32UI         = 0x823C,
        RGB8I          = 0x8D8F,
        RGB8UI         = 0x8D7D,
        RGB16I         = 0x8D89,
        RGB16UI        = 0x8D77,
        RGB32I         = 0x8D83,
        RGB32UI        = 0x8D71,
        RGBA8I         = 0x8D8E,
        RGBA8UI        = 0x8D7C,
        RGBA32I        = 0x8D82,
        RGBA32UI       = 0x8D70
    };

    class GLTexture
    {
    public:
        static const UI32 GenerateTexture(PCSTR img_path, BYTE*& data, UI32* width, UI32* height, 
            WrapMode s_wrap, WrapMode t_wrap, FilterMode min_filter, FilterMode mag_filter);
        static const UI32 GenerateTexture(BYTE*& data, UI32 width, UI32 height,
            WrapMode s_wrap, WrapMode t_wrap, FilterMode min_filter, FilterMode mag_filter);

    public:
        static void ActivateTexture(const UI32 id, UI32 slot = 0);
        static void DeactivateTexture();
        static void ReleaseTexture(const UI32 id);
    };
}

#endif