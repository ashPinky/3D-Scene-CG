#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "../common/Alias.hpp"
#include "../common/Assert.hpp"

#include "../graphics/GraphicsContext.hpp"
#include "../graphics/RendererCommand.hpp"

#include "Time.hpp"
#include "Window.hpp"
#include "ApplicationProps.hpp"

#include "../events/Event.hpp"
#include "../events/KeyEvent.hpp"
#include "../events/MouseEvent.hpp"
#include "../events/ApplicationEvent.hpp"
#include "../events/EventHandler.hpp"
#include "../events/EventDispatcher.hpp"

#include "../input/KeyListener.hpp"
#include "../input/MouseListener.hpp"
#include "../input/InputManager.hpp"

namespace re
{
    class Application : public EventHandler
    {
    protected:
        Window* m_window;
        ApplicationProps m_props;
        
    public:
        Application(const ApplicationProps& props);
        virtual ~Application() = default;

    public:
        void Run();

    public:
        virtual void OnWindowClose(WindowClosedEvent* event);
        virtual void OnWindowResize(WindowResizedEvent* event);

    public:
        virtual void OnStart() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnShutDown() = 0;
    };  
}

#endif