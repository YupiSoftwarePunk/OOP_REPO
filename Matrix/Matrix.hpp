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
// в качестве хранимых типов. Для этого вам нада изучить тему assert функций,
// специализацию шаблонов или constraint шаблонов. Любой из этих способов может ограничить область применения вашего шаблона.

template<typename Type, unsigned long long Row, unsigned long long Coll>

class Matrix
{
public:
	// конструкторы
	Matrix();
	Matrix(const Matrix& other);
	Matrix(Matrix&& other) noexcept;  // конструктор переноса

	// деструктор
	~Matrix();


	const Matrix& operator= (const Matrix& other);  // конструктор присваивания копирования
	const Matrix& operator= (Matrix&& other);   // конструктор переноса


	// размер колонок и строк
	unsigned long long collSize() const;
	unsigned long long rowSize() const;



	// Арифметические операторы
	friend const Matrix& operator+ (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator- (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator* (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator* (const Matrix& lso, int num);
	friend const Matrix& operator/ (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator^ (const Matrix& lso, const Integer& rso);


	// Присваивающие операторы
	friend const Matrix& operator+= (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator-= (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator*= (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator/= (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator^= (const Matrix& lso, const Integer& rso);


	// Сравнительные операторы
	friend const bool operator== (const Matrix& lso, const Matrix& rso);
	friend const bool operator!= (const Matrix& lso, const Matrix& rso);
	friend const bool operator> (const Matrix& lso, const Matrix& rso);
	friend const bool operator< (const Matrix& lso, const Matrix& rso);
	friend const bool operator>= (const Matrix& lso, const Matrix& rso);
	friend const bool operator<= (const Matrix& lso, const Matrix& rso);


	// Оператор [] - принимает только 1 параметр, а нам нужно 2, поэтому тут оператор ()
	Type& operator() (unsigned long long row, unsigned long long сoll);
	const Type& operator() (unsigned long long row, unsigned long long сoll) const;


	// Оператор at
	Type& at(unsigned long long row, unsigned long long сoll);
	const Type& at(unsigned long long row, unsigned long long сoll) const;


	// операторы ввода и вывода
	friend std::ostream& opeartor<<(std::ostream & outs, const Matrix & rso);
	friend std::istream& opeartor>>(std::istream & ins, const Matrix & rso);


private:

	// поле
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