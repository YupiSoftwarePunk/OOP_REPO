#include "Fraction.hpp"


// constructors
Fraction::Fraction() : Fraction(false, Integer(0), Integer(1)) {}
Fraction::Fraction(bool sign, Integer num, Integer denum) :sign_(sign), num_(num), denum_(denum) 
{
	if (denum < Integer(1))
	{
		throw std::invalid_argument("Знаменатель не может быть отрицательным");
	}
}
Fraction::Fraction(Integer number)
{
	if (number < 0)
	{
		sign_ = true;
		this->num_ = Integer(-static_cast<Integer>(number));
		this->denum_ = static_cast<Integer>(1);
	}
	else
	{
		sign_ = false;
		this->num_ = number;
		this->denum_ = static_cast<Integer>(1);
	}
}


// setters and getters

//setters
void Fraction::SetSign(bool sign)
{
	this->sign_ = sign;
}

void Fraction::SetNumerator(Integer num)
{
	this->num_ = num;
}

void Fraction::SetDenominator(Integer denum)
{
	this->denum_ = denum;
}


// getters
bool Fraction::GetSign()
{
	return sign_;
}

Integer Fraction::GetNumerator()
{
	return num_;
}

Integer Fraction::GetDenominator()
{
	return denum_;
}


// Проверка дроби
bool Fraction::isNumPositive() const
{
	return sign_ == false;
}

bool Fraction::isProper() const
{
	return num_ < denum_;
}

bool Fraction::isSame(Fraction other) const
{
	return sign_ == other.sign_ && num_ == other.num_ && denum_ == other.denum_;
}


// методы получения значений
void Fraction::ReduceFraction()
{
	Integer nod = num_.Nod(denum_);
	num_ /= nod;
	denum_ /= nod;
	std::cout << num_ << "/" << denum_ << "\n";
}

Fraction Fraction::ReverseFraction()
{
	Integer temp;
	temp = num_;
	num_ = denum_;
	denum_ = temp;
	return *this;
}

Integer Fraction::CountUnits() const
{
	Integer units = num_ / denum_;
	return units;
}


// Арифметические операции
Fraction Fraction::operator+(const Fraction& other)
{
	Integer numerator;
	Integer denominator;
	Fraction result;
	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ == false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.denum_ - other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ == true;
	}
	else
	{
		numerator = num_ * other.denum_ - other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ == true;
	}
	result.num_ = numerator;
	result.denum_ = denominator;

	return result;
}

Fraction Fraction::operator-(const Fraction& other)
{
	Integer numerator;
	Integer denominator;
	Fraction result;
	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.denum_ - other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ == false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ == true;
	}
	else
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ == true;
	}
	result.num_ = numerator;
	result.denum_ = denominator;

	return result;
}

Fraction Fraction::operator*(const Fraction& other)
{
	Integer numerator;
	Integer denominator;
	Fraction result;
	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.num_;
		denominator = denum_ * other.denum_;
		result.sign_ == false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.num_;
		denominator = denum_ * other.denum_;
		result.sign_ == true;
	}
	else
	{
		numerator = num_ * other.num_;
		denominator = denum_ * other.denum_;
		result.sign_ == true;
	}
	result.num_ = numerator;
	result.denum_ = denominator;

	return result;
}

Fraction Fraction::operator/(const Fraction& other)
{
	Integer numerator;
	Integer denominator;
	Fraction result;
	if (denum_ == 0 || other.num_ == 0)
	{
		std::cout << "Ошибка!! Деление на 0 запрещено!!\n\n";
		::exit(-1);
	}
	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.denum_;
		denominator = denum_ * other.num_;
		result.sign_ == false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.denum_;
		denominator = denum_ * other.num_;
		result.sign_ == true;
	}
	else
	{
		numerator = num_ * other.denum_;
		denominator = denum_ * other.num_;
		result.sign_ == true;
	}
	result.num_ = numerator;
	result.denum_ = denominator;

	return result;
}



// оператор вывода
std::ostream& operator<<(std::ostream out, const Fraction obj)
{
	if (obj.sign_ == false)
	{
		if (obj.denum_ == 1) {

			out << obj.num_;
		}
		else {
			out << obj.num_ << "/" << obj.denum_;
		}
	}
	else
	{
		if (obj.denum_ == 1) 
		{
			out << '-' << obj.num_;
		}
	}
	return out;
}
