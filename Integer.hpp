#pragma once

#include <iostream>
#include <numeric>
class Integer
{
public:

	// constructors (����������� �� ��������� �  ������������ � �����������)
	Integer();
	Integer(bool sign, unsigned units);
	Integer(int number);


	// ������� � �������

	//setters
	void SetSign(bool sign);

	void SetUnits(unsigned units);


	// getters
	bool GetSign();

	unsigned GetUnits();



	// number check (�������� �����)

	// �������� �� ��������
	bool isOdd()const;

	// �������� �� ���������������
	bool isPositive()const;

	// �������� �������� �� ����� �������
	bool isSimple()const;

	// �������� �������� �� ����� ���������������
	bool isCoprime(Integer other)const;

	// ���������� ����������� ������ ��������
	int Nod(Integer other)const;

	// ���������� ����������� ������ ��������
	int Nok(Integer other)const;



	// operators

	// �������������� ���������  

	// �����
	friend Integer operator+(const Integer& a, const Integer& b);

	// ��������
	friend Integer operator-(const Integer& a, const Integer& b);

	// ������������
	friend Integer operator*(const Integer& a, const Integer& b);

	// �������
	friend Integer operator/(const Integer& a, const Integer& b);

	// ������� �� ������
	friend Integer operator%(const Integer& a, const Integer& b);



	// ��������� ������������
	Integer& operator+=(Integer other);

	Integer& operator-=(Integer other);

	Integer& operator*=(Integer other);

	Integer& operator/=(Integer other);



	// ��������� ��������� � ���������

	// ����������� ��������� � ���������

	// ����������� ���������
	Integer operator++(int);

	// ����������� ���������
	Integer operator--(int);


	// ���������� ��������� � ���������

	// ���������� ���������
	Integer operator++();

	// ���������� ���������
	Integer operator--();



	//��������� ���������

	bool operator==(Integer other) const;

	bool operator!=(Integer other) const;

	bool operator<(Integer other) const;

	bool operator>(Integer other) const;

	bool operator<=(Integer other) const;

	bool operator>= (Integer other) const;


	// ������� ���������

	//������� ����
	// + -> +
	// - -> -

	Integer operator+();


	// ������� �����
	// - -> +
	// + -> -

	Integer operator-();



	// �������� ������
	friend std::ostream& operator<<(std::ostream& out, const Integer& other);


	// ���� ������
private:
	bool sign_;
	unsigned int units_;

};

