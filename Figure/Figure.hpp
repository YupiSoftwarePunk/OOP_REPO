#pragma once

#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"


class Figure
{

};



//#include <iostream>
//
//// virtual �������� ����������� ������� �����, ��������� �� ��������� ���� ���������� ����� ����� ����� ������� � ������ ������
//// ���� ������������ ����� �����������, �� � �������� ������ ����� ������������
//class Base
//{
//public:
//	virtual void Print() const
//	{
//		std::cout << "Hey, 111 apple\n";
//	}
//
//	virtual ~Base() {}   ����� ���� ����� ����� ��������� �������� ����� ���������� ������
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
//// ��������� �� �������� ����������
//__interface FigureImposter  // ���������
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
//	������� ����� ������� ��� 3 ����� ��� 3 �������
//	���� �������� ��������, �� ����� ����� ��������� �������� ������ ��������� ����� ����� �������
//
//	������ Point2d / Segment
//	*/
//
//public:
//
//
//private:
//	std::vector<Point2d> points_;   // - ��� ����� ������� �����
//	std::array<Point2d, 3> points2_;  // - ��� ����� ������� �����
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

