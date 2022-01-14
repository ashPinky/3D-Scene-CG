#ifndef KEY_EVENT_HPP
#define KEY_EVENT_HPP

#include "../common/Alias.hpp"

#include "Event.hpp"

namespace re
{
    class KeyEvent : public Event
    {
    protected:
        SI32 key, scancode, mods;

    private:
        SI32 action;

    public:
        KeyEvent(SI32 key, SI32 scancode, SI32 action, SI32 mods)
            :key(key), scancode(scancode), action(action), mods(mods) {}
        virtual ~KeyEvent() = default;
        
    public:
        SI32 GetKey() const
        {
            return key;
        }
        SI32 GetScancode() const
        {
            return scancode;
        }
        SI32 GetMods() const
        {
            return mods;
        }
        SI32 GetAction() const
        {
            return action;
        }

    public:
        EVENT_CLASS_TYPE(KEY_ACTION)
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(SI32 key, SI32 scancode, SI32 mods)
            :KeyEvent(key, scancode, GLFW_PRESS, mods) {}

    public:
        EVENT_CLASS_TYPE(KEY_PRESSED)
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(SI32 key, SI32 scancode, SI32 mods)
            :KeyEvent(key, scancode, GLFW_RELEASE, mods) {}
    
    public:
        EVENT_CLASS_TYPE(KEY_RELEASED)
    };
}

#endif