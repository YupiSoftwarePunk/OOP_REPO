#pragma once

#include "Integer.hpp"
#include <cmath>

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

	// ��������� ������
	friend std::ostream& operator<<(std::ostream out, const Fraction obj);

	// �������� �����
	bool isProper()const;
	bool isNumPositive()const;
	bool isSame(Fraction other)const;

	// ������ ��� ��������� ��������

	// ����������� �����
	void ReduceFraction();

	// �������� �����
	Fraction ReverseFraction();

	// ���� ����� ����� � �����
	Integer CountUnits() const;

	// ���� ������� �� �������� ����� � �����
	// �������

	// �������������� ��������
	Fraction operator+(const Fraction& other);

	Fraction operator-(const Fraction& other);

	Fraction operator*(const Fraction& other);

	Fraction operator/(const Fraction& other);


	// ��������� ���������
	bool operator==(const Fraction& other);

	bool operator!=(const Fraction& other);

	bool operator<(const Fraction& other);

	bool operator>(const Fraction& other);


	// ����
private:
	bool sign_;
	Integer num_;
	Integer denum_;
};