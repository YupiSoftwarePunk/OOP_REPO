#pragma once

#include <iostream>
#include <numeric>
class Integer
{
public:

	// constructors (конструктор по умолчанию и  конструкторы с параметрами)
	Integer();
	Integer(bool sign, unsigned units);
	Integer(int number);


	// сеттеры и геттеры

	//setters
	void SetSign(bool sign);
	void SetUnits(unsigned units);


	// getters
	bool GetSign();
	unsigned GetUnits();



	// number check (проверка числа)

	// проверка на четность
	bool isOdd()const;

	// проверка на положительность
	bool isPositive()const;

	// проверка является ли число простым
	bool isSimple()const;

	// проверка являются ли числа взаимнопростыми
	bool isCoprime(Integer other)const;

	// нахождение наибольшего общего делителя
	int Nod(Integer other)const;

	// нахождение наибольшего общего кратного
	int Nok(Integer other)const;


	// Арифметические операторы  

	// Сумма
	friend Integer operator+(const Integer& a, const Integer& b);

	// Разность
	friend Integer operator-(const Integer& a, const Integer& b);

	// Произведение
	friend Integer operator*(const Integer& a, const Integer& b);

	// Частное
	friend Integer operator/(const Integer& a, const Integer& b);

	// Деление по модулю
	friend Integer operator%(const Integer& a, const Integer& b);



	// Операторы присваивания
	Integer& operator+=(Integer other);

	Integer& operator-=(Integer other);

	Integer& operator*=(Integer other);

	Integer& operator/=(Integer other);



	// операторы инкремент и декремент

	// постфиксные инкремент и декремент

	// постфиксный инкремент
	Integer operator++(int);

	// постфиксный декремент
	Integer operator--(int);


	// префиксные инкремент и декремент

	// префиксный инкремент
	Integer operator++();

	// префиксный декремент
	Integer operator--();



	//Операторы сравнения

	bool operator==(Integer other) const;

	bool operator!=(Integer other) const;

	bool operator<(Integer other) const;

	bool operator>(Integer other) const;

	bool operator<=(Integer other) const;

	bool operator>= (Integer other) const;


	// Унарные операторы

	//Унарный плюс
	Integer operator+();

	// Унарный минуc
	Integer operator-();



	// Оператор вывода
	friend std::ostream& operator<<(std::ostream& out, const Integer& other);


	// поля класса
private:
	bool sign_;
	unsigned units_;

};
