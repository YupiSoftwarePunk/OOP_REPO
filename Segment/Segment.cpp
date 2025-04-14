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

bool Segment::IsSegmentsCrossed(const Segment& other)
{
	Point2d p1 = *pointer1_;
	Point2d p2 = *pointer2_;

	Point2d p3 = *(other.pointer1_);
	Point2d p4 = *(other.pointer2_);


	auto orientation = [](const Point2d& a, const Point2d& b, const Point2d& c) 
	{
		double orientation = (b.num2_ - a.num2_) * (c.num1_ - b.num1_) - (b.num1_ - a.num1_) * (c.num2_ - b.num2_);

		if (orientation == 0)
		{
			return 0;
		} 
		else 
		{
			return (orientation > 0) ? 1 : 2;
		}
	};


	auto onSegment = [](const Point2d& p, const Point2d& q, const Point2d& r) 
	{
		return q.num1_ <= std::max(p.num1_, r.num1_) && q.num1_ >= std::min(p.num1_, r.num1_) &&
			q.num2_ <= std::max(p.num2_, r.num2_) && q.num2_ >= std::min(p.num2_, r.num2_);
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