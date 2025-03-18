#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"


#include <iostream>
#include <type_traits>
#include <numeric>
#include <initializer_list>


// шаблонные классы
// шаблон целочисленной матрицы

// это шаблонный класс матрицы, который должен уметь работать только с целыми числами
// в качестве хранимых типов. Для этого вам нада изучить тему assert функций,
// специализацию шаблонов или constraint шаблонов. Любой из этих способов может ограничить область применения вашего шаблона.

template<typename Type, unsigned long long Coll, unsigned long long Row>

class Matrix
{
public:
	Matrix();
	Matrix(/* набор параметров, который сюда можно передать */);
	Matrix(const Matrix& other);
	Matrix(Matrix&& dead);
	~Matrix();

	const Matrix& operator= (const Matrix& other);
	const Matrix& operator= (Matrix&& other);

	// operator[][]  сделать это самостоятельно
	//  так же сюда должен быть добавлен метод at


	// Арифметические операторы
	friend const Matrix& operator+ (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator- (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator* (const Matrix& lso, const Matrix& rso);
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
	friend const bool operator<= (const Matrix& lso, const Matrix& rso);
	friend const bool operator>= (const Matrix& lso, const Matrix& rso);
	friend const bool operator^= (const Matrix& lso, const Matrix& rso);
	friend const bool operator=^ (const Matrix& lso, const Matrix& rso);


	// Оператор []
	Type& operator[] (unsigned long long Coll, unsigned long long Row);


	// Оператор at
	Type& at(unsigned long long Coll, unsigned long long Row);


	// операторы ввода и вывода
	friend std::ostream& opeartor<<(std::ostream & outs, const Matrix & rso);
	friend std::istream& opeartor>>(std::istream & ins, const Matrix & rso);

	// какие-то из операторов выше нужны, а некоторые нет и нужно это обосновать

	// нужны методы для получения определителя матрицы
	// транспонирования матрицы как модифицирующего так и нет




private:
	Type data_[Coll][Row];
};

namespace std
{
	template<typename Type, unsigned long long Coll, unsigned long long Row>
	struct hash<Matrix<Type, Coll, Row>>
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