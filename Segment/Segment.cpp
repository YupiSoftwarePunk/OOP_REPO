#include "Segment.hpp"

// оператор вывода
std::ostream& operator<<(std::ostream& out, const Segment obj)
{
	return out << obj.pointer1_ << " " << obj.pointer2_;
}


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
std::shared_ptr<Point2d> Segment::GetPointer1()
{
	return pointer1_;
}

std::shared_ptr<Point2d> Segment::GetPointer2()
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
		Real orientation = (b.GetNum2() - a.GetNum2()) * (c.GetNum1() - b.GetNum1()) - (b.GetNum1() - a.GetNum1()) * (c.GetNum2() - b.GetNum2());

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