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
	if (obj.isProper()) 
	{
		units_ = 0;
		fractional_ = obj;
	}
	else 
	{
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


// преобразование из double
Real::Real(long double obj)
{
	units_ = static_cast<Integer>(static_cast<int>(obj));

	long double fractional_part = obj - static_cast<int>(obj);


	if (fractional_part == 0.0)
	{
		fractional_ = Fraction(0, 1); 
	}
	else
	{
		const int denominator = 1000000; 
		int numerator = static_cast<int>(fractional_part * denominator);

		fractional_ = Fraction(numerator, denominator).ReduceFraction();
	}
}



// преобразование в double
long double Real::ToDouble() 
{
	
	long double result = static_cast<long double>(units_.integerToDouble());

	if (fractional_ != Fraction(0, 1))
	{
		result += static_cast<long double>(fractional_.GetNumerator().integerToDouble()) /
				  static_cast<long double>(fractional_.GetDenominator().integerToDouble());
	}

	return result;
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

	if (units_ > other.units_)
	{
		result.units_ = units_ - other.units_;
	}
	else
	{
		result.units_ = other.units_ - units_;
	}

	if (fractional_ > other.fractional_)
	{
		result.fractional_ = fractional_ - other.fractional_;
	}
	else
	{
		result.fractional_ = other.fractional_ - fractional_;
	}

	return result;
}

Real Real::operator*(const Real& other) const
{
	Real result;

	// сначала преобразовать в неправильную дробь, потом умножить, а затем преобразовать в реал

	result.units_ = units_ * other.units_;
	result.fractional_ = fractional_ * other.fractional_;

	return result;
}

Real Real::operator/(const Real& other) const    // переписать оператор
{
	if ((other.units_ == 0 || other.fractional_ == Fraction(0)) || (other.units_ == 0 && other.fractional_ == Fraction(0)))
	{
		std::cout << "Ошибка!! Деление на 0 запрещено!!\n\n";
		::exit(-1);
	}

	/*Real result;

	result.units_ = units_ / other.units_;
	result.fractional_ = fractional_ / other.fractional_;

	return result;*/



	Integer resUnits = units_;
	Fraction resFractional = fractional_;

	Integer resUnits2 = other.units_;
	Fraction resFractional2 = other.fractional_;

	long double res1 = resUnits.integerToDouble() / resUnits2.integerToDouble();
	long double res2 = resFractional.fractionToDouble() / resFractional2.fractionToDouble();

	Real result;

	result.units_ = Integer(res1);
	result.fractional_ = Fraction(res2);

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


// Операторы присваивания
Real& Real::operator+=(const Real& other)
{
	units_ += other.units_;
	fractional_ += other.fractional_;
	units_ += fractional_.WholePart();
	return *this;
}

Real& Real::operator-=(const Real& other) 
{
	units_ -= other.units_;
	fractional_ -= other.fractional_;
	units_ += fractional_.WholePart();
	return *this;
}

Real& Real::operator*=(const Real& other) 
{
	units_ *= other.units_;
	fractional_ *= other.fractional_;
	units_ += fractional_.WholePart();
	return *this;
}

Real& Real::operator/=(const Real& other)  // пофиксить
{
	/**this = *this / other;*/

	units_ /= other.units_;
	fractional_ /= other.fractional_;
	units_ += fractional_.WholePart();

	return *this;
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
		return out << obj.units_ << "(" << obj.fractional_ << ')';
	}
	else
	{
		return out << obj.units_ << "(" << obj.fractional_ << ')';
	}

}

std::istream& operator>>(std::istream& in, Real& obj)
{
	std::string input;
	in >> input;

	int slashPos = input.find('/');
	int bracketPos1 = input.find('(');
	int bracketPos2 = input.find(')');

	Integer units = 0;
	Integer fractionalNum = 0;
	Integer fractionalDenum = 0;
	Fraction fractional;

	bool sign = false;
	int startPos = 0;


	if (!input.empty() && input[0] == '-')
	{
		sign = true;
		startPos = 1;
	}


	for (int i = startPos; i < bracketPos1; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			if (input[0] == '-')
			{
				units = units * 10 + (input[i] - '0');
				units = -units;
			}
			else
			{
				units = units * 10 + (input[i] - '0');
			}
		}
	}

	for (int i = bracketPos1 + 1; i < slashPos; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			fractionalNum = fractionalNum * 10 + (input[i] - '0');
		}
	}

	for (int i = slashPos + 1; i < bracketPos2; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			fractionalDenum = fractionalDenum * 10 + (input[i] - '0');
		}
	}

	fractional.SetNumerator(fractionalNum);
	fractional.SetDenominator(fractionalDenum);

	obj.units_ = units;
	obj.fractional_ = fractional;


	return in;
}
