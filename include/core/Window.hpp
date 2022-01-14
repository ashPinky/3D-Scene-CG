#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <stdio.h>
#include <stdlib.h>

#include "glfw/glfw3.h"

#include "../common/Alias.hpp"
#include "../common/Assert.hpp"

namespace re
{
    typedef GLFWwindow* WindowHandle;
    typedef GLFWcursor* CursorHandle;

    enum class WindowDisplayState
    {
        NOMRAL,
        HIDDEN,
        MAXMIZED,
        FULLSCREEN
    };

    enum class WindowCursor
    {
        HAND,
        ARROW,
        IBEAM,
        CUSTOM,
        HRESIZE,
        VRESIZE,
        CROSSHAIR,
    };

    enum class WindowCursorState
    {
        NORMAL,
        HIDDEN,
        DISABLED
    };
    
    struct  WindowProps
    {
        PCSTR title                      = "Solar System";
        UI32 width                       = 800;
        UI32 height                      = 600;
        WindowCursor cursor              = WindowCursor::ARROW;
        WindowCursorState cursor_state   = WindowCursorState::NORMAL;
        WindowDisplayState display_state = WindowDisplayState::NOMRAL;
    };

    class Window
    {
    private:
        bool m_running = false;

    private:
        WindowProps m_props;
        WindowHandle m_window_handle = nullptr;
        CursorHandle m_cursor_handle = nullptr;

    private:
        Window() = default;
       ~Window() = default; 

    public:
        static Window* Create();
        static void Destroy(Window* window);

    public:
        void Init(const WindowProps& props);
        void Quit();

    public:
        PCSTR GetTitle();
        UI32 GetWidth();
        UI32 GetHeight();
        WindowCursor GetCursor();
        WindowCursorState GetCursorState();
        WindowDisplayState GetDisplayState();

    public:
        WindowHandle GetWindowHandle();
        CursorHandle GetCursorHandle();
    
    public:
        void SetTitle(PSTR title);
        void SetWidth(UI32 width);
        void SetHeight(UI32 height);
        void SetCursor(WindowCursor cursor);
        void SetCursorState(WindowCursorState cursor_state);
        void SetDisplayState(WindowDisplayState display_state);
    
    public:
        bool IsRunning();
    };  
}

#endif