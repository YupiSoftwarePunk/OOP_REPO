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


// Оператор вывода
std::ostream& operator<<(std::ostream& out, const Real& obj)
{
	return out << obj.units_ << '.' << obj.fractional_;
}
