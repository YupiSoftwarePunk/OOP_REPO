#include "Fraction.hpp"


// constructors
Fraction::Fraction() : Fraction(false, Integer(1)) {}
Fraction::Fraction(bool sign, Integer num) :sign_(sign), num_(num) {}
Fraction::Fraction(Integer number)
{
	if (number < 0)
	{
		sign_ = true;
		this->num_ = number;
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
void Fraction::SetSignNum(bool sign)
{
	this->signNum_ = sign;
}

void Fraction::SetSignDenum(bool sign)
{
	this->signDenum_ = sign;
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
bool Fraction::GetSignNum()
{
	return signNum_;
}

bool Fraction::GetSignDenum()
{
	return signDenum_;
}

Integer Fraction::GetNumerator()
{
	return num_;
}

Integer Fraction::GetDenominator()
{
	return denum_;
}


// // Проверка дроби
bool Fraction::isNumPositive() const
{
	return signNum_ < 1 && signDenum_ < 1;
}

bool Fraction::isProper() const
{
	return num_ < denum_;
}

bool Fraction::isSame() const
{
	return num_ == denum_ && signNum_ == signDenum_;
}