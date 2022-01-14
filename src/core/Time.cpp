#include "core/Time.hpp"

namespace re
{
    Time::TimePoint Time::m_init_time;
    Time::TimePoint Time::m_current_time;
    Time::TimePoint Time::m_previous_time;

    F64 Time::m_time_scale;
    F64 Time::m_delta_time;
    F64 Time::m_elapsed_time;
    F64 Time::m_unscaled_elapsed_time;
    
    void Time::OnStart()
    {
        m_init_time = HighResClk::now();
        m_current_time = HighResClk::now();
        m_previous_time = HighResClk::now();

        m_time_scale = 1.0;
        m_delta_time = 0.0;
        m_elapsed_time = 0.0;
        m_unscaled_elapsed_time = 0.0;
    }
    void Time::OnUpdate()
    {
        m_delta_time = 0.0;

        if(m_time_scale > 0.0)
        {
            m_current_time = HighResClk::now();

            nanoseconds delta = m_current_time - m_previous_time;
            nanoseconds elapsed = m_current_time - m_init_time;

            m_delta_time = delta.count() * (1e-9) * m_time_scale;
            m_elapsed_time = elapsed.count() * (1e-9) * m_time_scale;
            m_unscaled_elapsed_time = elapsed.count() * (1e-9);
        }
    }
    void Time::OnFrameEnd()
    {
        m_previous_time = m_current_time;
    }

    F64 Time::GetTimeScale()
    {
        return m_time_scale;
    }
    F64 Time::GetDeltaTime()
    {
        return m_delta_time;
    }
    F64 Time::GetElapsedTime()
    {
        return m_elapsed_time;
    }
    F64 Time::GetUnscaledElapsedTime()
    {
        return m_unscaled_elapsed_time;
    }

    void Time::SetTimeScale(F64 scale)
    {
        m_time_scale = scale;
    }
}