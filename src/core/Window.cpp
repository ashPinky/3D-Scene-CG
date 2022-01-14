#include "core/Window.hpp"

namespace re
{
    Window* Window::Create()
    {
        return new Window();
    }
    void Window::Destroy(Window* window)
    {
        if(window->m_window_handle)
            glfwDestroyWindow(window->m_window_handle);

        if(window->m_cursor_handle)
            glfwDestroyCursor(window->m_cursor_handle);

        delete window;
    }

    void Window::Init(const WindowProps& props)
    {
        m_props = props;

        if(glfwInit() != 1)
        {
            printf("Failed to intitialize glfw\n");
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        m_window_handle = glfwCreateWindow(
            m_props.width,
            m_props.height,
            m_props.title,
            nullptr,
            nullptr
        );

        CORE_ASSERT_LOG(m_window_handle != nullptr, "Failed to create GLFW Window\n")

        SetCursor(props.cursor);
        SetCursorState(props.cursor_state);
        SetDisplayState(props.display_state);

        glfwSwapInterval(1);

        m_running = true;
    }
    void Window::Quit()
    {
        m_running = false;
    }

    PCSTR Window::GetTitle()
    {
        return m_props.title;
    }
    UI32 Window::GetWidth()
    {
        return m_props.width;
    }
    UI32 Window::GetHeight()
    {
        return m_props.height;
    }
    WindowCursor Window::GetCursor()
    {
        return m_props.cursor;
    }
    WindowCursorState Window::GetCursorState()
    {
        return m_props.cursor_state;
    }
    WindowDisplayState Window::GetDisplayState()
    {
        return m_props.display_state;
    }

    WindowHandle Window::GetWindowHandle()
    {
        return m_window_handle;
    }
    CursorHandle Window::GetCursorHandle()
    {
        return m_cursor_handle;
    }

    void Window::SetTitle(PSTR title)
    {
        m_props.title = title;
        glfwSetWindowTitle(m_window_handle, title);
    }
    void Window::SetWidth(UI32 width)
    {
        m_props.width = width;
        glfwSetWindowSize(m_window_handle, width, m_props.height);
    }
    void Window::SetHeight(UI32 height)
    {
        m_props.height = height;
        glfwSetWindowSize(m_window_handle, m_props.width, height);
    }
    void Window::SetCursor(WindowCursor cursor)
    {
        m_props.cursor = cursor;

        switch(m_props.cursor)
        {
            case WindowCursor::ARROW     : {
                                            if(m_cursor_handle) 
                                                glfwDestroyCursor(m_cursor_handle); 
                                            
                                            m_cursor_handle = glfwCreateStandardCursor(GLFW_ARROW_CURSOR); 
                                            glfwSetCursor(m_window_handle, m_cursor_handle);
                                            
                                            break;
                                       }
            case WindowCursor::HAND      : {
                                            if(m_cursor_handle) 
                                                glfwDestroyCursor(m_cursor_handle); 
                                            
                                            m_cursor_handle = glfwCreateStandardCursor(GLFW_HAND_CURSOR); 
                                            glfwSetCursor(m_window_handle, m_cursor_handle);

                                            break;
                                       }
            case WindowCursor::IBEAM     : {
                                            if(m_cursor_handle) 
                                                glfwDestroyCursor(m_cursor_handle); 

                                            m_cursor_handle = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR); 
                                            glfwSetCursor(m_window_handle, m_cursor_handle);
                                            
                                            break;
                                       }
            case WindowCursor::HRESIZE   : {
                                            if(m_cursor_handle) 
                                                glfwDestroyCursor(m_cursor_handle); 

                                            m_cursor_handle = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR); 
                                            glfwSetCursor(m_window_handle, m_cursor_handle);
                                            
                                            break;
                                       }
            case WindowCursor::VRESIZE   : {
                                            if(m_cursor_handle) 
                                                glfwDestroyCursor(m_cursor_handle); 

                                            m_cursor_handle = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR); 
                                            glfwSetCursor(m_window_handle, m_cursor_handle);
                                            
                                            break;
                                       }
            case WindowCursor::CROSSHAIR : {
                                            if(m_cursor_handle) 
                                                glfwDestroyCursor(m_cursor_handle); 

                                            m_cursor_handle = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR); 
                                            glfwSetCursor(m_window_handle, m_cursor_handle);
                                            
                                            break;
                                       }
            case WindowCursor::CUSTOM    : {
                                            //TODO:
                                            // if(cursor_handle) 
                                            //     glfwDestroyCursor(m_cursor_handle);  
                                            // GLFWimage image;
                                            // image.width = this->custom_cursor_tex->width;
                                            // image.height = this->custom_cursor_tex->height;
                                            // image.pixels = this->custom_cursor_tex->pixels;
                                            // m_cursor_handle = glfwCreateCursor(&image, 0, 0);
                                       }
        }
    }
    void Window::SetCursorState(WindowCursorState cursor_state)
    {
        m_props.cursor_state = cursor_state;

        switch(m_props.cursor_state)
        {
            case WindowCursorState::NORMAL   : glfwSetInputMode(m_window_handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL); break;
            case WindowCursorState::HIDDEN   : glfwSetInputMode(m_window_handle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); break;
            case WindowCursorState::DISABLED : glfwSetInputMode(m_window_handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED); break; 
        }
    }
    void Window::SetDisplayState(WindowDisplayState display_state)
    {
        m_props.display_state = display_state;

        switch(m_props.display_state)
        {
            case WindowDisplayState::NOMRAL     : glfwShowWindow(m_window_handle); break;
            case WindowDisplayState::HIDDEN     : glfwHideWindow(m_window_handle); break;
            case WindowDisplayState::MAXMIZED   : glfwMaximizeWindow(m_window_handle); break;
            case WindowDisplayState::FULLSCREEN : {
                                                        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
                                                        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
                                                        glfwSetWindowMonitor(m_window_handle, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
                                                        break;
                                                  }
        }
    }

    bool Window::IsRunning()
    {
        return m_running;
    }
}