#pragma once

#include "Integer.hpp"

class Fraction
{
public:
	// constructors
	Fraction();
	Fraction(bool sign, Integer num);
	Fraction(Integer number);

	// setters
	void SetSignNum(bool sign);
	void SetSignDenum(bool sign);
	void SetNumerator(Integer num);
	void SetDenominator(Integer denum);

	// getters
	bool GetSignNum();
	bool GetSignDenum();
	Integer GetNumerator();
	Integer GetDenominator();

	// операторо вывода
	friend std::ostream& operator<<(std::ostream out, const Fraction obj);

	// Проверка дроби
	bool isProper()const;
	bool isNumPositive()const;
	bool isSame()const;

	// Методы для получения значений

	// сокращенная дробь
	void ReduceFraction();


	// поля
private:
	bool sign_;
	bool signNum_;
	bool signDenum_;
	Integer num_;
	Integer denum_;
};