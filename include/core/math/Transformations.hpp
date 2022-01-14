#ifndef TRANSFORMATIONS_HPP
#define TRANSFORMATIONS_HPP

#include "../../common/Alias.hpp"

#include "Math.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Operations.hpp"

namespace re
{
    template<typename T>
    Mat<4, 4, T> Translate(Vec<3, T> translation)
    {
        Mat<4, 4, T> result;

        result(0, 3) = translation.x;
        result(1, 3) = translation.y;
        result(2, 3) = translation.z;

        return result;
    }
    template<typename T>
    Mat<4, 4, T> Translate(Mat<4, 4, T>& result, Vec<3, T> translation)
    {
        result = Mat<4, 4, T>();

        result(0, 3) = translation.x;
        result(1, 3) = translation.y;
        result(2, 3) = translation.z;

        return result;
    }

    template<typename T>
    Mat<4, 4, T> Rotate(T angle, Vec<3, T> axis)
    {
        Mat<4, 4, T> result;

        const F32 c = Cos(angle);
        const F32 s = Sin(angle);

        if(axis.x)
        {
            result(1, 1) = c;
            result(1, 2) = s;
            result(2, 1) = -s;
            result(2, 2) = c;
        }
        else if(axis.y)
        {   
            result(0, 0) = c;
            result(0, 2) = -s;
            result(2, 0) = s;
            result(2, 2) = c;
        }
        else if(axis.z)
        {
            result(0, 0) = c;
            result(0, 1) = -s;
            result(1, 0) = s;
            result(1, 1) = s;
        }

        return result;
    }
    template<typename T>
    Mat<4, 4, T> Rotate(Mat<4, 4, T>& result, T angle, Vec<3, T> axis)
    {
        result = Mat<4, 4, T>();

        const F32 c = Cos(angle);
        const F32 s = Sin(angle);

        if(axis.x)
        {
            result(1, 1) = c;
            result(1, 2) = s;
            result(2, 1) = -s;
            result(2, 2) = c;
        }
        else if(axis.y)
        {   
            result(0, 0) = c;
            result(0, 2) = -s;
            result(2, 0) = s;
            result(2, 2) = c;
        }
        else if(axis.z)
        {
            result(0, 0) = c;
            result(0, 1) = -s;
            result(1, 0) = s;
            result(1, 1) = s;
        }

        return result;
    }

    template<typename T>
    Mat<4, 4, T> Scale(Vec<3, T> scale)
    {
        Mat<4, 4, T> result;

        for(int i = 0; i < 3; i++)
            result(i, i) = scale[i];

        return result;
    }
    template<typename T>
    Mat<4, 4, T> Scale(Mat<4, 4, T>& result, Vec<3, T> scale)
    {
        result = Mat<4, 4, T>();

        for(int i = 0; i < 3; i++)
            result(i, i) = scale[i];

        return result;
    }

    template<typename T>
    Mat<4, 4, T> LookAt(Vec<3, T> position, Vec<3, T> target, Vec<3, T> up)
    {
        Mat<4, 4, T> r, t;

        Vec<3, T> zaxis = Normalize(target - position);
        Vec<3, T> xaxis = Normalize(Cross(up, zaxis));
        Vec<3, T> yaxis = Cross(zaxis, xaxis);

        zaxis = -zaxis;

        r(0, 0) = xaxis.x;  r(0, 1) = yaxis.x;  r(0, 2) = zaxis.x;
        r(1, 0) = xaxis.y;  r(1, 1) = yaxis.y;  r(1, 2) = zaxis.y;
        r(2, 0) = xaxis.z;  r(2, 1) = yaxis.z;  r(2, 2) = zaxis.z;

        r = Transpose(r);

        t(0, 3) = -position.x;
        t(1, 3) = -position.y;
        t(2, 3) = -position.z;

        return r * t;
    }

    template<typename T>
    Mat<4, 4, T> Orthographic(T left, T right, T top, T bottom, T near, T far)
    {
        Mat<4, 4, T> result;

        const T tx = -(left + right) / (right - left);
        const T ty = -(bottom + top) / (top - bottom);
        const T tz = -(near + far) / (far - near);

        const T x_out = 2 / right - left;
        const T y_out = 2 / top - bottom;
        const T z_out = 2 / far - near;

        result(0, 0) = x_out; result(0, 3) = tx;
        result(1, 1) = y_out; result(1, 3) = ty;
        result(2, 2) = z_out; result(2, 3) = tz;

        return result;
    }

    template<typename T>
    Mat<4, 4, T> Perspective(T fov, T aspect, T near, T far)
    {   
        Mat<4, 4, T> result;

        const T half_fov = fov / 2.0f;

        result(0, 0) = 1 / (aspect * Tan(half_fov));
        result(1, 1) = 1 / Tan(half_fov);
        result(2, 2) = -(near - far) / (near - far);
        result(2, 3) = (2 * far * near) / (near - far);
        result(3, 2) = -1.0f;
        result(3, 3) = 0.0f;

        return result;
    }
}

#endif