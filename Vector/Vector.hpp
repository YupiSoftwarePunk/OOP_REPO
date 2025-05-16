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

	// Обычные конструкторы
	Vector(): array_(nullptr), capacity_(0), size_(0) {}

	Vector(int size) : capacity_(size), size_(size)
	{
		array_ = static_cast<T*>(allocator_.allocate(size * sizeof(T)));

		for (int i = 0; i < size; i++) 
		{
			new (&array_[i]) T(); 
		}
	}

	Vector(T* arr) 
	{
		capacity_ = arr.size();
		array_ = allocator_.allocate(capacity_);
		memcpy(array_, arr, capacity_);
	}

	// Конструктор копирования
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

	// конструктор оператор присваивания копирования
	Vector& operator=(const T& other) 
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

private:

	struct {
		void* allocate(size_t  size)
		{
			return ::operator new(size);
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