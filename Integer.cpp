#include "Integer.hpp"

//constructors(конструктор по умолчанию и  конструкторы с параметрами)
Integer::Integer() :Integer(false, 0u) {}
Integer::Integer(bool sign, unsigned units) :sign_(sign), units_(units) {}
Integer::Integer(int number)
{
	if (number < 0)
	{
		sign_ = true;
		units_ = ::abs(number);
	}
	else
	{
		sign_ = false;
		units_ = static_cast <unsigned> (number);
	}
}


// setters and getters

//setters
void Integer::SetSign(bool sign)
{
	this->sign_ = sign;
}

void Integer::SetUnits(unsigned units)
{
	this->units_ = units;
}

// getters
bool Integer::GetSign()
{
	return sign_;
}

unsigned Integer::GetUnits()
{
	return units_;
}



// number check (проверка числа)

// проверка на четность
bool Integer::isOdd()const
{
	return units_ % 2 == 0;
}

// проверка на положительность
bool Integer::isPositive()const
{
	return sign_ < 1;
}

// проверка является ли число простым
bool Integer::isSimple()const
{
	if (units_ < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= units_; i++)
	{
		if (units_ % i == 0)
		{
			return false;
		}
	}
	return true;
}

// проверка являются ли числа взаимнопростыми
bool Integer::isCoprime(Integer other)const
{
	return std::gcd(units_, other.units_) == 1;
}

// нахождение наибольшего общего делителя
int Integer::Nod(Integer other)const
{
	return std::gcd(units_, other.units_);
}

// нахождение наибольшего общего кратного
int Integer::Nok(Integer other)const
{
	return std::lcm(units_, other.units_);
}



// operators

// Арифметические операторы  

// Сумма
Integer operator+(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
		result.units_ = a.units_ + b.units_;
	}
	else
	{
		if (a.units_ > b.units_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.units_ - b.units_;
		}
		else if (a.units_ < b.units_)
		{
			result.sign_ = b.sign_;
			result.units_ = b.units_ - a.units_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	return result;
}

// Разность
Integer operator-(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
		result.units_ = a.sign_ - b.sign_;
	}
	else
	{
		if (a.sign_ > b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.units_ + b.units_;
		}
		else if (a.sign_ < b.sign_)
		{
			result.sign_ = b.sign_;
			result.units_ = b.units_ + a.units_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	return result;
}

// Произведение
Integer operator*(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
	}
	else
	{
		if (a.sign_ > b.sign_)
		{
			result.sign_ = a.sign_;
		}
		else if (a.sign_ < b.sign_)
		{
			result.sign_ = b.sign_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	result.units_ = a.units_ * b.units_;
	return result;
}

// Частное
Integer operator/(const Integer& a, const Integer& b)
{
	if (b == 0)
	{
		std::cout << "Ошибка!! Деление на 0 запрещено!!\n\n";
		::exit(-1);		// принудетельное завершение программы (1 способ)
		//throw - 1;	// принудетельное завершение программы (2 способ)
	}

	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
		result.units_ = a.units_ / b.units_;
	}
	else
	{
		if (a.sign_ > b.sign_)
		{
			result.sign_ = a.sign_;

			result.units_ = a.units_ / b.units_;
		}
		else if (a.sign_ < b.sign_)
		{
			result.sign_ = b.sign_;
			result.units_ = b.units_ / a.units_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	return result;
}

// Деление по модулю
Integer operator%(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
		result.units_ = a.units_ % b.units_;
	}
	else
	{
		if (a.sign_ > b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.sign_ % b.sign_;
		}
		else if (a.sign_ < b.sign_)
		{
			result.sign_ = b.sign_;
			result.units_ = b.sign_ % a.sign_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	return result;
}



// Операторы присваивания
Integer& Integer::operator+=(Integer other)
{

	if (sign_ == other.sign_)
	{
		sign_ = sign_;
		units_ += other.units_;
	}
	else
	{
		if (sign_ > other.sign_)
		{
			sign_ = sign_;
			units_ -= other.units_;
		}
		else if (sign_ < other.sign_)
		{
			sign_ = other.sign_;
			other.sign_ -= units_;
		}
		else
		{
			sign_ = false;
			units_ = 0;
		}
	}
	return *this;
}

Integer& Integer::operator-=(Integer other)
{
	if (sign_ == other.sign_)
	{
		sign_ = sign_;
		units_ -= other.units_;
	}
	else
	{
		if (sign_ > other.sign_)
		{
			sign_ = sign_;
			units_ += other.units_;
		}
		else if (sign_ < other.sign_)
		{
			sign_ = other.sign_;
			other.sign_ += units_;
		}
		else
		{
			sign_ = false;
			units_ = 0;
		}
	}
	return *this;
}

Integer& Integer::operator*=(Integer other)
{
	if (sign_ == other.sign_)
	{
		sign_ = sign_;
		units_ *= other.units_;
	}
	else
	{
		if (sign_ > other.sign_)
		{
			sign_ = sign_;
			units_ *= other.units_;
		}
		else if (sign_ < other.sign_)
		{
			sign_ = other.sign_;
			other.sign_ *= units_;
		}
		else
		{
			sign_ = false;
			units_ = 0;
		}
	}
	return *this;
}

Integer& Integer::operator/=(Integer other)
{
	if (other.units_ == 0)
	{
		std::cout << "Ошибка!! Деление на 0 запрещено!!\n\n";
		::exit(-1);
	}
	if (sign_ == other.sign_)
	{
		sign_ = sign_;
		units_ /= other.units_;
	}
	else
	{
		if (sign_ > other.sign_)
		{
			sign_ = sign_;
			units_ /= other.units_;
		}
		else if (sign_ < other.sign_)
		{
			sign_ = other.sign_;
			other.sign_ /= units_;
		}
		else
		{
			sign_ = false;
			units_ = 0;
		}
	}
	return *this;
}



// операторы инкремент и декремент

// постфиксные инкремент и декремент

// постфиксный инкремент
Integer Integer::operator++(int)
{
	if (sign_ == true)
	{
		units_++;
	}
	else
	{
		units_--;
	}
	return units_;
}

// постфиксный декремент
Integer Integer::operator--(int)
{
	if (sign_ == true)
	{
		units_--;
	}
	else
	{
		units_++;
	}
	return units_;
}

// префиксные инкремент и декремент


// префиксный инкремент
Integer Integer::operator++()
{
	if (sign_ == true)
	{
		++(units_);
	}
	else
	{
		--(units_);
	}
	return units_;
}

// префиксный декремент
Integer Integer::operator--()
{
	if (sign_ == true)
	{
		--(units_);
	}
	else
	{
		++(units_);
	}
	return units_;
}



//Операторы сравнения

bool Integer::operator==(Integer other) const
{
	if (sign_ == other.sign_)
	{
		return units_ == other.units_;
	}
	return false;
}

bool Integer::operator!=(Integer other) const
{
	if (sign_ == other.sign_)
	{
		return units_ != other.units_;
	}
	return true;
}

bool Integer::operator<(Integer other) const
{
	if (sign_ == other.sign_)
	{
		return units_ < other.units_;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		return false;
	}
	return true;
}

bool Integer::operator>(Integer other) const
{
	if (sign_ == other.sign_)
	{
		return units_ > other.units_;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		return true;
	}
	return false;
}

bool Integer::operator<=(Integer other) const
{
	if (sign_ == other.sign_)
	{
		return units_ <= other.units_;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		return false;
	}
	return true;
}

bool Integer::operator>= (Integer other) const
{
	if (sign_ == other.sign_)
	{
		return units_ >= other.units_;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		return true;
	}
	return false;
}


// Унарные операторы

//Унарный плюс
// + -> +
// - -> -

Integer Integer::operator+()
{
	return units_;
}


// Унарный минус
// - -> +
// + -> -

Integer Integer::operator-()
{
	Integer res = { *this };
	if (sign_ == true)
	{
		res.sign_ = false;
	}
	else
	{
		res.sign_ = true;
	}
	return res;
}



// Оператор вывода
std::ostream& operator<<(std::ostream& out, const Integer& other)
{
	if (other.sign_ == true)
	{
		out << '-' << other.units_;
	}
	else
	{
		out << other.units_;
	}
	return out;
}
