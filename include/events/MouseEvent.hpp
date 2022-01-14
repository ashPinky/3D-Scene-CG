#ifndef MOUSE_EVENT_HPP
#define MOUSE_EVENT_HPP

#include "../common/Alias.hpp"

#include "Event.hpp"

namespace re
{
    class MouseEvent : public Event
    {
    protected:
        SI32 button, mods;

    private:
        SI32 action;

    public:
        MouseEvent(SI32 button, SI32 action, SI32 mods)
            :button(button), action(action), mods(mods) {}
        virtual ~MouseEvent() = default;

    public:
        SI32 GetButton() const
        {
            return button;
        }
        SI32 GetAction() const
        {
            return action;
        }
        SI32 GetMods() const
        {
            return mods;
        }
        
    public:
        EVENT_CLASS_TYPE(MOUSE_ACTION)
    }; 

    class MousePressedEvent : public MouseEvent
    {
    public:
        MousePressedEvent(SI32 button, SI32 mods)
            :MouseEvent(button, GLFW_PRESS, mods) {}
        
    public:
        EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
    };

    class MouseReleasedEvent : public MouseEvent
    {
    public:
        MouseReleasedEvent(SI32 button, SI32 mods)
            :MouseEvent(button, GLFW_RELEASE, mods) {}
        
    public:
        EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
    };

    class MouseMovedEvent : public Event
    {
    private:
        SI32 x, y;

    public:
        MouseMovedEvent(SI32 x, SI32 y)
            :x(x), y(y) {}

    public:
        SI32 GetX() const
        {
            return x;
        }
        SI32 GetY() const
        {
            return y;
        }
    
    public:
        EVENT_CLASS_TYPE(MOUSE_MOVED)
    };

    class MouseScrolledEvent : public Event
    {
    private:
        SI32 x_offset, y_offset;

    public:
        MouseScrolledEvent(SI32 x_offset, SI32 y_offset)
            :x_offset(x_offset), y_offset(y_offset) {}

    public:
        SI32 GetXOffset() const
        {
            return x_offset;
        }
        SI32 GetYOffset() const
        {
            return y_offset;
        }
    
    public:
        EVENT_CLASS_TYPE(MOUSE_SCROLLED)
    };
}

#endif