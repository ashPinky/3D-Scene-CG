#include "events/EventDispatcher.hpp"
#include "events/EventHandler.hpp"
using namespace re;

std::vector<EventHandler*> EventDispatcher::handlers;

void EventDispatcher::DispatchEvent(Event* event)
{
    for(EventHandler* handler : handlers)
        handler->OnEvent(event);
}

void EventDispatcher::OnStart(Window* window)
{
    glfwSetWindowCloseCallback(window->GetWindowHandle(), RegisterEvent<WindowClosedEvent>);

    glfwSetWindowSizeCallback(window->GetWindowHandle(), RegisterEvent<WindowResizedEvent, SI32, SI32>);

    glfwSetKeyCallback(window->GetWindowHandle(), RegisterEvent<KeyEvent, SI32, SI32, SI32, SI32>);
    glfwSetMouseButtonCallback(window->GetWindowHandle(), RegisterEvent<MouseEvent, SI32, SI32, SI32>);

    glfwSetCursorPosCallback(window->GetWindowHandle(), RegisterEvent<MouseMovedEvent, double, double>);
    glfwSetScrollCallback(window->GetWindowHandle(), RegisterEvent<MouseScrolledEvent, double, double>);
}
void EventDispatcher::OnShutDown()
{
    handlers.clear();
}

void EventDispatcher::PollEvents()
{
    glfwPollEvents();
}

void EventDispatcher::AddHandler(EventHandler* handler)
{
    handlers.push_back(handler);
}
void EventDispatcher::RemoveHandler(EventHandler* handler)
{
    for(auto it = handlers.begin(); it < handlers.end(); it++)
        if(*it == handler)
            handlers.erase(it);
}