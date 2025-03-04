#include "Real.hpp"

//setters
void Real::SetUnits(Integer units)
{
	this->units_ = units;
}

void Real::SetFractional(Fraction fractional)
{
	this->fractional_ = fractional;
}


//getters
Integer Real::GetUnits()
{
	return units_;
}

Fraction Real::GetFractional()
{
	return fractional_;
}


// Проверки числа
bool Real::isDecimalPositive() const
{
	return units_.isPositive() && fractional_.isNumPositive();
}

bool Real::isDecimalNegative() const
{
	return units_.isNegative() && fractional_.isNumNegative();
}

bool Real::isDecimalSame(const Real& other) const
{
	return this == &other;
}

bool Real::isDecimal() const
{
	return fractional_ != Fraction(0);
}


// Оператор вывода
std::ostream& operator<<(std::ostream& out, const Real& obj)
{
	return out << obj.units_ << '.' << obj.fractional_;
}
