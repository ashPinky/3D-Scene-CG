#include "graphics/GraphicsContext.hpp"
using namespace re;

WindowHandle GraphicsContext::m_handle;

void GraphicsContext::OnStart(Window* window)
{
    m_handle = window->GetWindowHandle();
    glfwMakeContextCurrent(m_handle);

    glewExperimental = true;
    if(glewInit() != 0)
    {
       printf("Failed to initialize glew\n");
       exit(EXIT_FAILURE);
    }
}

UI32 GraphicsContext::GetMaxTextureSlots()
{
    SI32 maxSlots;
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxSlots);
    return maxSlots;
}
const BYTE* GraphicsContext::GetAPIVendor()
{
    return glGetString(GL_VENDOR);
}
const BYTE* GraphicsContext::GetAPIVersion()
{
    return glGetString(GL_VERSION);
}
const BYTE* GraphicsContext::GetAPIRenderer()
{
    return glGetString(GL_RENDERER);
}

void GraphicsContext::SwapBuffers()
{
    glfwSwapBuffers(m_handle);
}