#pragma once

#include "../Point2d/Point2d.hpp"

class Segment
{
public:

	// конструкторы
	Segment(Point2d pointer1, Point2d pointer2) : pointer1_(std::make_shared<Point2d>(pointer1)), pointer2_(std::make_shared<Point2d>(pointer2)) {}
	Segment() : pointer1_(nullptr), pointer2_(nullptr) {}

	// конструктор копирования
	Segment(const Segment& other) : pointer1_(other.pointer1_), pointer2_(other.pointer2_) {}

	// конструктор присваивания
	Segment& operator=(const Segment& other)
	{
		if (this != &other)
		{
			pointer1_ = other.pointer1_;
			pointer2_ = other.pointer2_;
			return *this;
		}
	}


	// сеттеры
	void SetPoiner1(std::shared_ptr<Point2d> pointer1);
	void SetPoiner2(std::shared_ptr<Point2d> pointer2);


	// геттеры указателя
	std::shared_ptr<Point2d> GetPointer1();
	std::shared_ptr<Point2d> GetPointer2();


	// геттеры значений
	Point2d& GetPointer1Ref();
	Point2d& GetPointer2Ref();


	// сравнение отрезков по длине
	friend bool operator>(const Segment& num1, const Segment& num2);
	friend bool operator<(const Segment& num1, const Segment& num2);
	friend bool operator>=(const Segment& num1, const Segment& num2);
	friend bool operator<=(const Segment& num1, const Segment& num2);
	friend bool operator==(const Segment& num1, const Segment& num2);
	friend bool operator!=(const Segment& num1, const Segment& num2);


	// проверка на одинаковость
	bool IsEqualSegments(const Segment& other);


	// проверка на пересечение отрезков
	bool IsSegmentsCrossed(const Segment& other);


	//  сообщение своей длины
	friend Real GetSegmentDistance(const Point2d& num1, const Point2d& num2);


	// вспомогательные методы для нахождения пересечения отрезков
	friend Real GetMax(const Real& num1, const Real& num2);
	friend Real GetMin(const Real& num1, const Real& num2);


	// оператор вывода
	friend std::ostream& operator<< (std::ostream& out, const Segment obj);


	// поля
private:
	std::shared_ptr<Point2d> pointer1_;
	std::shared_ptr<Point2d> pointer2_;

};

