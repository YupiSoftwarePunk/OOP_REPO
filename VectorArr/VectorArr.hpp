#pragma once
#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"
#include "../Matrix/Matrix.hpp"
#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"
#include <initializer_list>
#include <algorithm>
#include <cstring>
#include <stdexcept>


template <typename T>

class Vector
{
public:
    // ������������

    // ����������� �� ���������
    Vector() : data_(nullptr), rows_(0), cols_(0) {}

    // ����������� � ��������� ��������
    Vector(size_t rows, size_t cols) : rows_(rows), cols_(cols)
    {
        allocate();
    }

    // ����������� �� initializer_list
    Vector(const std::initializer_list<std::initializer_list<T>>& initList)
    {
        rows_ = initList.size();
        if (rows_ > 0) {
            cols_ = initList.begin()->size();
        }
        else {
            cols_ = 0;
        }

        allocate();

        size_t i = 0;
        for (const auto& row : initList)
        {
            if (row.size() != cols_)
            {
                ::exit(-1);
            }

            std::copy(row.begin(), row.end(), data_[i]);
            i++;
        }
    }

    // ����������� �����������
    Vector(const Vector& other) : rows_(other.rows_), cols_(other.cols_)
    {
        allocate();
        for (size_t i = 0; i < rows_; ++i)
        {
            for (size_t j = 0; j < cols_; ++j)
            {
                data_[i][j] = other.data_[i][j];
            }
        }
    }

    // ����������� �����������
    Vector(Vector&& other) noexcept : data_(other.data_), rows_(other.rows_), cols_(other.cols_)
    {
        other.data_ = nullptr;
        other.rows_ = 0;
        other.cols_ = 0;
    }


    // ����������
    ~Vector()
    {
        deallocate();
    }


    // �������� ������������ ������������
    Vector& operator=(const Vector& other)
    {
        if (this != &other)
        {
            deallocate();
            rows_ = other.rows_;
            cols_ = other.cols_;
            allocate();

            for (size_t i = 0; i < rows_; ++i)
            {
                for (size_t j = 0; j < cols_; ++j)
                {
                    data_[i][j] = other.data_[i][j];
                }
            }
        }
        return *this;
    }

    // �������� ������������ ������������
    Vector& operator=(Vector&& other) noexcept
    {
        if (this != &other)
        {
            deallocate();
            data_ = other.data_;
            rows_ = other.rows_;
            cols_ = other.cols_;

            other.data_ = nullptr;
            other.rows_ = 0;
            other.cols_ = 0;
        }
        return *this;
    }



    // ������ � ���������

    // ������ � �������
    T* operator[](size_t row)
    {
        return data_[row];
    }

    const T* operator[](size_t row) const
    {
        return data_[row];
    }


    // ������ � ��������
    T& operator()(size_t row, size_t col)
    {
        return data_[row][col];
    }

    const T& operator()(size_t row, size_t col) const
    {
        return data_[row][col];
    }


    // ���������� ������ � ��������
    T& at(size_t row, size_t col)
    {
        return data_[row][col];
    }

    const T& at(size_t row, size_t col) const
    {
        return data_[row][col];
    }


    // ��������� ��������
    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
    size_t size() const { return rows_ * cols_; }



    // ��������� �������
    void resize(size_t new_rows, size_t new_cols)
    {
        if (new_rows == rows_ && new_cols == cols_)
            return;

        T** new_data = new T * [new_rows];
        for (size_t i = 0; i < new_rows; ++i)
        {
            new_data[i] = new T[new_cols];
            for (size_t j = 0; j < new_cols; ++j)
            {
                if (i < rows_ && j < cols_)
                    new_data[i][j] = data_[i][j];
                else
                    new_data[i][j] = T();
            }
        }

        deallocate();
        data_ = new_data;
        rows_ = new_rows;
        cols_ = new_cols;
    }


    // ���������� ���������
    void fill(const T& value)
    {
        for (size_t i = 0; i < rows_; ++i)
        {
            for (size_t j = 0; j < cols_; ++j)
            {
                data_[i][j] = value;
            }
        }
    }



    // ��������� �����/������

    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec)
    {
        for (size_t i = 0; i < vec.rows_; ++i)
        {
            os << "{ ";
            for (size_t j = 0; j < vec.cols_; ++j)
            {
                os << vec.data_[i][j];
                if (j < vec.cols_ - 1)
                    os << ", ";
            }
            os << " }";
            if (i < vec.rows_ - 1)
                os << "\n";
        }
        return os;
    }


    friend std::istream& operator>>(std::istream& is, Vector<T>& vec)
    {
        for (size_t i = 0; i < vec.rows_; ++i)
        {
            for (size_t j = 0; j < vec.cols_; ++j)
            {
                is >> vec.data_[i][j];
            }
        }
        return is;
    }


private:
    // ����
    T** data_ = nullptr;
    size_t rows_ = 0;
    size_t cols_ = 0;


    // ��������� ������
    void allocate()
    {
        data_ = new T * [rows_];

        for (size_t i = 0; i < rows_; ++i)
        {
            data_[i] = new T[cols_];
            for (size_t j = 0; j < cols_; ++j)
            {
                data_[i][j] = T();
            }
        }
    }


    // ������������ ������
    void deallocate()
    {
        if (data_)
        {
            for (size_t i = 0; i < rows_; ++i)
            {
                delete[] data_[i];
            }
            delete[] data_;
            data_ = nullptr;
        }
        rows_ = 0;
        cols_ = 0;
    }
};