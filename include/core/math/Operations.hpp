#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include "../../common/Alias.hpp"

#include "Math.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

namespace re
{
    template<const SIZE N, typename T>
    inline T Length(Vec<N, T> v)
    {
        T result = {};

        for(int i = 0; i < N; i++)
            result += v[i] * v[i];

        return Sqrt(result);
    }

    template<const SIZE N, typename T>
    inline T Distance(Vec<N, T> lhs, Vec<N, T> rhs)
    {
        return Length(lhs - rhs);
    }   

    template<const SIZE N, typename T>
    inline Vec<N, T> Normalize(Vec<N, T> v)
    {
        Vec<N, T> result;
        
        T len = Length(v);

        for(int i = 0; i < N; i++)
            result[i] = v[i] / len;

        return result; 
    }

    template<const SIZE N, typename T>
    inline T Dot(Vec<N, T> lhs, Vec<N, T> rhs)
    {
        T result = {};

        for(int i = 0; i < N; i++)
            result += lhs[i] * rhs[i];

        return result;
    }

    template<const SIZE N, typename T>
    inline T Angle(Vec<N, T> lhs, Vec<N, T> rhs)
    {
        return Acos(Dot(lhs, rhs) / (Length(lhs) * Length(rhs)));
    }

    template<const SIZE N, typename T, typename U>
    inline Vec<N, T> Lerp(Vec<N, T> start, Vec<N, T> end, U t)
    {
        return start + (end - start) * Clamp01(t);
    }

    template<const SIZE N, typename T, typename U>
    inline Vec<N, T> LerpUnclamped(Vec<N, T> start, Vec<N, T> end, U t)
    {
        start + (end - start) * t;
    }

    template<const SIZE N, typename T>
    inline Vec<N, T> Project(Vec<N, T> lhs, Vec<N, T> rhs)
    {
        return (Dot(lhs, rhs) / Dot(rhs, rhs)) * rhs;
    }

    template<const SIZE N, typename T>
    inline Vec<N, T> Reflect(Vec<N, T> v, Vec<N, T> normal)
    {
        return v - 2 * Project(v, normal);
    }

    template<typename T>
    inline Vec<2, T> Perpendicular(Vec<2, T> v)
    {
        Vec<2, T> result;

        result.x = -v.y;
        result.y = v.x;

        return result;
    }

    template<typename T>
    inline void ToPolar(Vec<2, T> v, T& rad, T& theta) 
    {
        rad = Length(v);
        theta = Atan2(v.y, v.x);
    }

    template<typename T>
    inline Vec<2, T> FromPolar(T rad, T theta)
    {
        Vec<2, T> result;
        
        result.x = rad * Cos(theta);
        result.y = rad * Sin(theta);

        return result;
    }

    template<typename T>
    inline T Cross(Vec<2, T> lhs, Vec<2, T> rhs)
    {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    template<typename T>
    inline Vec<3, T> Cross(Vec<3, T> lhs, Vec<3, T> rhs)
    {
        Vec<3, T> result;

        result.x = lhs.y * rhs.z - lhs.z * rhs.y;
        result.y = lhs.z * rhs.x - lhs.x * rhs.z;
        result.z = lhs.x * rhs.y - lhs.y * rhs.x;

        return result;
    }

    template<const SIZE N, const SIZE M, typename T>
    inline Mat<N, M, T> Transpose(Mat<N, M, T> m)
    {
        Mat<M, N, T> result;
        
        for(int row = 0; row < N; row++)
            for(int col = 0; col < M; col++)
                result(col, row) = m(row, col);

        return result;
    }

    template<const SIZE N, const SIZE M, typename T>
    inline Mat<N, M, T> Inverse(Mat<N, M, T> m)
    {   
        //TODO

        Mat<N, M, T> result;

        return result;
    }
}

#endif