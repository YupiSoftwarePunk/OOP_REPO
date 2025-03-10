#include "Real.hpp"

// constructors
Real::Real(const Integer& units, const Fraction& fractional)
{
	units_ = units;
	if (!fractional.isProper()) 
	{
		units_ = units_ + (Fraction(fractional).GetNumerator() / Fraction(fractional).GetDenominator());
		Integer newNumerator = Fraction(fractional).GetNumerator() % Fraction(fractional).GetDenominator();
		fractional_ = Fraction(newNumerator, Fraction(fractional).GetDenominator());
	}
	else 
	{
		fractional_ = fractional;
	}
}

Real::Real(const Fraction& obj)
{
	if (obj.isProper()) {
		units_ = 0;
		fractional_ = obj;
	}
	else {
		units_ = Fraction(obj).GetNumerator() / Fraction(obj).GetDenominator();
		Integer newNumerator = Fraction(obj).GetNumerator() % Fraction(obj).GetDenominator();
		if (newNumerator == 0) {
			fractional_ = Fraction(0, 0);
		}
		else
		{
			fractional_ = Fraction(newNumerator, Fraction(obj).GetDenominator());
		}
	}
}



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



// Операторы сравнения

bool Real::operator<(const Real& other) const
{
	if (units_ == other.units_)
	{
		return fractional_ < other.fractional_;
	}
	else
	{
		return units_ < other.units_;
	}
}

bool Real::operator>(const Real& other) const
{
	if (units_ == other.units_)
	{
		return fractional_ > other.fractional_;
	}
	else
	{
		return units_ > other.units_;
	}
}

bool Real::operator<=(const Real& other) const
{
	if (units_ == other.units_)
	{
		return fractional_ <= other.fractional_;
	}
	else
	{
		return units_ <= other.units_;
	}
}

bool Real::operator>=(const Real& other) const
{
	if (units_ == other.units_)
	{
		return fractional_ >= other.fractional_;
	}
	else
	{
		return units_ >= other.units_;
	}
}

bool Real::operator==(const Real& other) const
{
	return units_ == other.units_ && fractional_ == other.fractional_;
}

bool Real::operator!=(const Real& other) const
{
	if (units_ == other.units_ && fractional_ == other.fractional_)
	{
		return false;
	}
	else
	{
		return true;
	}
}


// Унарные операторы
Real Real::operator+()
{
	this->units_ = units_;
	this->fractional_ = fractional_;
	return *this;
}

Real Real::operator-() const
{
	Real res = { *this };
	res.units_ = units_ * -1;
	res.fractional_ = fractional_;
	return res;
}



// Оператор вывода
std::ostream& operator<<(std::ostream& out, const Real& obj)
{
	if (obj.fractional_ == Fraction(0))
	{
		return out << obj.units_ << '.0' << obj.fractional_;
	}
	else
	{
		return out << obj.units_ << '.' << obj.fractional_;
	}
	
}
