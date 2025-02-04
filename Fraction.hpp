#pragma once

#include "Integer.hpp"

class Fraction
{
public:
	Fraction();
	Fraction(bool sign, Integer num);
	Fraction(Integer number);

	// setters
	void SetSign(bool sign);
	void SetNumerator(Integer num);
	void SetDenominator(Integer denum);

	// getters
	bool GetSign();
	Integer GetNumerator();
	Integer GetDenominator();

	// Проверка дроби
	bool isCorrect()const;
	bool isNumPositive()const;
	bool isSame()const;


	// поля
private:
	bool sign_;
	Integer num_;
	Integer denum_;
};