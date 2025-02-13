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

bool Fraction::isSame(const Fraction &other) const
{
	return num_ * other.denum_ == other.num_ * denum_;
}

bool Fraction::isEqual(const Fraction& obj, const Fraction& other)
{
	//return ReduceFraction(obj) == ReduceFraction(other);
	::exit(-1);   // пока так
}


// методы получения значений
Fraction Fraction::ReduceFraction()
{
	Integer nod = num_.Nod(denum_);
	num_ /= nod;
	denum_ /= nod;
	::exit(-1);   // пока так
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
Fraction Fraction::operator+(const Fraction& other)
{
	Integer numerator;
	Integer denominator;
	Fraction result;
	if (sign_ == false && other.sign_ == false)
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ = false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.denum_ - other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ = true;
	}
	else
	{
		numerator = num_ * other.denum_ - other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ = true;
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
		result.sign_ = false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ = true;
	}
	else
	{
		numerator = num_ * other.denum_ + other.num_ * denum_;
		denominator = denum_ * other.denum_;
		result.sign_ = true;
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
		result.sign_ = false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.num_;
		denominator = denum_ * other.denum_;
		result.sign_ = true;
	}
	else
	{
		numerator = num_ * other.num_;
		denominator = denum_ * other.denum_;
		result.sign_ = true;
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
		result.sign_ = false;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		numerator = num_ * other.denum_;
		denominator = denum_ * other.num_;
		result.sign_ = true;
	}
	else
	{
		numerator = num_ * other.denum_;
		denominator = denum_ * other.num_;
		result.sign_ = true;
	}
	result.num_ = numerator;
	result.denum_ = denominator;

	return result;
}


// Операторы сравнения
bool Fraction::operator==(const Fraction& other) const
{
	if (sign_ == other.sign_)
	{
		return num_ == other.num_ && denum_ == other.denum_;
	}
	return false;

}

bool Fraction::operator!=(const Fraction& other) const
{
	if (sign_ == other.sign_)
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
	}
	return false;
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
Fraction Fraction::operator+=(Fraction& other)
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

Fraction Fraction::operator-=(Fraction& other)
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

Fraction Fraction::operator*=(Fraction& other)
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

Fraction Fraction::operator/=(Fraction& other)
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



// оператор вывода
std::ostream& operator<<(std::ostream &out, const Fraction &obj)
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
