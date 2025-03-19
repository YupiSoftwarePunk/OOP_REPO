#include "../Matrix/Matrix.hpp"

// Конструкторы
template<typename Type, unsigned long long Coll, unsigned long long Row>

Matrix<Type, Coll, Row>::Matrix()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[i][j] = Type{};
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
			data_[i][j] = other.data_[i][j];
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

Type& Matrix<Type, Coll, Row>::operator() (unsigned long long row, unsigned long long сoll)
{
	return data_[row][coll];
}

template<typename Type, unsigned long long Coll, unsigned long long Row>

const Type& Matrix<Type, Coll, Row>::operator() (unsigned long long row, unsigned long long сoll) const
{
	return data_[row][coll];
}



// Оператор at
template<typename Type, unsigned long long Coll, unsigned long long Row>

Type& Matrix<Type, Coll, Row>::at(unsigned long long row, unsigned long long сoll)
{
	if (сoll >= Coll || row >= Row)
	{
		std::cout << "Такого индекса нет в матрице!!";
		::exit(-1);
	}
	return data_[row][сoll];
}

template<typename Type, unsigned long long Coll, unsigned long long Row>

const Type& Matrix<Type, Coll, Row>::at(unsigned long long row, unsigned long long сoll) const
{
	if (сoll >= Coll || row >= Row)
	{
		std::cout << "Такого индекса нет в матрице!!";
		::exit(-1);
	}
	return data_[row][сoll];
}
