#pragma once

#include "../VectorArr/VectorArr.hpp"
#include <memory>
#include <cmath>

// Базовый интерфейс стратегии
template <typename T>

class IVectorOperationStrategy 
{
public:
    virtual ~IVectorOperationStrategy() = default;

    // Для операций с двумя векторами
    virtual Vector<T> execute(const Vector<T>& vec1, const Vector<T>& vec2) const = 0;

    // Для операций с одним вектором
    virtual T execute(const Vector<T>& vec) const = 0;
};



// Конкретная стратегия для скалярного произведения
template <typename T>

class ScalarProductStrategy : public IVectorOperationStrategy<T> 
{
public:
    Vector<T> execute(const Vector<T>& vec1, const Vector<T>& vec2) const override 
    {
        if (vec1.rows() != vec2.rows() || vec1.cols() != vec2.cols()) 
        {
            throw std::invalid_argument("Vectors must have the same dimensions for scalar product");
        }

        T result = T();
        for (size_t i = 0; i < vec1.rows(); ++i) 
        {
            for (size_t j = 0; j < vec1.cols(); ++j) 
            {
                result += vec1[i][j] * vec2[i][j];
            }
        }

        // результат как вектор 1x1
        Vector<T> res(1, 1);
        res[0][0] = result;
        return res;
    }

    T execute(const Vector<T>& vec) const override 
    {
        throw std::logic_error("Scalar product requires two vectors");
    }
};



// Конкретная стратегия для векторного произведения (для 3D векторов)
template <typename T>

class VectorProductStrategy : public IVectorOperationStrategy<T> 
{
public:
    Vector<T> execute(const Vector<T>& vec1, const Vector<T>& vec2) const override
    {
        if (vec1.rows() != 1 || vec2.rows() != 1 || vec1.cols() != 3 || vec2.cols() != 3)
        {
            throw std::invalid_argument("Vector product is only defined for 3D vectors");
        }

        Vector<T> result(1, 3);
        result[0][0] = vec1[0][1] * vec2[0][2] - vec1[0][2] * vec2[0][1];
        result[0][1] = vec1[0][2] * vec2[0][0] - vec1[0][0] * vec2[0][2];
        result[0][2] = vec1[0][0] * vec2[0][1] - vec1[0][1] * vec2[0][0];
        return result;
    }

    T execute(const Vector<T>& vec) const override 
    {
        throw std::logic_error("Vector product requires two vectors");
    }
};



// Конкретная стратегия для вычисления нормы вектора
template <typename T>

class VectorNormStrategy : public IVectorOperationStrategy<T> 
{
public:
    Vector<T> execute(const Vector<T>& vec1, const Vector<T>& vec2) const override 
    {
        throw std::logic_error("Norm is calculated for a single vector");
    }

    T execute(const Vector<T>& vec) const override 
    {
        T sum = T();

        for (size_t i = 0; i < vec.rows(); ++i) 
        {
            for (size_t j = 0; j < vec.cols(); ++j) 
            {
                sum += vec[i][j] * vec[i][j];
            }
        }
        return std::sqrt(sum);
    }
};



// Класс-обработчик векторов
template <typename T>

class VectorHandler 
{
public:
    explicit VectorHandler(std::unique_ptr<IVectorOperationStrategy<T>> strategy)
        : strategy_(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<IVectorOperationStrategy<T>> strategy) 
    {
        strategy_ = std::move(strategy);
    }

    // Обработка двух векторов
    Vector<T> process(const Vector<T>& vec1, const Vector<T>& vec2) const 
    {
        return strategy_->execute(vec1, vec2);
    }

    // Обработка одного вектора
    T process(const Vector<T>& vec) const 
    {
        return strategy_->execute(vec);
    }

private:
    std::unique_ptr<IVectorOperationStrategy<T>> strategy_;
};