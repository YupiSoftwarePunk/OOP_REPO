#include "../Matrix/Matrix.hpp"

////  онструкторы
//template<typename Type, unsigned long long Row, unsigned long long Coll>
//
//Matrix<Type, Row, Coll>::Matrix()
//{
//	for (int i = 0; i < Row; i++)
//	{
//		for (int j = 0; j < Coll; j++)
//		{
//			data_[i][j] = Type{};
//		}
//	}
//}
//
//
////  онструктор копировани€
//template<typename Type, unsigned long long Row, unsigned long long Coll>
//
//Matrix<Type, Row, Coll>::Matrix(const Matrix& other)
//{
//	for (int i = 0; i < Row; i++)
//	{
//		for (int j = 0; j < Coll; j++)
//		{
//			data_[i][j] = other.data_[i][j];
//		}
//	}
//}
//
//
//template<typename Type, unsigned long long Row, unsigned long long Coll>
//
//Matrix<Type, Row, Coll>::Matrix(Matrix&& other) noexcept
//{
//	std::swap(data_, other.data_);
//}
//
//
//// конструктор присваивани€ копировани€
//template<typename Type, unsigned long long Row, unsigned long long Coll>
//
//const Matrix& Matrix<Type, Row, Coll>::operator= (const Matrix& other)
//{
//	if (this == &other)
//	{
//		return *this;
//	}
//	for (int i = 0; i < Row; i++)
//	{
//		for (int j = 0; j < Coll; j++)
//		{
//			data_[i][j] = other.data_[i][j];
//		}
//	}
//
//	return *this;
//}
//
//
//// конструктор переноса
//template<typename Type, unsigned long long Row, unsigned long long Coll>
//
//const Matrix& Matrix<Type, Row, Coll>::operator= (Matrix&& other)
//{
//	for (int i = 0; i < Row; i++)
//	{
//		for (int j = 0; j < Coll; j++)
//		{
//			data_[i][j] = other.data_[i][j];
//		}
//	}
//
//	return *this;
//}
//
//
//
//// деструктор
//template<typename Type, unsigned long long Row, unsigned long long Coll>
//
//Matrix<Type, Row, Coll>::~Matrix() = default;







//// оператор вывода
//template<typename Type, unsigned long long Row, unsigned long long Coll>
//
//std::ostream& opeartor << (std::ostream& outs, const Matrix<Type, Row, Coll>& rso)
//{
//	for (int i = 0; i < Row; i++)
//	{
//		for (int j = 0; j < Coll; j++)
//		{
//			outs << rso[i][j] << " ";
//		}
//		outs << "\n";
//	}
//	return outs;
//}




//// јрифметические операторы
//const Matrix& operator+(const Matrix& lso, const Matrix& rso)
//{
//	if ((lso.collSize() == rso.collSize()) && (lso.rowSize() == rso.rowSize()))
//	{
//		Matrix<Type, rso.rowSize(), rso.collSize()> result;
//
//		for (int i = 0; i < rso.rowSize(); i++)
//		{
//			for (int j = 0; j < rso.collSize(); j++)
//			{
//				result[i][j] = lso[i][j] + rso[i][j];
//			}
//		}
//
//		return result;
//	}
//	else
//	{
//		std::cout << "–азмеры матриц должны быть равны!!";
//		::exit(-1);
//	}
//}
//
//
//const Matrix& operator-(const Matrix& lso, const Matrix& rso)
//{
//	if ((lso.collSize() == rso.collSize()) && (lso.rowSize() == rso.rowSize()))
//	{
//		Matrix<Type, rso.rowSize(), rso.collSize()> result;
//
//		for (int i = 0; i < rso.rowSize(); i++)
//		{
//			for (int j = 0; j < rso.collSize(); j++)
//			{
//				result[i][j] = lso[i][j] - rso[i][j];
//			}
//		}
//
//		return result;
//	}
//	else
//	{
//		std::cout << "–азмеры матриц должны быть равны!!";
//		::exit(-1);
//	}
//}
//
//
//const Matrix& operator*(const Matrix& lso, const Matrix& rso)
//{
//	if (((lso.collSize() == rso.collSize()) && (lso.rowSize() == rso.rowSize())) || 
//		((rso.collSize() - lso.collSize() == 1) && (rso.rowSize() - lso.rowSize() == 1)))
//	{
//		Matrix<Type, rso.rowSize(), rso.collSize()> result;
//
//		for (int i = 0; i < lso.rowSize(); i++)
//		{
//			for (int j = 0; j < rso.collSize(); j++)
//			{
//				result[i][j] = 0;
//
//				for (int t = 0; t < lso.collSize(); t++)
//				{
//					result[i][j] += lso[i][t] * rso[t][j];
//				}
//			}
//		}
//
//		return result;
//	}
//	else
//	{
//		std::cout << "–азмеры матриц должны быть равны или внутренние размеры матриц должны совпадать!!";
//		::exit(-1);
//	}
//}
//
//
//const Matrix& operator*(const Matrix& lso, const int& num)
//{
//	Matrix<Type, lso.rowSize(), lso.collSize()> result;
//
//	for (int i = 0; i < lso.rowSize(); i++)
//	{
//		for (int j = 0; j < lso.collSize(); j++)
//		{
//			result[i][j] = lso[i][j] * num;
//		}
//	}
//
//	return result;
//}
//
//
//const Matrix& operator/(const Matrix& lso, const Matrix& rso)
//{
//	if ((lso.collSize() == rso.collSize()) && (lso.rowSize() == rso.rowSize()))
//	{
//		Matrix<Type, rso.rowSize(), rso.collSize()> result;
//
//		for (int i = 0; i < lso.rowSize(); i++)
//		{
//			for (int j = 0; j < rso.collSize(); j++)
//			{
//				result[i][j] = 0;
//
//				for (int t = 0; t < lso.collSize(); t++)
//				{
//					result[i][j] += lso[i][t] * (1 / rso[t][j]);
//				}
//			}
//		}
//
//		return result;
//	}
//	else
//	{
//		std::cout << "–азмеры матриц должны быть равны!!";
//		::exit(-1);
//	}
//}




//// ѕрисваивающие операторы
//const Matrix& operator+=(Matrix& lso, const Matrix& rso)
//{
//	if ((lso.collSize() == rso.collSize()) && (lso.rowSize() == rso.rowSize()))
//	{
//		for (int i = 0; i < rso.rowSize(); i++)
//		{
//			for (int j = 0; j < rso.collSize(); j++)
//			{
//				lso[i][j] += rso[i][j];
//			}
//		}
//
//		return lso;
//	}
//	else
//	{
//		std::cout << "–азмеры матриц должны быть равны!!";
//		::exit(-1);
//	}
//}
//
//
//const Matrix& operator-=(Matrix& lso, const Matrix& rso)
//{
//	if ((lso.collSize() == rso.collSize()) && (lso.rowSize() == rso.rowSize()))
//	{
//		for (int i = 0; i < rso.rowSize(); i++)
//		{
//			for (int j = 0; j < rso.collSize(); j++)
//			{
//				lso[i][j] -= rso[i][j];
//			}
//		}
//
//		return lso;
//	}
//	else
//	{
//		std::cout << "–азмеры матриц должны быть равны!!";
//		::exit(-1);
//	}
//}
//
//
//const Matrix& operator*=(Matrix& lso, const Matrix& rso)
//{
//	if (((lso.collSize() == rso.collSize()) && (lso.rowSize() == rso.rowSize())) || 
//		((rso.collSize() - lso.collSize() == 1) && (rso.rowSize() - lso.rowSize() == 1)))
//	{
//		Matrix<Type, rso.rowSize(), rso.collSize()> result;
//
//		for (int i = 0; i < lso.rowSize(); i++)
//		{
//			for (int j = 0; j < rso.collSize(); j++)
//			{
//				result[i][j] = 0;
//				for (int t = 0; t < lso.collSize(); t++)
//				{
//					result[i][j] += lso[i][t] * rso[t][j];
//				}
//			}
//		}
//		lso = result;
//
//		return lso;
//	}
//	else
//	{
//		std::cout << "–азмеры матриц должны быть равны или внутренние размеры матриц должны совпадать!!";
//		::exit(-1);
//	}
//}
//
//
//const Matrix& operator*=(Matrix& lso, const int& num)
//{
//	for (int i = 0; i < lso.rowSize(); i++)
//	{
//		for (int j = 0; j < lso.collSize(); j++)
//		{
//			lso[i][j] *= num;
//		}
//	}
//
//	return lso;
//}
//
//
//const Matrix& operator/=(Matrix& lso, const Matrix& rso)
//{
//	if ((lso.collSize() == rso.collSize()) && (lso.rowSize() == rso.rowSize()))
//	{
//		Matrix<Type, rso.rowSize(), rso.collSize()> result;
//
//		for (int i = 0; i < lso.rowSize(); i++)
//		{
//			for (int j = 0; j < rso.collSize(); j++)
//			{
//				result[i][j] = 0;
//
//				for (int t = 0; t < lso.collSize(); t++)
//				{
//					result[i][j] += lso[i][t] * (1 / rso[t][j]);
//				}
//			}
//		}
//		lso = result;
//
//		return lso;
//	}
//	else
//	{
//		std::cout << "–азмеры матриц должны быть равны!!";
//		::exit(-1);
//	}
//}
