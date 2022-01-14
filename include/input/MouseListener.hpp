#ifndef MOUSE_LISTENER_HPP
#define MOUSE_LISTENER_HPP

#include <string.h>

#include "../common/Alias.hpp"

#include "../core/Singleton.hpp"

#include "../events/EventHandler.hpp"

namespace re
{
    class MouseListener : public EventHandler, public Singleton<MouseListener>
    {
    private:
        BYTE* mouse_state;
    
    private:
        SI32* x;
        SI32* y;
        SI32* x_offset; 
        SI32* y_offset;

    private:
        MouseListener() = default;
       ~MouseListener() = default;

    public:
        const BYTE* GetMouseState(SI32*& x, SI32*& y, SI32*& x_offset, SI32*& y_offset);
    
    private:
        void OnEvent(Event* event) override;

    private:
        void OnMouseMove(MouseMovedEvent* event);
        void OnMousePress(MousePressedEvent* event);
        void OnMouseScroll(MouseScrolledEvent* event);
        void OnMouseRelease(MouseReleasedEvent* event);

    public:
        void OnStart();
        void OnShutDown();

    friend Singleton<MouseListener>;
    };
}

#endif