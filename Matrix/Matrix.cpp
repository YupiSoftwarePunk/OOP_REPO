#include "../Matrix/Matrix.hpp"

// Конструкторы
template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::Matrix()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[Row][Coll] = Type{};
		}
	}
}

template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::Matrix(const Matrix& other)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[Row][Coll] = other.data_[Row][Coll];
		}
	}
}

template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::Matrix(Matrix&& other)
{
	data_ = nullptr;
	std::swap(data_, other.data_);
}


// Деструктор
template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::~Matrix()
{
	int capacity = sizeof(data_) / sizeof(int);
	if (capacity > 0)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				delete data_[i][j];
			}
		}
	}
}



// оператор вывода
template<typename Type, unsigned long long Coll, unsigned long long Row>
std::ostream& opeartor<< (std::ostream& outs, const Matrix& rso)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			outs << rso[i][j] << " ";
		}
		outs << "\n";
	}
	return outs;
}



// Оператор []
template<typename Type, unsigned long long Coll, unsigned long long Row>
Type& Matrix<Type, Coll, Row>::operator() (unsigned long long Coll, unsigned long long Row)
{
	return data_[Row][Coll];
}