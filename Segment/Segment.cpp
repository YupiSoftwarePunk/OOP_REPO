#include "Segment.hpp"

// сеттеры
void Segment::SetPoiner1(std::shared_ptr<Point2d> pointer1)
{
	pointer1_ = pointer1;
}

void Segment::SetPoiner2(std::shared_ptr<Point2d> pointer2)
{
	pointer2_ = pointer2;
}


// геттеры указателя
std::shared_ptr<Point2d>& Segment::GetPointer1()
{
	return pointer1_;
}

std::shared_ptr<Point2d>& Segment::GetPointer2()
{
	return pointer2_;
}


// геттеры значений
Point2d& Segment::GetPointer1Ref()
{
	return *pointer1_;
}

Point2d& Segment::GetPointer2Ref()
{
	return *pointer2_;
}



// проверка на одинаковость
bool Segment::IsEqualSegments(const Segment& other)
{
	return *this == other;
}

Real GetMax(const Real& num1, const Real& num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

Real GetMin(const Real& num1, const Real& num2)
{
	if (num1 < num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


// проверка на пересечение отрезков
bool Segment::IsSegmentsCrossed(const Segment& other)
{
	Point2d p1 = *pointer1_;
	Point2d p2 = *pointer2_;

	Point2d p3 = *(other.pointer1_);
	Point2d p4 = *(other.pointer2_);


	auto orientation = [](Point2d& a, Point2d& b, Point2d& c)
		{
			Real orientation = (b.GetNum2() - a.GetNum2()) * 
				(c.GetNum1() - b.GetNum1()) - (b.GetNum1() - a.GetNum1()) * 
				(c.GetNum2() - b.GetNum2());

			if (orientation == Real(0))
			{
				return 0;
			}
			else
			{
				return (orientation > Real(0)) ? 1 : 2;
			}
		};


	auto onSegment = [](Point2d& p, Point2d& q, Point2d& r)
		{
			return
				q.GetNum1() <= GetMax(p.GetNum1(), r.GetNum1()) &&
				q.GetNum1() >= GetMin(p.GetNum1(), r.GetNum1()) &&
				q.GetNum2() <= GetMax(p.GetNum2(), r.GetNum2()) &&
				q.GetNum2() >= GetMin(p.GetNum2(), r.GetNum2());
		};


	int o1 = orientation(p1, p2, p3);
	int o2 = orientation(p1, p2, p4);
	int o3 = orientation(p3, p4, p1);
	int o4 = orientation(p3, p4, p2);

	if (o1 != o2 && o3 != o4)
	{
		return true;
	}


	if (o1 == 0 && onSegment(p1, p3, p2))
	{
		return true;
	}
	if (o2 == 0 && onSegment(p1, p4, p2))
	{
		return true;
	}
	if (o3 == 0 && onSegment(p3, p1, p4))
	{
		return true;
	}
	if (o4 == 0 && onSegment(p3, p2, p4))
	{
		return true;
	}
	else
	{
		return false;
	}

}







//  сообщение своей длины
Real GetSegmentDistance(const Point2d& num1, const Point2d& num2)
{
	return DistanceBetweenPoints(num1, num2);
}



// сравнение отрезков по длине
bool operator>(const Segment& num1, const Segment& num2)
{
	return GetSegmentDistance(*(num1.pointer1_), *(num1.pointer2_)) >
		GetSegmentDistance(*(num2.pointer1_), *(num2.pointer2_));
}


bool operator<(const Segment& num1, const Segment& num2)
{
	return GetSegmentDistance(*(num1.pointer1_), *(num1.pointer2_)) <
		GetSegmentDistance(*(num2.pointer1_), *(num2.pointer2_));
}


bool operator>=(const Segment& num1, const Segment& num2)
{
	return GetSegmentDistance(*(num1.pointer1_), *(num1.pointer2_)) >=
		GetSegmentDistance(*(num2.pointer1_), *(num2.pointer2_));
}


bool operator<=(const Segment& num1, const Segment& num2)
{
	return GetSegmentDistance(*(num1.pointer1_), *(num1.pointer2_)) <=
		GetSegmentDistance(*(num2.pointer1_), *(num2.pointer2_));
}


bool operator==(const Segment& num1, const Segment& num2)
{
	return GetSegmentDistance(*(num1.pointer1_), *(num1.pointer2_)) ==
		GetSegmentDistance(*(num2.pointer1_), *(num2.pointer2_));
}


bool operator!=(const Segment& num1, const Segment& num2)
{
	return GetSegmentDistance(*(num1.pointer1_), *(num1.pointer2_)) !=
		GetSegmentDistance(*(num2.pointer1_), *(num2.pointer2_));
}



// оператор вывода
std::ostream& operator<<(std::ostream& out, const Segment& obj)
{
	return out << *(obj.pointer1_) << " " << *(obj.pointer2_);
}


// оператор ввода
std::istream& operator>>(std::istream& in,  Segment& obj)
{
	std::string input;
	in >> input;



// первое число

	// первая часть числа
	int bracketPos1 = input.find('(');
	int slashPos1 = input.find('/');
	int bracketPos2 = input.find(')');

	// вторая часть числа
	int bracketPos3 = input.find('(', bracketPos1 + 1);
	int slashPos2 = input.find('/', slashPos1 + 1);
	int bracketPos4 = input.find(')', bracketPos2 + 1);



// второе число

	// первая часть числа
	int bracketPos5 = input.find('(', bracketPos3);
	int slashPos3 = input.find('/', slashPos2);
	int bracketPos6 = input.find(')', bracketPos4);

	// вторая часть числа
	int bracketPos7 = input.find('(', bracketPos5 + 1);
	int slashPos4 = input.find('/', slashPos3 + 1);
	int bracketPos8 = input.find(')', bracketPos6 + 1);



	// первое число
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

	Real num1;
	Real num2;

	Point2d p1;

	Segment s;



	// второе число
	Integer units3 = 0;
	Integer fractionalNum3 = 0;
	Integer fractionalDenum3 = 0;
	Fraction fractional3;

	Integer units4 = 0;
	Integer fractionalNum4 = 0;
	Integer fractionalDenum4 = 0;
	Fraction fractional4;

	bool sign3 = false;
	bool sign4 = false;

	Real num3;
	Real num4;

	Point2d p2;

	
	


	int startPos = 0;


	// первая часть числа
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


	// вторая часть числа
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



	// Второе число

	// Первая часть числа

	int startPos3 = bracketPos4 + 1;

	if (input.size() > startPos3 && input[startPos3] == '-')
	{
		sign3 = true;
		startPos3++;
	}


	for (int i = startPos3; i < bracketPos5; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			units3 = units3 * 10 + (input[i] - '0');
		}
	}

	for (int i = bracketPos5 + 1; i < slashPos3; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			fractionalNum3 = fractionalNum3 * 10 + (input[i] - '0');
		}
	}

	for (int i = slashPos3 + 1; i < bracketPos6; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			fractionalDenum3 = fractionalDenum3 * 10 + (input[i] - '0');
		}
	}


	// вторая часть числа

	int startPos4 = bracketPos6 + 1;

	if (input.size() > startPos4 && input[startPos4] == '-')
	{
		sign4 = true;
		startPos4++;
	}


	for (int i = startPos4; i < bracketPos7; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			units4 = units4 * 10 + (input[i] - '0');
		}
	}

	for (int i = bracketPos7 + 1; i < slashPos4; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			fractionalNum4 = fractionalNum4 * 10 + (input[i] - '0');
		}
	}

	for (int i = slashPos4 + 1; i < bracketPos8; i++)
	{
		if (!isdigit(input[i]))
		{
			break;
		}
		else
		{
			fractionalDenum4 = fractionalDenum4 * 10 + (input[i] - '0');
		}
	}





// Первое число

	// первая часть числа
	units.SetSign(sign);

	fractional.SetNumerator(fractionalNum);
	fractional.SetDenominator(fractionalDenum);

	num1.SetUnits(units);
	num1.SetFractional(fractional);


	// вторая часть числа
	units2.SetSign(sign2);

	fractional2.SetNumerator(fractionalNum2);
	fractional2.SetDenominator(fractionalDenum2);

	num2.SetUnits(units2);
	num2.SetFractional(fractional2);

	p1.SetNum1(num1);
	p1.SetNum2(num2);



// Второе число

	// первая часть числа
	units3.SetSign(sign3);

	fractional3.SetNumerator(fractionalNum3);
	fractional3.SetDenominator(fractionalDenum3);

	num3.SetUnits(units3);
	num3.SetFractional(fractional3);


	// вторая часть числа
	units4.SetSign(sign4);

	fractional4.SetNumerator(fractionalNum4);
	fractional4.SetDenominator(fractionalDenum4);

	num4.SetUnits(units4);
	num4.SetFractional(fractional4);



	p2.SetNum1(num3);
	p2.SetNum2(num4);

	obj.SetPoiner1(std::make_shared<Point2d>(p1));
	obj.SetPoiner2(std::make_shared<Point2d>(p2));


	return in;
}
