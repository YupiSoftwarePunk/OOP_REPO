#include "../Matrix/Matrix.hpp"

// Конструкторы
template<typename Type, unsigned long long Row, unsigned long long Coll>

Matrix<Type, Row, Coll>::Matrix()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[i][j] = Type{};
		}
	}
}


// Конструктор копирования
template<typename Type, unsigned long long Row, unsigned long long Coll>

Matrix<Type, Row, Coll>::Matrix(const Matrix& other)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			data_[i][j] = other.data_[i][j];
		}
	}
}


template<typename Type, unsigned long long Row, unsigned long long Coll>

Matrix<Type, Row, Coll>::Matrix(Matrix&& other) noexcept
{
	data_ = nullptr;
	std::swap(data_, other.data_);
}


// конструктор присваивания копирования
template<typename Type, unsigned long long Row, unsigned long long Coll>

const Matrix& Matrix<Type, Row, Coll>::operator= (const Matrix& other)
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


// конструктор переноса
template<typename Type, unsigned long long Row, unsigned long long Coll>

const Matrix& Matrix<Type, Row, Coll>::operator= (Matrix&& other)
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



// деструктор
template<typename Type, unsigned long long Row, unsigned long long Coll>

Matrix<Type, Row, Coll>::~Matrix() = default;



// размер колонок и строк
template<typename Type, unsigned long long Row, unsigned long long Coll>
unsigned long long Matrix<Type, Row, Coll>::collSize() const
{
	return Coll;
}


template<typename Type, unsigned long long Row, unsigned long long Coll>
unsigned long long Matrix<Type, Row, Coll>::rowSize() const
{
	return Row;
}




// оператор вывода
template<typename Type, unsigned long long Row, unsigned long long Coll>

std::ostream& opeartor << (std::ostream& outs, const Matrix<Type, Row, Coll>& rso)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Coll; j++)
		{
			outs << rso[i][j] << " ";
		}
		outs << "\n";
	}
	return outs;

	/*outs << rso;
	return out;*/
}



// оператор ввода
template<typename Type, unsigned long long Row, unsigned long long Coll>

std::istream& opeartor >> (std::istream& ins, const Matrix& rso)
{
	ins >> rso;
	return ins;
}





// Оператор []
template<typename Type, unsigned long long Row, unsigned long long Coll>

Type& Matrix<Type, Row, Coll>::operator() (unsigned long long row, unsigned long long сoll)
{
	return data_[row][coll];
}


// const Оператор []
template<typename Type, unsigned long long Row, unsigned long long Coll>

const Type& Matrix<Type, Row, Coll>::operator() (unsigned long long row, unsigned long long сoll) const
{
	return data_[row][coll];
}



// Оператор at
template<typename Type, unsigned long long Row, unsigned long long Coll>

Type& Matrix<Type, Row, Coll>::at(unsigned long long row, unsigned long long сoll)
{
	if ((сoll >= Coll || row >= Row) || (сoll >= Coll && row >= Row))
	{
		std::cout << "Такого индекса нет в матрице!!";
		::exit(-1);
	}
	return data_[row][сoll];
}


// const Оператор at
template<typename Type, unsigned long long Row, unsigned long long Coll>

const Type& Matrix<Type, Row, Coll>::at(unsigned long long row, unsigned long long сoll) const
{
	if ((сoll >= Coll || row >= Row) || (сoll >= Coll && row >= Row))
	{
		std::cout << "Такого индекса нет в матрице!!";
		::exit(-1);
	}
	return data_[row][сoll];
}



// Арифметические операторы
const Matrix& operator+(const Matrix& lso, const Matrix& rso)
{
	if (sizeof(lso.data_) == sizeof(rso.data_))
	{
		unsigned long long newObj = rso.rowSize();
		Matrix<Type, newObj, rso.collSize()> result;

		for (int i = 0; i < rso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				result[i][j] = lso[i][j] + rso[i][j];
			}
		}
		return result;
	}
	else
	{
		std::cout << "Размеры матриц должны быть равны!!";
		::exit(-1);
	}
}


const Matrix& operator-(const Matrix& lso, const Matrix& rso)
{
	if (sizeof(lso.data_) == sizeof(rso.data_))
	{
		unsigned long long newObj = rso.rowSize();
		Matrix<Type, newObj, rso.collSize()> result;

		for (int i = 0; i < rso.rowSize(); i++)
		{
			for (int j = 0; j < rso.collSize(); j++)
			{
				result[i][j] = lso[i][j] - rso[i][j];
			}
		}
		return result;
	}
	else
	{
		std::cout << "Размеры матриц должны быть равны!!";
		::exit(-1);
	}
}


const Matrix& operator*(const Matrix& lso, const Matrix& rso)
{
	// to do
}


const Matrix& operator*(const Matrix& lso, int num)
{
	unsigned long long newObj = lso.rowSize();
	Matrix<Type, newObj, lso.collSize()> result;

	for (int i = 0; i < lso.rowSize(); i++)
	{
		for (int j = 0; j < rso.collSize(); j++)
		{
			result[i][j] = lso[i][j] * num;
		}
	}

	return result;
}
