#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"


//  ласс точки
// ƒанный класс хранит координаты одной точки в пространстве (реализован на дес€тичных дроб€х)
class Point2d
{
public:

	// конструкторы
	Point2d(Real num1, Real num2) : num1_(num1), num2_(num2) {}
	Point2d() : Point2d(Real(0 / 1), Real(0 / 1)) {}

	// деструктор
	virtual ~Point2d() = default;


	// setters
	void SetNum1(const Real num1);
	void SetNum2(const Real num2);

	// getters
	Real GetNum1();
	Real GetNum2();

 

	// —равнительный оператор 
	friend bool operator==(const Point2d& num1, const Point2d& num2);


	// проверка одинаковости двух точек
	bool IsEqualPoints(const Point2d& other);


	// –асчет рассто€ни€ между точками
	friend Real DistanceBetweenPoints(const Point2d& x, const Point2d& y);



	// –асчет корн€ - дл€ формулы нахождени€ рассто€ни€ между точками
	static Real MySqrt(Real& number);



	// ќператор ввода и вывода
	friend std::ostream& operator<< (std::ostream& out, const Point2d& obj);

	friend std::istream& operator>> (std::istream& in, Point2d& obj);

private:

	// пол€
	Real num1_;
	Real num2_;
};