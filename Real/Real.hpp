#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"

class Real
{
public:

	// constructors
    Real() : Real(Integer(), Fraction()) {}
    Real(const Integer& units, const Fraction& fractional);
    Real(const Fraction& obj);
    Real(const char*);
    Real(double);
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



    // поля класса
private:

    Integer units_;
    Fraction fractional_;
};