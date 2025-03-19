#include "../Matrix/Matrix.hpp"

// ������������
template<typename Type, unsigned long long Coll, unsigned long long Row>

Matrix<Type, Coll, Row>::Matrix()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[i][j] = Type{};
		}
	}
}


// ����������� �����������
template<typename Type, unsigned long long Coll, unsigned long long Row>

Matrix<Type, Coll, Row>::Matrix(const Matrix& other)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[i][j] = other.data_[i][j];
		}
	}
}


template<typename Type, unsigned long long Coll, unsigned long long Row>

Matrix<Type, Coll, Row>::Matrix(Matrix&& other) noexcept
{
	data_ = nullptr;
	std::swap(data_, other.data_);
}


// ����������� ������������ �����������
template<typename Type, unsigned long long Coll, unsigned long long Row>

const Matrix& Matrix<Type, Coll, Row>::operator=(const Matrix& other)
{
	if (this == &other)
	{
		return *this;
	}
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[i][j] = other.data_[i][j];
		}
	}

	return *this;
}


// ����������� ��������
template<typename Type, unsigned long long Coll, unsigned long long Row>

const Matrix& Matrix<Type, Coll, Row>::operator=(Matrix&& other)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[i][j] = other.data_[i][j];
		}
	}

	return *this;
}



// ����������
template<typename Type, unsigned long long Coll, unsigned long long Row>

Matrix<Type, Coll, Row>::~Matrix() = default;




// �������� ������
template<typename Type, unsigned long long Coll, unsigned long long Row>

std::ostream& opeartor << (std::ostream& outs, const Matrix& rso)
{
	/*for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			outs << rso[i][j] << " ";
		}
		outs << "\n";
	}
	return outs;*/
	outs << rso;
	return out;
}



// �������� �����
template<typename Type, unsigned long long Coll, unsigned long long Row>

std::istream& opeartor >> (std::istream& ins, const Matrix& rso)
{
	ins >> rso;
	return ins;
}





// �������� []
template<typename Type, unsigned long long Coll, unsigned long long Row>

Type& Matrix<Type, Coll, Row>::operator() (unsigned long long row, unsigned long long �oll)
{
	return data_[row][coll];
}


// const �������� []
template<typename Type, unsigned long long Coll, unsigned long long Row>

const Type& Matrix<Type, Coll, Row>::operator() (unsigned long long row, unsigned long long �oll) const
{
	return data_[row][coll];
}



// �������� at
template<typename Type, unsigned long long Coll, unsigned long long Row>

Type& Matrix<Type, Coll, Row>::at(unsigned long long row, unsigned long long �oll)
{
	if (�oll >= Coll || row >= Row)
	{
		std::cout << "������ ������� ��� � �������!!";
		::exit(-1);
	}
	return data_[row][�oll];
}


// const �������� at
template<typename Type, unsigned long long Coll, unsigned long long Row>

const Type& Matrix<Type, Coll, Row>::at(unsigned long long row, unsigned long long �oll) const
{
	if (�oll >= Coll || row >= Row)
	{
		std::cout << "������ ������� ��� � �������!!";
		::exit(-1);
	}
	return data_[row][�oll];
}