#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../../common/Alias.hpp"
#include "../../common/Assert.hpp"

namespace re
{
    template<const SIZE N, const SIZE M, typename T>
    class Mat
    {
    public:
        T m_data[N * M];

    public: 
        Mat()
        {
            for(int row = 0; row < N; row++)
                for(int col = 0; col < M; col++)
                    m_data[row * M + col] = (row == col) ? (T)1.0f : (T)0.0f;
        }
        Mat(const T& val)
        {
            for(int row = 0; row < N; row++)
                for(int col = 0; col < M; col++)
                    m_data[row * M + col] = (row == col) ? val : (T)0.0f;
        }
        Mat(const T*& initializer_list, const SIZE row_size, const SIZE col_size)
        {
            CORE_ASSERT_LOG(row_size >= N && col_size >= M, "Initializer_list is smaller than than matrix dimensions")
            
            for(int row = 0; row < N; row++)
                for(int col = 0; col < M; col++)
                    m_data[row * M + col] = initializer_list[row * M + col];
        }

    public:
        T& operator ()(const SIZE row, const SIZE col)
        {
            CORE_ASSERT_LOG((row >= 0 && row < N) && (col >= 0 && row < M), "Index is out of bounds")
            return m_data[row * M + col];
        }
    };

    typedef Mat<2, 2, F32> FMat2;
    typedef Mat<3, 3, F32> FMat3;
    typedef Mat<4, 4, F32> FMat4;
    typedef Mat<2, 2, F64> DMat2;
    typedef Mat<3, 3, F64> DMat3;
    typedef Mat<4, 4, F64> DMat4;

    template<const SIZE N, const SIZE M, typename T>
    Mat<N, M, T> operator +(Mat<N, M, T> lhs, Mat<N, M, T> rhs)
    {
        Mat<N, M, T> result;

        for(int row = 0; row < N; row++)
            for(int col = 0; col < M; col++)    
                result(row, col) = lhs(row, col) + rhs(row, col);

        return result;
    }

    template<const SIZE N, const SIZE M, typename T>
    Mat<N, M, T> operator -(Mat<N, M, T> lhs, Mat<N, M, T> rhs)
    {
        Mat<N, M, T> result;

        for(int row = 0; row < N; row++)
            for(int col = 0; col < M; col++)    
                result(row, col) = lhs(row, col) - rhs(row, col);

        return result;
    }

    template<const SIZE N, const SIZE M, const SIZE O, typename T>
    Mat<N, O, T> operator *(Mat<N, M, T> lhs, Mat<M, O, T> rhs)
    {       
        Mat<N, O, T> result;

        for(int r1 = 0; r1 < N; r1++)
            for(int rhs_col = 0; rhs_col < O; rhs_col++)
            {
                T value = {};
                for(int r2 = 0; r2 < M; r2++)
                    value += lhs(r1, r2) * rhs(r2, rhs_col);

                result(r1, rhs_col) = value;
            }

        return result;
    }
    template<const SIZE N, const SIZE M, typename T>
    Vec<N, T> operator *(Mat<N, M, T> lhs, Vec<M, T> rhs)
    {
        Vec<N, T> result;

        for(int row = 0; row < N; row++)
            for(int col = 0; col < M; col++)
                result[row] += lhs(row, col) * rhs[col];
        
        return result;
    }
}

#endif