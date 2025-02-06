#pragma once

#include "Integer.hpp"
#include <cmath>
#include <Windows.h>

class Fraction
{
public:
	// constructors
	Fraction();
	Fraction(bool sign, Integer num, Integer denum);
	Fraction(Integer number);

	// setters
	void SetSign(bool sign);
	void SetNumerator(Integer num);
	void SetDenominator(Integer denum);

	// getters
	bool GetSign();
	Integer GetNumerator();
	Integer GetDenominator();

	// операторо вывода
	friend std::ostream& operator<<(std::ostream out, const Fraction obj);

	// Проверка дроби

	// Правильная ли дробь
	bool isProper()const;

	// Положительная ли дробь
	bool isNumPositive()const;

	// являются ли 2 числа одним и тем же объектом в программе
	bool isSame(Fraction other)const;

	// Методы для получения значений

	// сокращенная дробь
	void ReduceFraction();

	// обратная дробь
	Fraction ReverseFraction();

	// Счет целых чисел в дроби
	Integer CountUnits() const;

	// Счет остатка от целового числа в дроби
	// сделать

	// Арифметические операции
	Fraction operator+(const Fraction& other);

	Fraction operator-(const Fraction& other);

	Fraction operator*(const Fraction& other);

	Fraction operator/(const Fraction& other);


	// Операторы сравнения
	bool operator==(const Fraction& other);

	bool operator!=(const Fraction& other);

	bool operator<(const Fraction& other);

	bool operator>(const Fraction& other);

	bool operator<=(const Fraction & other);

	bool operator>=(const Fraction& other);

	// Операторы присваивания
	Fraction operator+=(Fraction& other);

	Fraction operator-=(Fraction& other);

	Fraction operator*=(Fraction& other);

	Fraction operator/=(Fraction& other);


	// поля
private:
	bool sign_;
	Integer num_;
	Integer denum_;
};