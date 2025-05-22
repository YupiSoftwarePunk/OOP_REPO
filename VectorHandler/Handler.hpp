#pragma once
#include "../VectorArr/VectorArr.hpp"
#include <memory>


// Базовый интерфейс стратегии
template <typename T>
class IVectorOperationStrategy 
{
public:
    virtual ~IVectorOperationStrategy() = default;

    virtual T execute(const Vector<T>& vec1, const Vector<T>& vec2) const = 0;

    virtual T execute(const Vector<T>& vec) const = 0;
};



// Конкретная стратегия для скалярного произведения
template <typename T>

class ScalarProductStrategy : public IVectorOperationStrategy<T> 
{
public:
    T execute(const Vector<T>& vec1, const Vector<T>& vec2) const override 
    {
        if (vec1.size_ != vec2.size_ || vec1.capacity_ != vec2.capacity_) 
        {
            throw std::invalid_argument("Vectors must have the same dimensions for scalar product");
        }

        T result = T();
        for (int i = 0; i < vec1.size_; ++i) 
        {
            for (int j = 0; j < vec1.capacity_; ++j) 
            {
                result += vec1[i][j] * vec2[i][j];
            }
        }
        return result;
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
    T execute(const Vector<T>& vec1, const Vector<T>& vec2) const override 
    {
        if (vec1.size_ != 1 || vec2.size_ != 1 || vec1.capacity_ != 3 || vec2.capacity_ != 3)
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
    T execute(const Vector<T>& vec1, const Vector<T>& vec2) const override 
    {
        throw std::logic_error("Norm is calculated for a single vector");
    }

    T execute(const Vector<T>& vec) const override 
    {
        T sum = T();
        for (int i = 0; i < vec.size_; ++i) 
        {
            for (int j = 0; j < vec.capacity_; ++j)
            {
                sum += vec[i][j] * vec[i][j];
            }
        }
        return sqrt(sum);
    }
};



// Класс-обработчик векторов, использующий паттерн Стратегия
template <typename T>

class VectorHandler
{
public:
    explicit VectorHandler(std::unique_ptr<IVectorOperationStrategy<T>> strategy)
        : strategy_(std::move(strategy)) 
    {
    }

    void setStrategy(std::unique_ptr<IVectorOperationStrategy<T>> strategy) 
    {
        strategy_ = std::move(strategy);
    }

    T process(const Vector<T>& vec1, const Vector<T>& vec2) const 
    {
        return strategy_->execute(vec1, vec2);
    }

    T process(const Vector<T>& vec) const 
    {
        return strategy_->execute(vec);
    }

private:
    std::unique_ptr<IVectorOperationStrategy<T>> strategy_;
};

