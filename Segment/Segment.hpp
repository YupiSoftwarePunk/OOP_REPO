#pragma once

#include "../Point2d/Point2d.hpp"

class Segment
{
public:

	// ������������
	Segment(Point2d pointer1, Point2d pointer2) : pointer1_(std::make_shared<Point2d>(pointer1)), pointer2_(std::make_shared<Point2d>(pointer2)) {}
	Segment() : pointer1_(nullptr), pointer2_(nullptr) {}

	// ����������� �����������
	Segment(const Segment& other) : pointer1_(other.pointer1_), pointer2_(other.pointer2_) {}

	// ����������� ������������
	Segment& operator=(const Segment& other)
	{
		if (this != &other)
		{
			pointer1_ = other.pointer1_;
			pointer2_ = other.pointer2_;
			return *this;
		}
	}


	// �������
	void SetPoiner1(std::shared_ptr<Point2d> pointer1);
	void SetPoiner2(std::shared_ptr<Point2d> pointer2);


	// ������� ���������
	std::shared_ptr<Point2d> GetPointer1();
	std::shared_ptr<Point2d> GetPointer2();


	// ������� ��������
	Point2d& GetPointer1Ref();
	Point2d& GetPointer2Ref();


	// ��������� �������� �� �����
	friend bool operator>(const Segment& num1, const Segment& num2);
	friend bool operator<(const Segment& num1, const Segment& num2);
	friend bool operator>=(const Segment& num1, const Segment& num2);
	friend bool operator<=(const Segment& num1, const Segment& num2);
	friend bool operator==(const Segment& num1, const Segment& num2);
	friend bool operator!=(const Segment& num1, const Segment& num2);


	// �������� �� ������������
	bool IsEqualSegments(const Segment& other);


	// �������� �� ����������� ��������
	bool IsSegmentsCrossed(const Segment& other);


	//  ��������� ����� �����
	friend Real GetSegmentDistance(const Point2d& num1, const Point2d& num2);


	// ��������������� ������ ��� ���������� ����������� ��������
	friend Real GetMax(const Real& num1, const Real& num2);
	friend Real GetMin(const Real& num1, const Real& num2);


	// �������� ������
	friend std::ostream& operator<< (std::ostream& out, const Segment obj);


	// ����
private:
	std::shared_ptr<Point2d> pointer1_;
	std::shared_ptr<Point2d> pointer2_;

};

