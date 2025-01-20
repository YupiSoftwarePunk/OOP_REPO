#include <iostream>
#include <numeric>

class Integer
{
public:

	// constructors
	Integer():Integer(false, 0u) { }
	Integer(bool sign, unsigned units):sign_(sign), units_(units){ }
	Integer(int number) 
	{
		if (number < 0)
		{
			sign_ = true;
			units_ = ::abs(number);
		}
		else
		{
			sign_ = false;
			units_ = static_cast <unsigned> (number);
		}
	}


	// number check

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

	bool isCoprime(Integer other)const
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


	// operators

	Integer operator+(const Integer &other)const
	{
		Integer result;
		if (sign_ == other.sign_) 
		{
			result.sign_ = sign_;
			result.units_ = units_ + other.units_;
		}
		else
		{
			if (units_ > other.units_)
			{
				result.sign_ = sign_;
				result.units_ = units_ - other.units_;
			}
			else if (units_ < other.units_) 
			{
				result.sign_ = other.sign_;
				result.units_ = other.units_ - units_;
			}
			else 
			{
				result.sign_ = false;
				result.units_ = 0;
			}
		}
		return result;
	}

	friend Integer operator-(const Integer other)
	{
		// доделать по принципу operator+
	}




private:
	bool sign_;
	unsigned int units_;

};
