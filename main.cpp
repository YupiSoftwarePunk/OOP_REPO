#include <iostream>
#include <numeric>

class Integer
{
public:

	// Проверка числа
	bool isOdd()const
	{
		return units_ % 2 == 0;
	}

	bool isPositive()const
	{
		return units_ > 0;
	}

	bool isSimple()const
	{
		if (units_ < 2)
		{
			return false;
		}
		for (int i = 0; i < i * i <= units_; i++)
		{
			if (units_ % i == 0)
			{
				return false;
			}
		}
		return true;
	}

	bool isСoprime(Integer other)const
	{
		return std::gcd(units_, other.units_) == 1;
	}

	int Nod(Integer other)const
	{
		return std::gcd(units_, other.units_);
	}

	int Nok(Integer other)const
	{
		return std::lcm(units_, other.units_);
	}


	// Операторы
	int operator+(const Integer other)const
	{
		return units_ + other.units_;
	}



private:
	int units_;

};