#pragma once

#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"


#include <iostream>
#include <type_traits>
#include <numeric>
#include <initializer_list>


// ������ ������������� �������

// ��� ��������� ����� �������, ������� ������ ����� �������� ������ � ������ �������
// � �������� �������� �����. ��� ����� ��� ���� ������� ���� assert �������,
// ������������� �������� ��� constraint ��������. ����� �� ���� �������� ����� ���������� ������� ���������� ������ �������.

template<typename Type, unsigned long long Row, unsigned long long Coll>

class Matrix
{
public:
	// ������������
	Matrix();
	Matrix(const Matrix& other);
	Matrix(Matrix&& other) noexcept;  // ����������� ��������

	// ����������
	~Matrix();


	const Matrix& operator= (const Matrix& other);  // ����������� ������������ �����������
	const Matrix& operator= (Matrix&& other);   // ����������� ��������


	// ������ ������� � �����
	unsigned long long collSize() const;
	unsigned long long rowSize() const;



	// �������������� ���������
	friend const Matrix& operator+ (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator- (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator* (const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator* (const Matrix& lso, int num);
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
	friend const bool operator>= (const Matrix& lso, const Matrix& rso);
	friend const bool operator<= (const Matrix& lso, const Matrix& rso);


	// �������� [] - ��������� ������ 1 ��������, � ��� ����� 2, ������� ��� �������� ()
	Type& operator() (unsigned long long row, unsigned long long �oll);
	const Type& operator() (unsigned long long row, unsigned long long �oll) const;


	// �������� at
	Type& at(unsigned long long row, unsigned long long �oll);
	const Type& at(unsigned long long row, unsigned long long �oll) const;


	// ��������� ����� � ������
	friend std::ostream& opeartor<<(std::ostream & outs, const Matrix & rso);
	friend std::istream& opeartor>>(std::istream & ins, const Matrix & rso);


private:

	// ����
	Type data_[Row][Coll];
};



namespace std
{
	template<typename Type, unsigned long long Row, unsigned long long Coll>
	struct hash<Matrix<Type, Row, Coll>>
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