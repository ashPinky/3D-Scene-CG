#include "input/KeyListener.hpp"
using namespace re;

const BYTE* KeyListener::GetKeyboardStates()
{
    return this->keyboard_states;
}

void KeyListener::OnEvent(Event* event)
{
    switch(event->GetEventType())
    {
        case EventType::KEY_PRESSED  : OnKeyPress((KeyPressedEvent*)event); break;
        case EventType::KEY_RELEASED : OnKeyRelease((KeyReleasedEvent*)event); break;
    }
}

void KeyListener::OnKeyPress(KeyPressedEvent* event)
{
    this->keyboard_states[event->GetKey()] = 1;
}
void KeyListener::OnKeyRelease(KeyReleasedEvent* event)
{
    this->keyboard_states[event->GetKey()] = 0;
}

void KeyListener::OnStart()
{
    this->keyboard_states = new BYTE[512];
    memset(this->keyboard_states, 0, 512);
}
void KeyListener::OnShutDown()
{
    delete[] this->keyboard_states;
}