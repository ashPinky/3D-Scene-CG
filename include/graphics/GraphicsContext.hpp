#ifndef GRAPHICS_CONTEXT_HPP
#define GRAPHICS_CONTEXT_HPP

#include <stdio.h>
#include <stdlib.h>

#include "glew/glew.h"

#include "../common/Alias.hpp"

#include "../core/Window.hpp"

namespace re
{
    class GraphicsContext
    {
    private:
        static WindowHandle m_handle;

    private:
        GraphicsContext() = delete;
       ~GraphicsContext() = delete;

    public:
        static void OnStart(Window* window);

    public:
        static UI32 GetMaxTextureSlots();

    public:
        static CBYTE* GetAPIVendor();
        static CBYTE* GetAPIVersion();
        static CBYTE* GetAPIRenderer();

    public:
        static void SwapBuffers();
    };
}

#endif