#include "graphics/Texture.hpp"

namespace re
{
    Texture::Texture(UI32 width, UI32 height, 
        WrapMode s_wrap, WrapMode t_wrap, 
        FilterMode min_filter, FilterMode mag_filter)
    {
        m_width = width;
        m_height = height;

        m_s_wrap = s_wrap;
        m_t_wrap = t_wrap;
        m_min_filter = min_filter;
        m_mag_filter = mag_filter;

        m_native_ptr = GLTexture::GenerateTexture(m_raw_data, m_width, m_height, m_s_wrap, m_t_wrap, m_min_filter, m_mag_filter);
    }
    Texture::Texture(PCSTR filepath, 
        WrapMode s_wrap, WrapMode t_wrap, 
        FilterMode min_filter, FilterMode mag_filter)
    {
        m_s_wrap = s_wrap;
        m_t_wrap = t_wrap;
        m_min_filter = min_filter;
        m_mag_filter = mag_filter;

        m_native_ptr = GLTexture::GenerateTexture(filepath, m_raw_data, &m_width, &m_height, m_s_wrap, m_t_wrap, m_min_filter, m_mag_filter);
    }   
    Texture::~Texture()
    {
        GLTexture::ReleaseTexture(m_native_ptr);
    }

    bool Texture::operator ==(Texture rhs)
    {
        return m_native_ptr == rhs.m_native_ptr;
    }
    bool Texture::operator !=(Texture rhs)
    {
        return m_native_ptr != rhs.m_native_ptr;
    }

    UI32 Texture::GetNativePtr()
    {
        return m_native_ptr;
    }
    UI32 Texture::GetWidth()
    {
        return m_width;
    }
    UI32 Texture::GetHeight()
    {
        return m_height;
    }

    WrapMode Texture::GetSWrap()
    {   
        return m_s_wrap;
    }
    WrapMode Texture::GetTWrap()
    {
        return m_t_wrap;
    }
    FilterMode Texture::GetMinFilter()
    {
        return m_min_filter;
    }
    FilterMode Texture::GetMagFilter()
    {
        return m_mag_filter;
    }
    FormatType Texture::GetFormatType()
    {
        return m_format_type;
    }

    void Texture::SetWrapMode(WrapMode s_wrap, WrapMode t_wrap)
    {   
        m_s_wrap = s_wrap;
        m_t_wrap = t_wrap;

        GLTexture::ActivateTexture(m_native_ptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (UI32)m_s_wrap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (UI32)m_t_wrap);
        GLTexture::DeactivateTexture();
    }
    void Texture::SetFilterMode(FilterMode min_filter, FilterMode mag_filter)
    {
        m_min_filter = min_filter;
        m_mag_filter = mag_filter;

        GLTexture::ActivateTexture(m_native_ptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (UI32)m_min_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (UI32)m_mag_filter);
        GLTexture::DeactivateTexture();
    }

    PVOID Texture::GetPixel(UI32 x, UI32 y)
    {
        return nullptr;
    }
    PVOID Texture::GetPixelData(UI32 x_offset, UI32 y_offset, UI32 width, UI32 height)
    {
        return nullptr;
    }

    void Texture::SetPixel(UI32 x, UI32 y, PVOID data)
    {
        
    }
    void Texture::SetPixelData(UI32 x_offset, UI32 y_offset, UI32 width, UI32 height, PVOID data)
    {
       
    }
}