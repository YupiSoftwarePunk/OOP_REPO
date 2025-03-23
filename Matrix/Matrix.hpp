#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"


#include <iostream>
#include <type_traits>
#include <numeric>
#include <initializer_list>


// шаблон целочисленной матрицы

// это шаблонный класс матрицы, который должен уметь работать только с целыми числами
// в качестве хранимых типов. ƒл€ этого вам нада изучить тему assert функций,
// специализацию шаблонов или constraint шаблонов. Ћюбой из этих способов может ограничить область применени€ вашего шаблона.

template<typename Type, unsigned long long Row, unsigned long long Coll>

class Matrix
{
public:
	// конструкторы
	Matrix() {}

	Matrix(const Matrix& other)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				data_[i][j] = other.data_[i][j];
			}
		}
	}

	// конструктор переноса
	Matrix(Matrix&& other) noexcept  
	{
		std::swap(data_, other.data_);
	}

	// деструктор
	~Matrix() = default;


	// конструктор переноса
	const Matrix& operator= (Matrix&& other)   
	{
		std::swap(data_, other.data_);
		return *this;
	}



	// размер колонок и строк
	unsigned long long collSize() const 
	{
		return Coll;
	}

	unsigned long long rowSize() const
	{
		return Row;
	}



	// јрифметические операторы
	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator+ (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		Matrix<Type, Row, Coll> result;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				result[i][j] = lso[i][j] + rso[i][j];
			}
		}

		return result;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator- (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		Matrix<Type, Row, Coll> result;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				result[i][j] = lso[i][j] - rso[i][j];
			}
		}

		return result;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator* (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		Matrix<Type, Row, Coll> result;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				result[i][j] = 0;

				for (int t = 0; t < Coll; t++)
				{
					result[i][j] += lso[i][t] * rso[t][j];
				}
			}
		}

		return result;
	}

	friend const Matrix& operator* (const Matrix<Type, Row, Coll>& lso, const int& num)
	{
		Matrix<Type, Row, Coll> result;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				result[i][j] = lso[i][j] * num;
			}
		}

		return result;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator/ (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		Matrix<Type, Row, Coll> result;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				result[i][j] = 0;

				for (int t = 0; t < Coll; t++)
				{
					result[i][j] += lso[i][t] * (1 / rso[t][j]);
				}
			}
		}

		return result;
	}



	// ѕрисваивающие операторы
	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator+= (
		Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				lso[i][j] += rso[i][j];
			}
		}

		return lso;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator-= (
		Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				lso[i][j] -= rso[i][j];
			}
		}

		return lso;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator*= (
		Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		Matrix<Type, Row, Coll> result;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				result[i][j] = 0;
				for (int t = 0; t < Coll; t++)
				{
					result[i][j] += lso[i][t] * rso[t][j];
				}
			}
		}
		lso = result;

		return lso;
	}

	friend const Matrix& operator*= (Matrix<Type, Row, Coll>& lso, const int& num)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				lso[i][j] *= num;
			}
		}

		return lso;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator/= (
		Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		Matrix<Type, Row, Coll> result;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				result[i][j] = 0;

				for (int t = 0; t < Coll; t++)
				{
					result[i][j] += lso[i][t] * (1 / rso[t][j]);
				}
			}
		}
		lso = result;

		return lso;
	}



	// —равнительные операторы
	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator== (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		for (int i = 0; i < Row; i++) 
		{
			for (int j = 0; j < Coll; j++) 
			{
				if (lso[i][j] != rso[i][j]) 
				{
					return false;
				}
			}
		}
		return true;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator!= (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				if (lso[i][j] != rso[i][j])
				{
					return true;
				}
			}
		}
		return false;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator> (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				if (lso[i][j] < rso[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator< (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				if (lso[i][j] > rso[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator>= (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				if (lso[i][j] <= rso[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

	template<unsigned long long Row2, unsigned long long Coll2>
	friend const Matrix& operator<= (
		const Matrix<Type, Row, Coll>& lso,
		const Matrix<Type, Row2, Coll2>& rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				if (lso[i][j] >= rso[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}


	// ќператор [] - принимает только 1 параметр, а нам нужно 2, поэтому тут оператор ()
	Type& operator() (unsigned long long Row, unsigned long long Coll)
	{
		return data_[Row][Coll];
	}

	const Type& operator() (unsigned long long Row, unsigned long long Coll) const
	{
		return data_[Row][Coll];
	}


	// ќператор at
	Type& at(unsigned long long Row, unsigned long long Coll)
	{
		return data_[Row][Coll];
	}

	const Type& at(unsigned long long Row, unsigned long long Coll) const
	{
		return data_[Row][Coll];
	}



	// операторы ввода и вывода
	friend std::ostream& operator << (std::ostream & outs, const Matrix & rso)
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

	friend std::istream& operator >> (std::istream & ins, const Matrix & rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				ins >> rso[i][j] >> " ";
			}
		}
		return ins;
	}


private:

	// поле
	Type data_[Row][Coll];
};



namespace std
{
	template<typename Type, unsigned long long Row, unsigned long long Coll>
	struct hash<Matrix<Type, Row, Coll>>
	{
		size_t operator()(const Matrix<Type, Coll, Row>& obj) {
			size_t result{};
			for (size_t i = 0; i < obj.rowSize(); i++) {
				for (size_t j = 0; j < obj.collSize(); j++) {
					result <<= 1;
					result ^= hash<Type>()(obj[i][j]);
				}
			}
			return result;
		}
	};
}