#include "Fraction.hpp"


// constructors
Fraction::Fraction() : Fraction(Integer(0), Integer(1)) {}
Fraction::Fraction(Integer num, Integer denum) :num_(num), denum_(denum)
{
	if (denum == 0)
	{
		throw std::invalid_argument("\nЗнаменатель не может быть равен нулю!!\n");
	}
}
Fraction::Fraction(const Integer& number)
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
	num_.SetSign(sign);
	denum_.SetSign(sign);
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
	return num_.GetSign() != denum_.GetSign();
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
	return num_.isPositive() == denum_.isPositive();
}

bool Fraction::isNumNegative() const
{
	return num_.isPositive() != denum_.isPositive();
}

bool Fraction::isProper() const
{
	return num_ < denum_;
}

bool Fraction::isImProper() const
{
	return num_ > denum_;
}

bool Fraction::isSame(const Fraction& other) const     
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
	Integer nod = num_.Gcd(denum_);
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
	units = this->num_ % this->denum_;
	return units;
}

Integer Fraction::CountRemainder()const
{
	Integer remainder = this->num_ % this->denum_;
	return remainder;
}


// Арифметические операции
Fraction Fraction::operator+(const Fraction& other) const
{
	Fraction result;

	result.denum_ = denum_ * other.denum_;
	result.num_ = num_ * other.denum_ + other.num_ * denum_;

	return result.ReduceFraction();
}

Fraction Fraction::operator-(const Fraction& other) const
{
	Fraction result;

	if ((num_ * other.denum_) > (other.num_ * denum_))
	{
		result.num_ = (num_ * other.denum_) - (other.num_ * denum_);
	}
	else
	{
		result.num_ = (other.num_ * denum_) - (num_ * other.denum_);
	}
	result.denum_ = denum_ * other.denum_;

	return result;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction result;

	result.denum_ = denum_ * other.denum_;
	result.num_ = num_ * other.num_;

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

	result.denum_ = denum_ * other.num_;
	result.num_ = num_ * other.denum_;

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


// Операторы присваивания
void Fraction::operator+=(const Fraction& other)
{
	*this = *this + other;
}

void Fraction::operator-=(const Fraction& other)
{
	*this = *this - other;
}

void Fraction::operator*=(const Fraction& other)
{
	*this = *this * other;
}

void Fraction::operator/=(const Fraction& other)
{
	*this = *this / other;
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

Fraction Fraction::operator-() const
{
	Fraction res = { *this };
	res.sign_ = !sign_;
	res.num_ = num_;
	res.denum_ = denum_;
	return res;
}



long double Fraction::fractionToDouble()
{
	long double numerator = num_.integerToDouble();
	long double denominator = denum_.integerToDouble();

	long double result = numerator / denominator;

	if (GetSign())
	{
		result = -result;
	}

	return result;
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


// оператор ввода
std::istream& operator>>(std::istream& in, Fraction& obj)
{
	std::string input;
	in >> input;

	int slashPos = input.find('/');
	Integer num = 0;
	Integer denum = 0;


	bool sign = false;
	int startPos = 0;

	if (!input.empty() && input[0] == '-')
	{
		sign = true;
		startPos = 1;
	}


	for (int i = startPos; i < slashPos; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			num = num * 10 + (input[i] - '0');
		}
	}

	for (int i = slashPos + 1; i < input.size(); i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			denum = denum * 10 + (input[i] - '0');
		}
	}

	obj.num_ = num;
	obj.denum_ = denum;
	obj.sign_ = sign;

	return in;
}
