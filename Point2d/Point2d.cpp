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
    /*if (number < Real(0)) 
    {
        throw std::invalid_argument("„исло должно быть положительным!");
    }

    if (number == Real(0)) 
    {
        return Real(0);
    }

    Real x = number;
    Real prev;

    do 
    {
        prev = x;
        x = Real(1 / 2) * (x + number / x); 

        if ((x - prev) < Real(0))
        {
            (x - prev) *= Real(-1);
        }

    } while ((x - prev) > Real(epsilon)); 

    return x;*/

    return ::sqrt(number.ToDouble());
}




std::ostream& operator<<(std::ostream& out, const Point2d obj)
{
	return out << obj.num1_ << " " << obj.num2_;
}

//std::istream& operator>>(std::istream& in, const Point2d obj)
//{
//	return in >> obj.num1_ >> " " >> obj.num2_;
//}
