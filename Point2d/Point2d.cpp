#include "Point2d.hpp"

// setters
void Point2d::SetNum1(const Real num1)
{
	this->num1_ = num1;
}

void Point2d::SetNum2(const Real num2)
{
	this->num2_ = num2;
}


// getters
Real Point2d::GetNum1()
{
	return num1_;
}

Real Point2d::GetNum2()
{
	return num2_;
}

