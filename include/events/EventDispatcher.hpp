#ifndef EVENT_DISPATCHER_HPP
#define EVENT_DISPATCHER_HPP

#include <vector>
#include <utility>

#include "../common/Alias.hpp"

#include "../core/Window.hpp"

#include "ApplicationEvent.hpp"
#include "MouseEvent.hpp"
#include "KeyEvent.hpp"

namespace re
{
    class EventHandler;

    class EventDispatcher
    {
    private:
        static std::vector<EventHandler*> handlers;

    private:
        EventDispatcher() = delete;
       ~EventDispatcher() = delete;

    public:
        template<typename EVENT_TYPE, typename... EVENT_ARGS>
        static void RegisterEvent(WindowHandle handle, EVENT_ARGS... args)
        {
            EVENT_TYPE* event = new EVENT_TYPE(std::forward<EVENT_ARGS>(args)...);

            if(event->GetEventType() == EventType::KEY_ACTION)
            {
                KeyEvent* key_event = dynamic_cast<KeyEvent*>(event);

                switch (key_event->GetAction())
                {
                    case GLFW_PRESS : 
                    {
                        KeyPressedEvent* key_pressed_event = new KeyPressedEvent(
                            key_event->GetKey(),
                            key_event->GetScancode(),
                            key_event->GetMods()
                        );
                        DispatchEvent(key_pressed_event); 
                        break;
                    }
                    case GLFW_RELEASE : 
                    {
                        KeyReleasedEvent* key_released_event = new KeyReleasedEvent(
                            key_event->GetKey(),
                            key_event->GetScancode(),
                            key_event->GetMods()
                        );
                        DispatchEvent(key_released_event);
                        break;
                    }
                }
            }

            if(event->GetEventType() == EventType::MOUSE_ACTION)
            {   
                MouseEvent* mouse_event = dynamic_cast<MouseEvent*>(event);

                switch (mouse_event->GetAction())
                {
                    case GLFW_PRESS : 
                    {
                        MousePressedEvent* mouse_pressed_event = new MousePressedEvent(
                            mouse_event->GetButton(),
                            mouse_event->GetMods()
                        );
                        DispatchEvent(mouse_pressed_event); 
                        break;
                    }
                    case GLFW_RELEASE : 
                    {
                            MouseReleasedEvent* mouse_released_event = new MouseReleasedEvent(
                            mouse_event->GetButton(),
                            mouse_event->GetMods()
                        );
                        DispatchEvent(mouse_released_event); 
                        break;
                    }
                }
            }

            DispatchEvent(event);
        }
        static void DispatchEvent(Event* event);

    public:
        static void OnStart(Window* handle);
        static void OnShutDown();

    public:
        static void PollEvents();

    public:
        static void AddHandler(EventHandler* handler);
        static void RemoveHandler(EventHandler* handler);
    };
}

#endif