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

	// �������� �����
	bool isCorrect()const;
	bool isNumPositive()const;
	bool isSame()const;


	// ����
private:
	bool sign_;
	Integer num_;
	Integer denum_;
};