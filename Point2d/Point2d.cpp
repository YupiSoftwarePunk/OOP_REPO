#include "Point2d.hpp"

// setters
void Point2d::SetNum1(const Real num1)
{
	this->num1_ = num1;
}

void Point2d::SetNum2(const Real num2)
{
	this->num2_ = num2;
}


// getters
Real Point2d::GetNum1()
{
	return num1_;
}

Real Point2d::GetNum2()
{
	return num2_;
}



// —равнительный оператор 
bool operator==(const Point2d& num1, const Point2d& num2)
{
    return (num1.num1_ == num2.num1_) && (num1.num2_ == num2.num2_);
}


//проверка одинаковости двух точек 
bool Point2d::IsEqualPoints(const Point2d& other)
{
	return *this == other;
}



// –асчет рассто€ни€ между точками
Real DistanceBetweenPoints(const Point2d& x, const Point2d& y)
{
	Real x1 = x.num2_ - x.num1_;
	Real y1 = y.num2_ - y.num1_;

    Real result = x1 * x1 + y1 * y1;

    return Point2d::MySqrt(result);
}



Real Point2d::MySqrt(Real& number)
{
    return ::sqrt(number.ToDouble());
}




// ќператор вывода
std::ostream& operator<<(std::ostream& out, const Point2d& obj)
{
	return out << obj.num1_ << " " << obj.num2_;
}


// ќператор ввода
std::istream& operator>>(std::istream& in, Point2d& obj)  
{
	std::string input;
	in >> input;

	// перва€ часть числа
	int bracketPos1 = input.find('(');
	int slashPos1 = input.find('/');
	int bracketPos2 = input.find(')');

	// втора€ часть числа
	int bracketPos3 = input.find('(', bracketPos1 + 1);
	int slashPos2 = input.find('/', slashPos1 + 1);
	int bracketPos4 = input.find(')', bracketPos2 + 1);

	Real num1;
	Real num2;

	Integer units = 0;
	Integer fractionalNum = 0;
	Integer fractionalDenum = 0;
	Fraction fractional;

	Integer units2 = 0;
	Integer fractionalNum2 = 0;
	Integer fractionalDenum2 = 0;
	Fraction fractional2;

	bool sign = false;
	bool sign2 = false;

	int startPos = 0;


	// перва€ часть числа
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
			units = units * 10 + (input[i] - '0');
		}
	}

	for (int i = bracketPos1 + 1; i < slashPos1; i++)   
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

	for (int i = slashPos1 + 1; i < bracketPos2; i++)   
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


	// втора€ часть числа
	int startPos2 = bracketPos2 + 1;

	if (input.size() > startPos2 && input[startPos2] == '-')
	{
		sign2 = true;
		startPos2++;
	}


	for (int i = startPos2; i < bracketPos3; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			units2 = units2 * 10 + (input[i] - '0');
		}
	}

	for (int i = bracketPos3 + 1; i < slashPos2; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			fractionalNum2 = fractionalNum2 * 10 + (input[i] - '0');
		}
	}

	for (int i = slashPos2 + 1; i < bracketPos4; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			fractionalDenum2 = fractionalDenum2 * 10 + (input[i] - '0');
		}
	}

	// перва€ часть числа
	units.SetSign(sign);

	fractional.SetNumerator(fractionalNum);
	fractional.SetDenominator(fractionalDenum);

	num1.SetUnits(units);
	num1.SetFractional(fractional);


	// втора€ часть числа
	units2.SetSign(sign2);

	fractional2.SetNumerator(fractionalNum2);
	fractional2.SetDenominator(fractionalDenum2);

	num2.SetUnits(units2);         
	num2.SetFractional(fractional2);

	obj.num1_ = num1;
	obj.num2_ = num2;


	return in;
}
