#pragma once


#include <cmath>
#include <Windows.h>
#include "../Integer/Integer.hpp"

class Fraction
{
public:
	// constructors
	Fraction();
	Fraction(Integer num, Integer denum);
	Fraction(const Integer& number);

	// setters
	void SetSign(bool sign);
	void SetNumerator(Integer num);
	void SetDenominator(Integer denum);

	// getters
	bool GetSign();
	Integer GetNumerator();
	Integer GetDenominator();



	// операторо вывода
	friend std::ostream& operator<<(std::ostream& out, const Fraction& obj);

	// операторо ввода
	friend std::istream& operator>>(std::istream& in, Fraction& obj);


	// Проверка дроби

	// Правильная ли дробь
	bool isProper()const;

	// Неправильная ли дробь
	bool isImProper()const;

	// Положительная ли дробь
	bool isNumPositive()const;

	// Отрицательная ли дробь
	bool isNumNegative()const;

	// являются ли 2 числа одним и тем же объектом в программе
	bool isSame(const Fraction& other) const;

	// Проверка на эквивалентность
	bool isEqual(const Fraction& other);


	// Методы для получения значений

	// сокращенная дробь
	Fraction ReduceFraction();

	// обратная дробь
	Fraction ReverseFraction();

	// Счет целых чисел в дроби
	Integer CountUnits() const;

	Integer WholePart()const { return num_ / denum_; }

	// Счет остатка от целового числа в дроби
	Integer CountRemainder() const;


	// Арифметические операции
	Fraction operator+(const Fraction& other) const;

	Fraction operator-(const Fraction& other) const;

	Fraction operator*(const Fraction& other) const;

	Fraction operator/(const Fraction& other) const;


	// Операторы сравнения
	bool operator==(const Fraction& other) const;

	bool operator!=(const Fraction& other) const;

	bool operator<(const Fraction& other) const;

	bool operator>(const Fraction& other) const;

	bool operator<=(const Fraction& other) const;

	bool operator>=(const Fraction& other) const;


	// Операторы присваивания
	void operator+=(const Fraction& other);

	void operator-=(const Fraction& other);

	void operator*=(const Fraction& other);

	void operator/=(const Fraction& other);


	// Инкремент и декремент

	// Постфиксные
	Fraction operator++(int);

	Fraction operator--(int);

	// Префиксные
	Fraction operator++();

	Fraction operator--();


	// Унарные операторы

	//Унарный плюс
	Fraction operator+();

	// Унарный минус
	Fraction operator-() const;


	long double fractionToDouble();



	// поля
private:
	bool sign_;
	Integer num_;
	Integer denum_;
};
