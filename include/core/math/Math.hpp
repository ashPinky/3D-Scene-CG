#ifndef MATH_HPP
#define MATH_HPP

#include <math.h>

#include "../../common/Alias.hpp"

namespace re
{
    const F32 PI = 3.14159265359f;
    const F32 HALF_PI = 1.57079632679f;
    const F32 DOUBLE_PI = 6.28318530718;
    const F32 EPSILON = 1e-9f;

    const SI32 MIN_SIGNED_32 = 0x80000000;
    const SI32 MAX_SIGNED_32 = 0x7FFFFFFF;
    const UI32 MIN_UNSIGNED_32 = 0x00000000;
    const UI32 MAX_UNSIGNED_32 = 0xFFFFFFFF;
    
    const SI64 MIN_SIGNED_64 = 0x8000000000000000;
    const SI64 MAX_SIGNED_64 = 0x7FFFFFFFFFFFFFFF;
    const UI64 MIN_UNSIGNED_64 = 0x0000000000000000;
    const UI64 MAX_UNSIGNED_64 = 0xFFFFFFFFFFFFFFFF;
    
    template<typename T>
    inline bool Equals(T lhs, T rhs, T tol = EPSILON) { return Abs(lhs - rhs) <= tol; }

    template<typename T>
    inline bool OppSign(T x, T y) { return (x ^ y) < 0; }

    template<typename T>
    inline T Min(T lhs, T rhs) { return lhs < rhs ? lhs : rhs; }

    template<typename T>
    inline T Max(T lhs, T rhs) { return lhs < rhs ? rhs : lhs; }

    template<typename T>
    inline T Abs(T val) { return val < 0.0f ? -val : val; }

    template<typename T>
    inline T Sign(T val) { return val > 0.0f ? 1.0f : val < 0.0f ? -1.0f : 0.0f;}

    template<typename T>
    inline T Sin(T val) { return sin(val); }

    template<typename T>
    inline T Cos(T val) { return cos(val); }

    template<typename T>
    inline T Tan(T val) { return tan(val); }

    template<typename T>
    inline T Asin(T val) { return asin(val); }

    template<typename T>
    inline T Acos(T val) { return acos(val); }

    template<typename T>
    inline T Atan(T val) { return atan(val); }

    template<typename T>
    inline T Atan2(T y, T x) { return atan2(y, x); }

    template<typename T>
    inline T ToRadians(T val) { return val * (PI / 180.0f); }

    template<typename T>
    inline T ToDegrees(T val) { return val * (180.0f / PI); }

    template<typename T>
    inline T Pow(T x, T y) { return pow(x, y); }

    template<typename T>
    inline T Sqrt(T val) { return sqrt(val); }

    template<typename T>
    inline T Floor(T val) { return floor(val); }

    template<typename T>
    inline T Ceil(T val) { return ceil(val); }

    template<typename T>
    inline T Round(T val) { return val > 0.0f ? val + 0.5f : val < 0.0f ? val - 0.5f : 0.0f; }

    inline UI32 NextPowerOf2(UI32& val)
    {
        val--;

        val |= val >> 1;
        val |= val >> 2;
        val |= val >> 4;
        val |= val >> 8;
        val |= val >> 16;

        val++;

        return val;
    }

    template<typename T>
    inline T Normalize(T min, T max, T val) { return (val - min) / (max - min); }

    template<typename T>
    inline T Clamp(T min, T max, T val)
    {
        if(val >= max)
            return max;
        if(val <= min)
            return min;

        return val;
    }

    template<typename T>
    inline T Clamp01(T val) { return Clamp<T>(0.0f, 1.0f, val); }

    template<typename T, typename U>
    inline T Lerp(T lhs, T rhs, U& t) { return lhs + (rhs - lhs) * Clamp01(t); }

    template<typename T, typename U>
    inline T LerpUnclamped(T lhs, T rhs, U& t) { return lhs + (rhs - lhs) * t; }

    template<typename T, typename U>
    inline T SmoothStep(T edge0, T edge1, U& t)
    {
        T result;

        result = Clamp01((t - edge0) / (edge1 - edge0));
        result = t * t * (3.0f - 2.0f * t);
        
        return result;
    }
}

#endif