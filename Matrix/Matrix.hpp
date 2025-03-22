#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"


#include <iostream>
#include <type_traits>
#include <numeric>
#include <initializer_list>


// ������ ������������� �������

// ��� ��������� ����� �������, ������� ������ ����� �������� ������ � ������ �������
// � �������� �������� �����. ��� ����� ��� ���� ������� ���� assert �������,
// ������������� �������� ��� constraint ��������. ����� �� ���� �������� ����� ���������� ������� ���������� ������ �������.

template<typename Type, unsigned long long Row, unsigned long long Coll>

class Matrix
{
public:
	// ������������
	Matrix()
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				data_[i][j] = Type{};
			}
		}
	}

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

	// ����������� ��������
	Matrix(Matrix&& other) noexcept  
	{
		std::swap(data_, other.data_);
	}

	// ����������
	~Matrix() = default;


	// ����������� ��������
	const Matrix& operator= (Matrix&& other)   
	{
		std::swap(data_, other.data_);
		return *this;
	}



	// ������ ������� � �����
	unsigned long long collSize() const 
	{
		return Coll;
	}

	unsigned long long rowSize() const
	{
		return Row;
	}



	// �������������� ���������
	friend const Matrix& operator+ (const Matrix& lso, const Matrix& rso)
	{
		Matrix<Type, rso.rowSize(), rso.collSize()> result;

		for (int i = 0; i < rso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				result[i][j] = lso[i][j] + rso[i][j];
			}
		}

		return result;
	}

	friend const Matrix& operator- (const Matrix& lso, const Matrix& rso)
	{
		Matrix<Type, rso.rowSize(), rso.collSize()> result;

		for (int i = 0; i < rso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				result[i][j] = lso[i][j] - rso[i][j];
			}
		}

		return result;
	}

	friend const Matrix& operator* (const Matrix& lso, const Matrix& rso)
	{
		Matrix<Type, rso.rowSize(), rso.collSize()> result;

		for (int i = 0; i < lso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				result[i][j] = 0;

				for (int t = 0; t < lso.collSize(); t++)
				{
					result[i][j] += lso[i][t] * rso[t][j];
				}
			}
		}

		return result;
	}

	friend const Matrix& operator* (const Matrix& lso, const int& num)
	{
		Matrix<Type, lso.rowSize(), lso.collSize()> result;

		for (int i = 0; i < lso.rowSize(); i++)
		{
			for (int j = 0; j < lso.collSize(); j++)
			{
				result[i][j] = lso[i][j] * num;
			}
		}

		return result;
	}

	friend const Matrix& operator/ (const Matrix& lso, const Matrix& rso)
	{
		Matrix<Type, rso.rowSize(), rso.collSize()> result;

		for (int i = 0; i < lso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				result[i][j] = 0;

				for (int t = 0; t < lso.collSize(); t++)
				{
					result[i][j] += lso[i][t] * (1 / rso[t][j]);
				}
			}
		}

		return result;
	}


	// ������������� ���������
	friend const Matrix& operator+= (Matrix& lso, const Matrix& rso)
	{
		for (int i = 0; i < rso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				lso[i][j] += rso[i][j];
			}
		}

		return lso;
	}

	friend const Matrix& operator-= (Matrix& lso, const Matrix& rso)
	{
		for (int i = 0; i < rso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				lso[i][j] -= rso[i][j];
			}
		}

		return lso;
	}

	friend const Matrix& operator*= (Matrix& lso, const Matrix& rso)
	{
		Matrix<Type, rso.rowSize(), rso.collSize()> result;

		for (int i = 0; i < lso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				result[i][j] = 0;
				for (int t = 0; t < lso.collSize(); t++)
				{
					result[i][j] += lso[i][t] * rso[t][j];
				}
			}
		}
		lso = result;

		return lso;
	}

	friend const Matrix& operator*= (Matrix& lso, const int& num)
	{
		for (int i = 0; i < lso.rowSize(); i++)
		{
			for (int j = 0; j < lso.collSize(); j++)
			{
				lso[i][j] *= num;
			}
		}

		return lso;
	}

	friend const Matrix& operator/= (Matrix& lso, const Matrix& rso)
	{
		Matrix<Type, rso.rowSize(), rso.collSize()> result;

		for (int i = 0; i < lso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				result[i][j] = 0;

				for (int t = 0; t < lso.collSize(); t++)
				{
					result[i][j] += lso[i][t] * (1 / rso[t][j]);
				}
			}
		}
		lso = result;

		return lso;
	}



	// ������������� ���������
	friend const bool operator== (const Matrix& lso, const Matrix& rso);
	friend const bool operator!= (const Matrix& lso, const Matrix& rso);
	friend const bool operator> (const Matrix& lso, const Matrix& rso);
	friend const bool operator< (const Matrix& lso, const Matrix& rso);
	friend const bool operator>= (const Matrix& lso, const Matrix& rso);
	friend const bool operator<= (const Matrix& lso, const Matrix& rso);


	// �������� [] - ��������� ������ 1 ��������, � ��� ����� 2, ������� ��� �������� ()
	Type& operator() (unsigned long long row, unsigned long long �oll)
	{
		return data_[row][coll];
	}

	const Type& operator() (unsigned long long row, unsigned long long �oll) const
	{
		return data_[row][coll];
	}


	// �������� at
	Type& at(unsigned long long row, unsigned long long �oll)
	{
		return data_[row][coll];
	}

	const Type& at(unsigned long long row, unsigned long long �oll) const
	{
		return data_[row][coll];
	}



	// ��������� ����� � ������
	friend std::ostream& opeartor << (std::ostream & outs, const Matrix & rso)
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

	friend std::istream& opeartor >> (std::istream& ins, const Matrix& rso)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Coll; j++)
			{
				ins >> rso[i][j];
			}
			ins >> "\n";
		}
		return ins;
	}


private:

	// ����
	Type data_[Row][Coll];
};



namespace std
{
	template<typename Type, unsigned long long Row, unsigned long long Coll>
	struct hash<Matrix<Type, Row, Coll>>
	{
		size_t operator()(Matrix<Type, unsigned long long, unsigned long long>& obj) {
			size_t result{};
			for (size_t i = 0; i < obj.rows(); i++) {
				for (size_t j = 0; j < obj.columns(); j++) {
					result <<= 1;
					result ^= hash<Type>()(obj[i][j]);
				}
			}
			return result;
		}
	};
}