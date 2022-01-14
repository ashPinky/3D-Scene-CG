#ifndef EVENT_HPP
#define EVENT_HPP

#include "../common/Alias.hpp"

namespace re
{
    enum class EventType
    {
        NONE,

        KEY_ACTION,
        MOUSE_ACTION,
        
        KEY_PRESSED, 
        KEY_RELEASED,
        MOUSE_BUTTON_PRESSED, 
        MOUSE_BUTTON_RELEASED,

        MOUSE_MOVED, 
        MOUSE_SCROLLED,

        WINDOW_MOVED,
        WINDOW_CLOSED, 
        WINDOW_RESIZED, 
        WINDOW_FOCUSED, 
        WINDOW_LOST_FOCUSED 
    };

    class Event
    {
    public:
        virtual ~Event() = default;

    public:
        virtual PCSTR GetEventName() = 0;
        virtual EventType GetEventType() = 0;
    };

    #define EVENT_CLASS_TYPE(type)\
        PCSTR GetEventName() override {return #type;}\
        EventType GetEventType() override {return EventType::type;}
}

#endif