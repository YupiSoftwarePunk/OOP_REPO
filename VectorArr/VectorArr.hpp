#pragma once
#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"
#include "../Matrix/Matrix.hpp"
#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"
#include  <initializer_list>
#include <algorithm>
#include <cstring>



template <typename T>
class Vector
{
public:
	// конструкторы

	// ќбычные конструкторы
	Vector(): array_(nullptr), capacity_(0), size_(0) {}

	Vector(int size) : capacity_(size), size_(size)
	{
		array_ = static_cast<T*>(allocator_.allocate(size * sizeof(T)));

		for (int i = 0; i < size; i++) 
		{
			new (&array_[i]) T(); 
		}
	}

	Vector(const std::initializer_list<T>& other) : capacity_(other.size()), size_(other.size()) 
	{
		array_ = static_cast<T*>(allocator_.allocate(capacity_ * sizeof(T)));
		std::copy(other.begin(), other.end(), array_);
	}

	//  онструктор копировани€
	Vector(const Vector& other) : capacity_(other.capacity_), size_(other.size_)
	{
		array_ = static_cast<T*>(allocator_.allocate(other.capacity_ * sizeof(T)));

		for (int i = 0; i < other.size_; i++)
		{
			new (&array_[i]) T(other.array_[i]); 
		}
	}

	// конструктор переноса
	Vector(Vector&& other) noexcept : array_(other.array_), capacity_(other.capacity_), size_(other.size_)
	{
		other.array_ = nullptr;
		other.capacity_ = 0;
		other.size_ = 0;
	}

	// конструктор оператор присваивани€ копировани€
	Vector& operator=(const Vector& other) 
	{
		if (this != &other) 
		{
			allocator_.deallocate(array_);

			capacity_ = other.capacity_;
			size_ = other.size_;
			array_ = static_cast<T*>(allocator_.allocate(capacity_ * sizeof(T)));

			for (int i = 0; i < size_; ++i) 
			{
				new (&array_[i]) T(other.array_[i]);
			}
		}
		return *this;
	}

	Vector(std::initializer_list<T> other) 
	{
		size_ = other.size();
		capacity_ = other.size()
		for (int i = 0; i < capacity_; i++)
		{
			array_[i] = other.array_[i];
		}
	}

	// деструктор
	~Vector()
	{
		if (capacity_ > 0 || capacity_ != nullptr)
		{
			allocator_.deallocate(array_);
		}
	}



	// методы дл€ индексов с одним параметром
	T* operator[] (unsigned long long Row)
	{
		return array_[Row];
	}

	const T* operator[] (unsigned long long Row) const
	{
		return array_[Row];
	}



	// методы дл€ индексов с двум€ параметрами
	T& operator() (unsigned long long Row, unsigned long long Coll)
	{
		return array_[Row][Coll];
	}

	const T& operator() (unsigned long long Row, unsigned long long Coll) const
	{
		return array_[Row][Coll];
	}



	// ќператор at
	T& at(unsigned long long Row, unsigned long long Coll)
	{
		return array_[Row][Coll];
	}

	const T& at(unsigned long long Row, unsigned long long Coll) const
	{
		return array_[Row][Coll];
	}



	// ќператор вывода
	friend std::ostream& operator << (std::ostream& outs, const Vector<T>& obj)
	{
		for (int i = 0; i < obj.size_; ++i) 
		{
			outs << "{ ";
			for (int j = 0; j < obj.capacity_; ++j) 
			{
				outs << obj.array_[i][j];
				if (j < obj.capacity_ - 1) 
				{
					outs << ", ";
				}
			}
			outs << " }";
			if (i < obj.size_ - 1) 
			{
				outs << "\n";
			}
		}
		return outs;
	}


	// ќператор ввода
	friend std::istream& operator >> (std::istream& ins, const Vector<T>& obj) 
	{
		for (int i = 0; i < obj.size_; ++i) 
		{
			for (int j = 0; j < obj.capacity_; ++j) 
			{
				ins >> obj.array_[i][j];
			}
		}
		return ins;
	}


private:

	struct allocator_ 
	{
		void* allocate(size_t  size)
		{
			return ::operator new(size);
		}

		void deallocate(T** arr)
		{
			if (arr) 
			{
				for (T** ptr = arr; *ptr != nullptr; ++ptr) 
				{
					delete[] * ptr; 
					*ptr = nullptr; 
				}
				delete[] arr; 
				arr = nullptr; 
			}
		}

		void reallocate(T** array, size_t old_rows, size_t old_cols, size_t new_rows, size_t new_cols)
		{
			T** new_array = allocate(new_rows, new_cols); 
			for (size_t i = 0; i < std::min(old_rows, new_rows); i++) 
			{
				for (size_t j = 0; j < std::min(old_cols, new_cols); j++) 
				{
					new_array[i][j] = array[i][j]; 
				}
			}
			deallocate(array); 
			return new_array; 
		}

	};

	// пол€
	T** array_;

	int capacity_;
	int size_;

	size_t rows_ = 0;
	size_t cols_ = 0;
};