#include "core/Application.hpp"

namespace re
{
    Application::Application(const ApplicationProps& props)
    {
        m_window = Window::Create();
        m_props = props;
    }

    void Application::Run()
    {
        m_window->Init(m_props.window_props);

        Time::OnStart();

        KeyListener::GetInstanceRef().OnStart();
        MouseListener::GetInstanceRef().OnStart();

        InputManager::OnStart();
        EventDispatcher::OnStart(m_window);
        GraphicsContext::OnStart(m_window);
        RendererCommand::OnStart(m_window);

        OnStart();

        while(m_window->IsRunning())
        {
            Time::OnUpdate();
            
            EventDispatcher::PollEvents();

            RendererCommand::ClearBuffers(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            OnUpdate();

            GraphicsContext::SwapBuffers();

            InputManager::OnFrameEnd();

            Time::OnFrameEnd();
        }

        OnShutDown();

        EventDispatcher::OnShutDown();

        MouseListener::GetInstanceRef().OnShutDown();
        KeyListener::GetInstanceRef().OnShutDown();

        Window::Destroy(m_window);
    }

    void Application::OnWindowClose(WindowClosedEvent* event)
    {
        m_window->Quit();
    }
    void Application::OnWindowResize(WindowResizedEvent* event)
    {
        m_window->SetWidth(event->GetWidth());
        m_window->SetHeight(event->GetHeight());
    }
}
