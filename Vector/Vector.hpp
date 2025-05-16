#pragma once
#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"
#include "../Matrix/Matrix.hpp"
#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"
#include <vector>
#include  <initializer_list>


std::vector <int> a;

template <typename T>
class Vector
{
public:
	// конструкторы
	Vector() {}

	Vector(int size) 
	{
		size_ = size;
		array_ = allocator_.allocate(size);
	}

	Vector(T* arr) 
	{
		capacity_ = arr.size();
		array_ = allocator_.allocate(capacity_);
		memcpy(array_, arr, capacity_);
	}

	Vector(const T& other) 
	{
		capacity_ = other.capacity_;
		for (int i = 0; i < capacity_; i++)
		{
			array_[i] = other.array_[i];
		}
	}

	Vector(T&& other) 
	{
		str_ = nullptr;
		capacity_ = 0;

		std::swap(array_, other.array_);
		std::swap(capacity_, other.capacity_);
	}

	Vector& operator=(const T& other) {}

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

private:

	struct {
		char* allocate(int size)
		{
			char(*place) = new char[size];
			return place;
		}
		void deallocate(char* place)
		{
			delete[] place;
		}
		void reallocate(char*& place, int old_size, int new_size)
		{
			char* place2 = new char[new_size];
			for (int i = 0; i < new_size; i++)
			{
				place2[i] = place[i];
			}
			delete[] place;
			place = place2;

		}

	}allocator_;

	// поля
	T* array_[];
	int capacity_;
	int size_;
};