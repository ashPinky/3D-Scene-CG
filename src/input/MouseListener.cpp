#include "input/MouseListener.hpp"
using namespace re;

const BYTE* MouseListener::GetMouseState(SI32*& x, SI32*& y, SI32*& x_offset, SI32*& y_offset)
{
    x = this->x; 
    y = this->y;
    
    x_offset = this->x_offset; 
    y_offset = this->y_offset;

    return mouse_state;
}

void MouseListener::OnEvent(Event* event)
{
    switch(event->GetEventType())
    {
        case EventType::MOUSE_MOVED           : OnMouseMove((MouseMovedEvent*)event); break;
        case EventType::MOUSE_BUTTON_PRESSED  : OnMousePress((MousePressedEvent*)event); break;
        case EventType::MOUSE_SCROLLED        : OnMouseScroll((MouseScrolledEvent*)event); break;
        case EventType::MOUSE_BUTTON_RELEASED : OnMouseRelease((MouseReleasedEvent*)event); break;
    }
}

void MouseListener::OnMouseMove(MouseMovedEvent* event)
{
    *(this->x) = event->GetX();
    *(this->y) = event->GetY();
}
void MouseListener::OnMousePress(MousePressedEvent* event)
{
    this->mouse_state[event->GetButton()] = 1;
}
void MouseListener::OnMouseScroll(MouseScrolledEvent* event)
{
    *(this->x_offset) = event->GetXOffset();
    *(this->y_offset) = event->GetYOffset();
}
void MouseListener::OnMouseRelease(MouseReleasedEvent* event)
{
    this->mouse_state[event->GetButton()] = 0;
}

void MouseListener::OnStart()
{
    this->x = new SI32;
    this->y = new SI32;

    this->x_offset = new SI32;
    this->y_offset = new SI32;

    this->mouse_state = new BYTE[8];
    memset(this->mouse_state, 0, 8);
}
void MouseListener::OnShutDown()
{
    delete this->x;
    delete this->y;

    delete this->x_offset;
    delete this->y_offset;

    delete[] this->mouse_state;
}