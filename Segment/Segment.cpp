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



// сравнение отрезков по длине
bool operator>(const Segment& num1, const Segment& num2)
{
	Segment difference1 = num2.pointer1_ - num1.pointer1_;
	Segment difference2 = num2.pointer2_ - num1.pointer2_;
	return difference1 > difference2;
}

bool operator<(const Segment& num1, const Segment& num2)
{
	
}

bool operator>=(const Segment& num1, const Segment& num2)
{
	
}

bool operator<=(const Segment& num1, const Segment& num2)
{
	
}

bool operator==(const Segment& num1, const Segment& num2)
{
	
}

bool operator!=(const Segment& num1, const Segment& num2)
{

}


// арифметические операторы 
bool operator-(const Segment& num1, const Segment& num2)
{
	
}
