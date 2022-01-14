#ifndef APPLICATION_EVENT_HPP
#define APPLICATION_EVENT_HPP

#include "../common/Alias.hpp"

#include "Event.hpp"

namespace re
{
    class WindowClosedEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(WINDOW_CLOSED)
    };

    class WindowMovedEvent : public Event
    {
    private:
        SI32 x, y;

    public:
        WindowMovedEvent(SI32 x, SI32 y)
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
        EVENT_CLASS_TYPE(WINDOW_MOVED)
    };

    class WindowResizedEvent : public Event
    {   
    private:
        SI32 width, height;

    public:
        WindowResizedEvent(SI32 width, SI32 height)
            : width(width), height(height) {}

    public:
        SI32 GetWidth() const 
        {
            return this->width; 
        }
        SI32 GetHeight() const
        {
            return this->height;
        }
    
    public:
        EVENT_CLASS_TYPE(WINDOW_RESIZED)
    };
}

#endif