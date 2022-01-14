#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include "../common/Alias.hpp"

#include "Event.hpp"
#include "EventDispatcher.hpp"

namespace re
{
    class EventHandler
    {
    public:
        EventHandler() { EventDispatcher::AddHandler(this); }

    protected:
        virtual void OnEvent(Event* event) = 0;

    friend class EventDispatcher;
    };
}

#endif