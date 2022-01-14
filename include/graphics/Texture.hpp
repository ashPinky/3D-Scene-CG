#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "../common/Alias.hpp"

#include "platform/opengl/GLTexture.hpp"

namespace re
{
    class Texture
    {
    private:
        BYTE* m_raw_data;

    private:
        UI32 m_native_ptr;
        UI32 m_width, m_height;

    private:
        WrapMode m_s_wrap;
        WrapMode m_t_wrap;
        FilterMode m_min_filter;
        FilterMode m_mag_filter;
        FormatType m_format_type;

    public:
        Texture(UI32 width, UI32 height, 
            WrapMode s_wrap = WrapMode::REPEAT, WrapMode t_wrap = WrapMode::REPEAT, 
            FilterMode min_filter = FilterMode::NEAREST, FilterMode mag_filter = FilterMode::NEAREST);
        Texture(PCSTR filepath, 
            WrapMode s_wrap = WrapMode::REPEAT, WrapMode t_wrap = WrapMode::REPEAT, 
            FilterMode min_filter = FilterMode::NEAREST, FilterMode mag_filter = FilterMode::NEAREST);
       ~Texture();

    public:
        bool operator ==(Texture rhs);
        bool operator !=(Texture rhs);

    public:
        UI32 GetNativePtr();
        UI32 GetWidth();
        UI32 GetHeight();

    public:
        WrapMode GetSWrap();
        WrapMode GetTWrap();
        FilterMode GetMinFilter();
        FilterMode GetMagFilter();
        FormatType GetFormatType();

    public:
        void SetWrapMode(WrapMode s_wrap, WrapMode t_wrap);
        void SetFilterMode(FilterMode min_filter, FilterMode mag_filter);

    public:
        PVOID GetPixel(UI32 x, UI32 y);
        PVOID GetPixelData(UI32 x_offset, UI32 y_offset, UI32 width, UI32 height);

    public:
        void SetPixel(UI32 x, UI32 y, PVOID data);
        void SetPixelData(UI32 x_offset, UI32 y_offset, UI32 width, UI32 height, PVOID data);
    };
}

#endif