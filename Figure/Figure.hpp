#pragma once

#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"


class Figure
{

};



//#include <iostream>
//
//// virtual включает виртуальную таблицу типов, позволяет за пределами кода определять какой метод нужно вызвать в данном случае
//// если родительский класс виртуальный, то и дочерние классы будут виртуальными
//class Base
//{
//public:
//	virtual void Print() const
//	{
//		std::cout << "Hey, 111 apple\n";
//	}
//
//	virtual ~Base() {}   через этот класс можно управлять временем жизни наследника класса
//
//private:
//
//
//};
//
//
//class Derived : public Base
//{
//public:
//	void Print() const override
//	{
//		std::cout << "Hey, apple\n";
//	}
//
//private:
//
//
//};
//
//void Print(const Base& obj)
//{
//	obj.Print();
//}
//
//// интерфейс не содержит реализацию
//__interface FigureImposter  // интерфейс
//{
//public:
//	Real Square();
//	Real Perimetr();
//	Point2d Center();
//};
//
//class Figure
//{
//public:
//	virtual Real Square() = 0;
//	virtual Real Perimetr() = 0;
//	virtual Point2d Center() = 0;
//};
//
//class Triangle : public Figure
//{
//	/* 
//	отрезки можно хранить как 3 точки или 3 отрезка
//	если хранятся точкамим, то нужно юудет регулярно вызывать методы получения длины между точками
//
//	классы Point2d / Segment
//	*/
//
//public:
//
//
//private:
//	std::vector<Point2d> points_;   // - так можно хранить точки
//	std::array<Point2d, 3> points2_;  // - так можно хранить точки
//};
//
//
//int main()
//{
//	Base base;
//	Derived derived;
//
//	Print(base);
//	Print(derived);
//
//	/*base.Print();
//	derived.Print();*/
//
//	return 0;
//}

