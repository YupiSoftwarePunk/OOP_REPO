#include "Fraction.hpp"


// constructors
Fraction::Fraction() : Fraction(/*false, */Integer(0), Integer(1)) {}
Fraction::Fraction(/*bool sign, */Integer num, Integer denum) :/*sign_(sign), */num_(num), denum_(denum)
{
	if (denum == 0)
	{
		throw std::invalid_argument("\nЗнаменатель не может быть равен нулю!!\n");
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

bool Fraction::isNumNegative() const
{
	return sign_ == true;
}

bool Fraction::isProper() const
{
	return num_ < denum_;
}

bool Fraction::isImProper() const
{
	return num_ > denum_;
}

bool Fraction::isSame(const Fraction &other) const      // нужно сравнить адреса параметров
{
	return this == &other;
}

bool Fraction::isEqual(const Fraction& other)
{
	return num_ == other.num_ && denum_ == other.denum_;
}


// методы получения значений
Fraction Fraction::ReduceFraction()
{
	Integer nod = num_.Nod(denum_);
	num_ /= nod;
	denum_ /= nod;
	return *this;
}

Fraction Fraction::ReverseFraction()
{
	std::swap(num_, denum_);
	return *this;
}

Integer Fraction::CountUnits() const
{
	Integer units;
	if (sign_ == false)
	{
		units = num_ / denum_;
		return units;
	}
	else
	{
		units = num_ / denum_;
		return units + Integer(1);
	}
}

Integer Fraction::CountRemainder()const
{
	Integer remainder = num_ % denum_;
	return remainder;
}


// Арифметические операции
Fraction Fraction::operator+(const Fraction& other) const
{
	//Integer numerator;
	//Integer denominator;
	//
	//if (sign_ == false && other.sign_ == false)
	//{
	//	numerator = num_ * other.denum_ + other.num_ * denum_;
	//	denominator = denum_ * other.denum_;
	//	result.sign_ = false;
	//}
	//else if (sign_ == true && other.sign_ == false)
	//{
	//	numerator = num_ * other.denum_ - other.num_ * denum_;
	//	denominator = denum_ * other.denum_;
	//	result.sign_ = true;
	//}
	//else
	//{
	//	numerator = num_ * other.denum_ - other.num_ * denum_;
	//	denominator = denum_ * other.denum_;
	//	result.sign_ = true;
	//}
	//result.num_ = numerator;
	//result.denum_ = denominator;

	Fraction result;

	if (this->denum_ == other.denum_)
	{
		result.denum_ = this->denum_;
		result.num_ = this->num_ + other.num_;
	}
	else
	{
		result.denum_ = this->denum_ * other.denum_;
		result.num_ = this->num_ * other.denum_ + other.num_ * this->denum_;
	}

	return result;
}

Fraction Fraction::operator-(const Fraction& other) const
{
	Fraction result;

	if (this->denum_ == other.denum_)
	{
		result.denum_ = this->denum_;
		result.num_ = this->num_ - other.num_;
	}
	else
	{
		result.denum_ = this->denum_ * other.denum_;
		result.num_ = this->num_ * other.denum_ - other.num_ * this->denum_;
	}

	return result;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction result;

	result.denum_ = this->denum_ * other.denum_;
	result.num_ = this->num_ * other.num_;

	return result;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction result;
	if ((denum_ == 0 || other.num_ == 0) || (denum_ == 0 && other.num_ == 0))
	{
		std::cout << "Ошибка!! Деление на 0 запрещено!!\n\n";
		::exit(-1);
	}

	result.denum_ = this->denum_ * other.num_;
	result.num_ = this->num_ * other.denum_;
	return result;
}


// Операторы сравнения
bool Fraction::operator==(const Fraction& other) const
{
	return num_ == other.num_ && denum_ == other.denum_;
}

bool Fraction::operator!=(const Fraction& other) const
{
	if (num_ != other.num_ && denum_ != other.denum_)
	{
		return true;
	}
	else if (num_ == other.num_ && denum_ != other.denum_)
	{
		return true;
	}
	else if (num_ != other.num_ && denum_ == other.denum_)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Fraction::operator<(const Fraction& other) const
{
	Integer num1;
	Integer num2;
	if (sign_ == other.sign_)
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 < num2;
	}
	else if (sign_ < other.sign_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator>(const Fraction& other) const
{
	Integer num1;
	Integer num2;
	if (sign_ == other.sign_)
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 > num2;
	}
	else if (sign_ > other.sign_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator<=(const Fraction& other) const
{
	Integer num1;
	Integer num2;
	if (sign_ == other.sign_)
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 <= num2;
	}
	else if (sign_ < other.sign_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator>=(const Fraction& other) const
{
	Integer num1;
	Integer num2;
	if (sign_ == other.sign_)
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 >= num2;
	}
	else if (sign_ > other.sign_)
	{
		return true;
	}
	else
	{
		return false;
	}
}


// Операторы присваивания
Fraction Fraction::operator+=(const Fraction& other)
{
	Integer numerator;
	Integer denominator;

	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		sign_ = false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		if (num_ * other.denum_ >= other.num_ * denum_)
		{
			numerator = num_ * other.denum_ - other.num_ * denum_;
			denominator = denum_ * other.denum_;
			sign_ = true;
		}
		else
		{
			numerator = other.num_ * denum_ - num_ * other.denum_;
			denominator = denum_ * other.denum_;
			sign_ = true;
		}
	}
	else if (sign_ == false && other.sign_ == true)
	{
		if (num_ * other.denum_ >= other.num_ * denum_)
		{
			numerator = num_ * other.denum_ + other.num_ * denum_;
			denominator = denum_ * other.denum_;
			sign_ = true;
		}
		else
		{
			numerator = other.num_ * denum_ + num_ * other.denum_;
			denominator = denum_ * other.denum_;
			sign_ = true;
		}
	}
	else
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		sign_ = true;
	}

	num_ = numerator;
	denum_ = denominator;

	return *this;
}

Fraction Fraction::operator-=(const Fraction& other)
{
	Integer numerator;
	Integer denominator;

	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.denum_ - other.num_ * denum_;
		denominator = denum_ * other.denum_;
		sign_ = false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		if (num_ * other.denum_ >= other.num_ * denum_)
		{
			numerator = num_ * other.denum_ + other.num_ * denum_;
			denominator = denum_ * other.denum_;
			sign_ = true;
		}
		else
		{
			numerator = other.num_ * denum_ + num_ * other.denum_;
			denominator = denum_ * other.denum_;
			sign_ = true;
		}
	}
	else if (sign_ == false && other.sign_ == true)
	{
		if (num_ * other.denum_ >= other.num_ * denum_)
		{
			numerator = num_ * other.denum_ - other.num_ * denum_;
			denominator = denum_ * other.denum_;
			sign_ = true;
		}
		else
		{
			numerator = other.num_ * denum_ - num_ * other.denum_;
			denominator = denum_ * other.denum_;
			sign_ = true;
		}
	}
	else
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		sign_ = true;
	}

	num_ = numerator;
	denum_ = denominator;

	return *this;
}

Fraction Fraction::operator*=(const Fraction& other)
{
	Integer numerator;
	Integer denominator;
	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.num_;
		denominator = denum_ * other.denum_;
		sign_ = false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.num_;
		denominator = denum_ * other.denum_;
		sign_ = true;
	}
	else
	{
		numerator = num_ * other.num_;
		denominator = denum_ * other.denum_;
		sign_ = true;
	}
	num_ = numerator;
	denum_ = denominator;

	return *this;
}

Fraction Fraction::operator/=(const Fraction& other)
{
	Integer numerator;
	Integer denominator;
	if (denum_ == 0 || other.num_ == 0)
	{
		std::cout << "Ошибка!! Деление на 0 запрещено!!\n\n";
		::exit(-1);
	}
	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.denum_;
		denominator = denum_ * other.num_;
		sign_ = false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.denum_;
		denominator = denum_ * other.num_;
		sign_ = true;
	}
	else
	{
		numerator = num_ * other.denum_;
		denominator = denum_ * other.num_;
		sign_ = true;
	}
	num_ = numerator;
	denum_ = denominator;

	return *this;
}


// Инкремент и декремент
// Постфиксные
Fraction Fraction::operator++(int)
{
	if (sign_ == false)
	{
		this->num_ += denum_;
		this->denum_ = denum_;
	}
	else
	{
		this->num_ -= denum_;
		this->denum_ = denum_;
	}
	return *this;
}

Fraction Fraction::operator--(int)
{
	if (sign_ == false)
	{
		this->num_ -= denum_;
		this->denum_ = denum_;
	}
	else
	{
		this->num_ += denum_;
		this->denum_ = denum_;
	}
	return *this;
}


// Префиксные
Fraction Fraction::operator++()
{
	if (sign_ == false)
	{
		this->num_ += denum_;
		this->denum_ = denum_;
	}
	else
	{
		this->num_ -= denum_;
		this->denum_ = denum_;
	}
	return *this;
}

Fraction Fraction::operator--()
{
	if (sign_ == false)
	{
		this->num_ -= denum_;
		this->denum_ = denum_;
	}
	else
	{
		this->num_ += denum_;
		this->denum_ = denum_;
	}
	return *this;
}



// Унарные операторы

//Унарный плюс
Fraction Fraction::operator+()
{
	this->num_ = num_;
	this->denum_ = denum_;
	return *this;
}

Fraction Fraction::operator-()
{
	Fraction res = { *this };
	res.sign_ != sign_;
	res.num_ = num_;
	res.denum_ = denum_;
	return res;
}



// оператор вывода
std::ostream& operator<<(std::ostream& out, const Fraction& obj)
{
	if (obj.sign_ == true)
	{
		return out << "-(" << obj.num_ << "/" << obj.denum_ << ")";
	}
	else
	{
		return out << obj.num_ << "/" << obj.denum_;
	}
}
