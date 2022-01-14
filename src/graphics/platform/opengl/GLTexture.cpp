#include "graphics/platform/opengl/GLTexture.hpp"

namespace re
{
    const UI32 GLTexture::GenerateTexture(PCSTR img_path, BYTE*& data, UI32* width, UI32* height, 
        WrapMode s_wrap, WrapMode t_wrap, FilterMode min_filter, FilterMode mag_filter)
    {
        SI32 pitch, format;
        UI32 id, _width, _height;

        data = stbi_load(img_path, (SI32*)width, (SI32*)height, &format, 0);

        _width = *width;
        _height = *height;

        pitch = _width * format;

        BYTE* top_pixels = data;
        BYTE* bottom_pixels = data + (_height - 1) * pitch;

        BYTE* temp_top_pixels = new BYTE[pitch];
        BYTE* temp_bottom_pixels = new BYTE[pitch];

        for(int y = 0; y < *(height) / 2; y++)
        {
            memcpy(temp_top_pixels, top_pixels, pitch);
            memcpy(temp_bottom_pixels, bottom_pixels, pitch);
            memcpy(top_pixels, temp_bottom_pixels, pitch);
            memcpy(bottom_pixels, temp_bottom_pixels, pitch);

            top_pixels += pitch;
            bottom_pixels -= pitch;
        }

        GLCALL(glGenTextures(1, &id))
        GLCALL(glBindTexture(GL_TEXTURE_2D, id))   

        GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (UI32)s_wrap))
        GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (UI32)t_wrap))
        GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (UI32)min_filter))
        GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (UI32)mag_filter))

        GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, format == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data))

        GLCALL(glBindTexture(GL_TEXTURE_2D, 0))

        delete[] temp_top_pixels;
        delete[] temp_bottom_pixels;

        return id;
    }
    const UI32 GLTexture::GenerateTexture(BYTE*& data, UI32 width, UI32 height,
        WrapMode s_wrap, WrapMode t_wrap, FilterMode min_filter, FilterMode mag_filter)
    {
        return 0;
    }

    void GLTexture::ActivateTexture(const UI32 id, UI32 slot)
    {
        GLCALL(glActiveTexture(GL_TEXTURE0 + slot))
        GLCALL(glBindTexture(GL_TEXTURE_2D, id))
    }
    void GLTexture::DeactivateTexture()
    {
        GLCALL(glBindTexture(GL_TEXTURE_2D, 0))
    }
    void GLTexture::ReleaseTexture(const UI32 id)
    {
        GLCALL(glDeleteTextures(1, &id))
    }
}