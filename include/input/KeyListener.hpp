#ifndef KEY_LISTENER_HPP
#define KEY_LISTENER_HPP

#include <string.h>

#include "../common/Alias.hpp"

#include "../core/Singleton.hpp"

#include "../events/EventHandler.hpp"

namespace re
{
    class KeyListener : public EventHandler, public Singleton<KeyListener>
    {
    private:
        BYTE* keyboard_states;

    private:
        KeyListener() = default;
       ~KeyListener() = default;
    
    public:
        const BYTE* GetKeyboardStates();

    private:
        void OnEvent(Event* event) override;

    private:
        void OnKeyPress(KeyPressedEvent* event);
        void OnKeyRelease(KeyReleasedEvent* event);

    public:
        void OnStart();
        void OnShutDown();

    friend Singleton<KeyListener>;
    };
}

#endif