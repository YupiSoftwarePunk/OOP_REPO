#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"

class Point2d
{
public:

	// ������������
	Point2d(Real num1, Real num2) : num1_(num1), num2_(num2) {}
	Point2d() : Point2d(Real(0 / 0), Real(0 / 0)) {}

	// ����������
	virtual ~Point2d() = default;


	// setters
	void SetNum1(const Real num1);
	void SetNum2(const Real num2);

	// getters
	Real GetNum1();
	Real GetNum2();

 

	// ������������� �������� 
	friend bool operator==(const Point2d& num1, const Point2d& num2);


	// �������� ������������ ���� �����
	bool IsEqualPoints(const Point2d& other);


	// ������ ���������� ����� �������
	friend Point2d DistanceBetweenPoints(const Point2d& x, const Point2d& y);



	// �������� ����� � ������
	friend std::ostream& operator<< (std::ostream& out, const Point2d obj);
	friend std::istream& operator>> (std::istream& in, const Point2d obj);

private:

	// ����
	Real num1_;
	Real num2_;
};