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
	std::shared_ptr<const Point2d> GetPointer1() const;

	std::shared_ptr<Point2d> GetPointer2();
	std::shared_ptr<const Point2d> GetPointer2() const;


	// ������� ��������
	Point2d& GetPointer1Ref();
	const Point2d& GetPointer1Ref() const;

	Point2d& GetPointer2Ref();
	const Point2d& GetPointer2Ref() const;


	// ����
private:
	std::shared_ptr<Point2d> pointer1_;
	std::shared_ptr<Point2d> pointer2_;

};

