#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"


#include <iostream>
#include <type_traits>
#include <numeric>
#include <initializer_list>


// ��������� ������
// ������ ������������� �������

// ��� ��������� ����� �������, ������� ������ ����� �������� ������ � ������ �������
// � �������� �������� �����. ��� ����� ��� ���� ������� ���� assert �������,
// ������������� �������� ��� constraint ��������. ����� �� ���� �������� ����� ���������� ������� ���������� ������ �������.

template<typename Type, unsigned long long Coll, unsigned long long Row>

class Matrix
{
public:
	Matrix();
	Matrix(/* ����� ����������, ������� ���� ����� �������� */);
	Matrix(const Matrix& other);
	Matrix(Matrix&& dead);
	~Matrix();

	const Matrix& operator= (const Matrix& other);
	const Matrix& operator= (Matrix&& other);

	// operator[][]  ������� ��� ��������������
	//  ��� �� ���� ������ ���� �������� ����� at


	// �������������� ���������
	friend const Matrix& operator+ (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator- (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator* (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator/ (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator^ (const Matrix& lso, const Integer& rso);


	// ������������� ���������
	friend const Matrix& operator+= (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator-= (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator*= (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator/= (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator^= (const Matrix& lso, const Integer& rso);


	// ������������� ���������
	friend const bool operator== (const Matrix& lso, const Matrix& rso);
	friend const bool operator!= (const Matrix& lso, const Matrix& rso);
	friend const bool operator> (const Matrix& lso, const Matrix& rso);
	friend const bool operator< (const Matrix& lso, const Matrix& rso);
	friend const bool operator<= (const Matrix& lso, const Matrix& rso);
	friend const bool operator>= (const Matrix& lso, const Matrix& rso);
	friend const bool operator^= (const Matrix& lso, const Matrix& rso);
	friend const bool operator=^ (const Matrix& lso, const Matrix& rso);


	// �������� []
	Type& operator[] (unsigned long long Coll, unsigned long long Row);


	// �������� at
	Type& at(unsigned long long Coll, unsigned long long Row);


	// ��������� ����� � ������
	friend std::ostream& opeartor<<(std::ostream & outs, const Matrix & rso);
	friend std::istream& opeartor>>(std::istream & ins, const Matrix & rso);

	// �����-�� �� ���������� ���� �����, � ��������� ��� � ����� ��� ����������

	// ����� ������ ��� ��������� ������������ �������
	// ���������������� ������� ��� ��������������� ��� � ���




private:
	Type data_[Coll][Row];
};

namespace std
{
	template<typename Type, unsigned long long Coll, unsigned long long Row>
	struct hash<Matrix<Type, Coll, Row>>
	{
		size_t operator()(Matrix<Type, unsigned long long, unsigned long long>& obj) {
			size_t result{};
			for (size_t i = 0; i < obj.rows(); i++) {
				for (size_t j = 0; j < obj.columns(); j++) {
					result <<= 1;
					result ^= hash<Type>()(obj[i][j]);
				}
			}
			return result;
		}
	};
}