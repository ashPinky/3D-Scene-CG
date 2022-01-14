#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>

#include "../common/Alias.hpp"

namespace re
{
    class Time
    {
    public:
        typedef std::chrono::duration<UI64, std::ratio<1, 1>> seconds;
        typedef std::chrono::duration<UI64, std::ratio<1, 10000000>> microseconds;
        typedef std::chrono::duration<UI64, std::ratio<1, 1000000000>> nanoseconds;

        typedef std::chrono::high_resolution_clock HighResClk;
        typedef std::chrono::time_point<HighResClk, nanoseconds> TimePoint;
    
    private:
        static TimePoint m_init_time;
        static TimePoint m_current_time;
        static TimePoint m_previous_time;

    private:
        static F64 m_time_scale;
        static F64 m_delta_time;
        static F64 m_elapsed_time;
        static F64 m_unscaled_elapsed_time;

    private:
        Time() = delete;
       ~Time() = delete;

    public:
        static void OnStart();
        static void OnUpdate();
        static void OnFrameEnd();

    public:
        static F64 GetTimeScale();
        static F64 GetDeltaTime();
        static F64 GetElapsedTime();
        static F64 GetUnscaledElapsedTime();

    public:
        static void SetTimeScale(F64 scale);
    }; 
}

#endif