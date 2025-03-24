#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"

class Point2d
{
public:

	// конструкторы
	Point2d(Real num1, Real num2) : num1_(num1), num2_(num2) {}
	Point2d() : Point2d(Real(0 / 0), Real(0 / 0)) {}

	// деструктор
	virtual ~Point2d() = default;


	// setters
	void SetNum1(const Real num1);
	void SetNum2(const Real num2);

	// getters
	Real GetNum1();
	Real GetNum2();

private:

	// поля
	Real num1_;
	Real num2_;
};