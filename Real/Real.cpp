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
	return units_.isPositive() == fractional_.isNumPositive();
}

bool Real::isDecimalNegative() const
{
	return units_.isPositive() != fractional_.isNumPositive();
}

bool Real::isDecimalSame(const Real& other) const
{
	return this == &other;
}

bool Real::isDecimal() const
{
	return fractional_ != Fraction(0);
}



// Арифметические операторы
Real Real::operator+(const Real& other) const
{
	Real result;

	result.units_ = units_ + other.units_;
	result.fractional_ = fractional_ + other.fractional_;

	return result;
}

Real Real::operator-(const Real& other) const
{
	Real result;

	result.units_ = units_ - other.units_;
	result.fractional_ = fractional_ - other.fractional_;

	return result;
}

Real Real::operator*(const Real& other) const
{
	Real result;

	result.units_ = units_ * other.units_;
	result.fractional_ = fractional_ * other.fractional_;

	return result;
}

Real Real::operator/(const Real& other) const
{
	if ((other.units_ == 0 || other.fractional_ == Fraction(0)) || (other.units_ == 0 && other.fractional_ == Fraction(0)))
	{
		std::cout << "Ошибка!! Деление на 0 запрещено!!\n\n";
		::exit(-1);
	}

	Real result;

	result.units_ = units_ / other.units_;
	result.fractional_ = fractional_ / other.fractional_;

	return result;
}


// Оператор вывода
std::ostream& operator<<(std::ostream& out, const Real& obj)
{
	return out << obj.units_ << '.' << obj.fractional_;
}
