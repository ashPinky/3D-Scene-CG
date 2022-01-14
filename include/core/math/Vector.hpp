#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../../common/Alias.hpp"
#include "../../common/Assert.hpp"

namespace re
{
    template<const SIZE N, typename T>
    class Vec
    {
    public:
        T m_data[N] = {};
    
    public:
        Vec() = default;
        Vec(const T& val)
        {
            for(int i = 0; i < N; i++)
                m_data[i] = val;
        }
        Vec(const T*& initalizer_list, const SIZE size)
        {
            CORE_ASSERT_LOG(size >= N, "Initalizer list is smaller than vector dimensions")
            for(int i = 0; i < N; i++)
                m_data[i] = initalizer_list[i];
        }

    public:
        T& operator [](const SIZE index)
        {
            CORE_ASSERT_LOG(index >= 0 && index < N, "Index is out of bounds")
            return m_data[index];
        }
    };

    template<typename T>
    class Vec<2, T>
    {
    public:
        union
        {
            T m_data[2] = {};

            struct
            {
                T x, y;
            };

            struct
            {
                T u, v;
            }; 
        };

    public:
        Vec() = default;
        Vec(const T& val)
        {
            m_data[0] = val;
            m_data[1] = val;
        }
        Vec(const T& x, const T& y)
        {
            m_data[0] = x;
            m_data[1] = y;
        }

    public:
        static const Vec<2, T> UP;
        static const Vec<2, T> DOWN;
        static const Vec<2, T> RIGHT;
        static const Vec<2, T> LEFT;

    public:
        T& operator [](const SIZE index)
        {
            CORE_ASSERT_LOG(index >= 0 && index < 2, "Index is out of bounds")
            return m_data[index];
        }
    };

    template<typename T>
    class Vec<3, T>
    {   
    public:
        union
        {
            T m_data[3] = {};

            struct
            {
                T x, y, z;
            };

            struct
            {
                T r, g, b;
            };
        };
    
    public:
        Vec() = default;
        Vec(const T& val)
        {
            m_data[0] = val;
            m_data[1] = val;
            m_data[2] = val;
        }
        Vec(const T& x, const T& y, const T& z)
        {
            m_data[0] = x;
            m_data[1] = y;
            m_data[2] = z;
        }

    public:
        static const Vec<3, T> UP;
        static const Vec<3, T> DOWN;
        static const Vec<3, T> RIGHT;
        static const Vec<3, T> LEFT;
        static const Vec<3, T> FRONT;
        static const Vec<3, T> BACK;

    public:
        T& operator [](const SIZE index)
        {
            CORE_ASSERT_LOG(index >= 0 && index < 3, "Index is out of bounds")
            return m_data[index];
        }
    };

    template<typename T>
    class Vec<4, T>
    {
    public:
        union
        {
            T m_data[4] = {};

            struct
            {
                T x, y, z, w;
            };

            struct
            {
                T r, g, b, a;
            };
        };

    public:
        Vec() = default;
        Vec(const T& val)
        {
            m_data[0] = val;
            m_data[1] = val;
            m_data[2] = val;
            m_data[3] = val;
        }
        Vec(const T& x, const T& y, const T& z, const T& w)
        {
            m_data[0] = x;
            m_data[1] = y;
            m_data[2] = z;
            m_data[3] = w;
        }

    public:
        T& operator [](const SIZE index)
        {
            CORE_ASSERT_LOG(index >= 0 && index < 4, "Index is out of bounds")
            return m_data[index];
        }
    };

    template<typename T> const Vec<2, T> Vec<2, T>::UP(0.0f, 1.0f, 0.0f);
    template<typename T> const Vec<2, T> Vec<2, T>::DOWN(0.0f, -1.0f, 0.0f);
    template<typename T> const Vec<2, T> Vec<2, T>::RIGHT(1.0f, 0.0f, 0.0f);
    template<typename T> const Vec<2, T> Vec<2, T>::LEFT(-1.0f, 0.0f, 0.0f);

    template<typename T> const Vec<3, T> Vec<3, T>::UP(0.0f, 1.0f, 0.0f);
    template<typename T> const Vec<3, T> Vec<3, T>::DOWN(0.0f, -1.0f, 0.0f);
    template<typename T> const Vec<3, T> Vec<3, T>::RIGHT(1.0f, 0.0f, 0.0f);
    template<typename T> const Vec<3, T> Vec<3, T>::LEFT(-1.0f, 0.0f, 0.0f);
    template<typename T> const Vec<3, T> Vec<3, T>::FRONT(0.0f, 0.0f, 1.0f);
    template<typename T> const Vec<3, T> Vec<3, T>::BACK(0.0f, 0.0f, -1.0f);

    typedef Vec<2, SI32> IVec2;
    typedef Vec<3, SI32> IVec3;
    typedef Vec<4, SI32> IVec4;
    typedef Vec<2, F32> FVec2;
    typedef Vec<3, F32> FVec3;
    typedef Vec<4, F32> FVec4;
    typedef Vec<2, F64> DVec2;
    typedef Vec<3, F64> DVec3;
    typedef Vec<4, F64> DVec4;

    template<const SIZE N, typename T>
    inline Vec<N, T> operator +(Vec<N, T> lhs, T rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result[i] = lhs[i] + rhs;

        return result;
    }
    template<const SIZE N, typename T>
    inline Vec<N, T> operator +(T lhs, Vec<N, T> rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result[i] = lhs + rhs[i];

        return result;
    }
    template<const SIZE N, typename T>
    inline Vec<N, T> operator +(Vec<N, T> lhs, Vec<N, T> rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result[i] = lhs[i] + rhs[i];

        return result;
    }

    template<const SIZE N, typename T>
    inline Vec<N, T> operator -(Vec<N, T> v)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result[i] = -v[i];

        return result;
    }
    template<const SIZE N, typename T>
    inline Vec<N, T> operator -(Vec<N, T> lhs, T rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result[i] = lhs[i] - rhs;

        return result;
    }
    template<const SIZE N, typename T>
    inline Vec<N, T> operator -(T lhs, Vec<N, T> rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result[i] = lhs - rhs[i];

        return result;
    }
    template<const SIZE N, typename T>
    inline Vec<N, T> operator -(Vec<N, T> lhs, Vec<N, T> rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result[i] = lhs[i] - rhs[i];

        return result;
    }

    template<const SIZE N, typename T>
    inline Vec<N, T> operator *(Vec<N, T> lhs, T rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result[i] = lhs[i] * rhs;

        return result;
    }
    template<const SIZE N, typename T>
    inline Vec<N, T> operator *(T lhs, Vec<N, T> rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result = lhs * rhs[i];

        return result;
    }

    template<const SIZE N, typename T>
    inline Vec<N, T> operator /(Vec<N, T> lhs, T rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result = lhs[i] / rhs;

        return result;
    }
    template<const SIZE N, typename T>
    inline Vec<N, T> operator /(T lhs, Vec<N, T> rhs)
    {
        Vec<N, T> result;

        for(int i = 0; i < N; i++)
            result = lhs / rhs[i];

        return result;
    }
}

#endif