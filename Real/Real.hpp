#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"


// Класс десятичных дробей или дробей с целой частью
class Real
{
public:

	// constructors
    
    Real() : Real(Integer(), Fraction()) {}   
    Real(const Integer& units, const Fraction& fractional); 
    Real(const Fraction& obj);
    Real(long double obj);
    Real(Integer obj) : units_(obj), fractional_(Integer(1)) {};
    Real(
        int units,
        Fraction fractional) :
        units_(units),
        fractional_(fractional) {};
    Real(
        unsigned units,
        Fraction fractional) :
        units_(units),
        fractional_(fractional) {};


    long double ToDouble();


    // сеттеры и геттеры

    //setters
    void SetUnits(Integer units);
    void SetFractional(Fraction fractional);

    // getters
    Integer GetUnits();
    Fraction GetFractional();


    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const Real& obj);

    // Оператор ввода
    friend std::istream& operator>>(std::istream& in, Real& obj);


    // Проверки числа
    bool isDecimalPositive() const;

    bool isDecimalNegative() const;

    bool isDecimalSame(const Real& other) const;

    bool isDecimal() const;


    // Операторы

    // Арифметические операторы
    Real operator+(const Real& other) const;

    Real operator-(const Real& other) const;

    Real operator*(const Real& other) const;

    Real operator/(const Real& other) const;


    // Операторы сравнения
    bool operator<(const Real& other) const;

    bool operator>(const Real& other) const;

    bool operator<=(const Real& other) const;

    bool operator>=(const Real& other) const;

    bool operator==(const Real& other) const;

    bool operator!=(const Real& other) const;


    // Операторы присваивания
    Real& operator+=(const Real& other);

    Real& operator-=(const Real& other);

    Real& operator*=(const Real& other);

    Real& operator/=(const Real& other);


    // Унарные операторы
    Real operator+();
    Real operator-() const;



    // поля класса
private:

    Integer units_;
    Fraction fractional_;
};
