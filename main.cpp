#include <iostream>
#include <numeric>


class Demo
{
public:
	friend std::ostream& operator<<
		    (
			std::ostream& out,
			const Demo& obj
			);
};



class Integer
{
public:

	// constructors
	Integer() :Integer(false, 0u) { }
	Integer(bool sign, unsigned units) :sign_(sign), units_(units) { }
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


	// Арифметические операторы  
	friend Integer operator+(const Integer& a,const Integer& b)
	{
		Integer result;
		if (a.sign_ == b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.units_ + b.units_;
		}
		else
		{
			if (a.units_ > b.units_)
			{
				result.sign_ = a.sign_;
				result.units_ = a.units_ - b.units_;
			}
			else if (a.units_ < b.units_)
			{
				result.sign_ = b.sign_;
				result.units_ = b.units_ - a.units_;
			}
			else
			{
				result.sign_ = false;
				result.units_ = 0;
			}
		}
		return result;
	}

	friend Integer operator-(const Integer& a, const Integer& b)
	{
		Integer result;
		if (a.sign_ == b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.sign_ - b.sign_;
		}
		else
		{
			if (a.sign_ > b.sign_)
			{
				result.sign_ = a.sign_;
				result.units_ = a.units_ + b.units_;
			}
			else if (a.sign_ < b.sign_)
			{
				result.sign_ = b.sign_;
				result.units_ = b.units_ + a.units_;
			}
			else
			{
				result.sign_ = false;
				result.units_ = 0;
			}
		}
		return result;
	}

	friend Integer operator*(const Integer& a, const Integer& b)
	{
		Integer result;
		if (a.sign_ == b.sign_)
		{
			result.sign_ = a.sign_;
		}
		else
		{
			if (a.sign_ > b.sign_)
			{
				result.sign_ = a.sign_;
			}
			else if (a.sign_ < b.sign_)
			{
				result.sign_ = b.sign_;
			}
			else
			{
				result.sign_ = false;
				result.units_ = 0;
			}
		}
		result.units_ = a.units_ * b.units_;
		return result;
	}

	friend Integer operator/(const Integer& a, const Integer& b)
	{
		Integer result;
		if (a.sign_ == b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.sign_ / b.sign_;
		}
		else
		{
			if (a.sign_ > b.sign_)
			{
				result.sign_ = a.sign_;
				result.units_ = a.units_ / b.units_;
			}
			else if (a.sign_ < b.sign_)
			{
				result.sign_ = b.sign_;
				result.units_ = b.units_ / a.units_;
			}
			else
			{
				result.sign_ = false;
				result.units_ = 0;
			}
		}
		return result;
	}

	friend Integer operator%(const Integer& a, const Integer& b)
	{
		Integer result;
		if (a.sign_ == b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.sign_ % b.sign_;
		}
		else
		{
			if (a.sign_ > b.sign_)
			{
				result.sign_ = a.sign_;
				result.units_ = a.sign_ % b.sign_;
			}
			else if (a.sign_ < b.sign_)
			{
				result.sign_ = b.sign_;
				result.units_ = b.sign_ % a.sign_;
			}
			else
			{
				result.sign_ = false;
				result.units_ = 0;
			}
		}
		return result;
	}


	// Операторы присваивания
	Integer& operator+=(Integer other)
	{
		
		if (sign_ == other.sign_)
		{
			sign_ = sign_;
			units_ += other.units_;
		}
		else
		{
			if (sign_ > other.sign_)
			{
				sign_ = sign_;
				units_ -= other.units_;
			}
			else if (sign_ < other.sign_)
			{
				sign_ = other.sign_;
				other.sign_ -= units_;
			}
			else
			{
				sign_ = false;
				units_ = 0;
			}
		}
		return *this;
	}

	Integer& operator-=(Integer other)
	{
		if (sign_ == other.sign_)
		{
			sign_ = sign_;
			units_ -= other.units_;
		}
		else
		{
			if (sign_ > other.sign_)
			{
				sign_ = sign_;
				units_ += other.units_;
			}
			else if (sign_ < other.sign_)
			{
				sign_ = other.sign_;
				other.sign_ += units_;
			}
			else
			{
				sign_ = false;
				units_ = 0;
			}
		}
		return *this;
	}

	Integer& operator*=(Integer other)
	{
		if (sign_ == other.sign_)
		{
			sign_ = sign_;
			units_ *= other.units_;
		}
		else
		{
			if (sign_ > other.sign_)
			{
				sign_ = sign_;
				units_ *= other.units_;
			}
			else if (sign_ < other.sign_)
			{
				sign_ = other.sign_;
				other.sign_ *= units_;
			}
			else
			{
				sign_ = false;
				units_ = 0;
			}
		}
		return *this;
	}

	Integer& operator/=(Integer other)
	{
		if (sign_ == other.sign_)
		{
			sign_ = sign_;
			units_ /= other.units_;
		}
		else
		{
			if (sign_ > other.sign_)
			{
				sign_ = sign_;
				units_ /= other.units_;
			}
			else if (sign_ < other.sign_)
			{
				sign_ = other.sign_;
				other.sign_ /= units_;
			}
			else
			{
				sign_ = false;
				units_ = 0;
			}
		}
		return *this;
	}



	// Оператор вывода
	friend std::ostream& operator<<(std::ostream& out, const Integer& obj)
	{
		return out;
	}

	// поля класса
private:
	bool sign_;
	unsigned int units_;

};



int main() 
{

	return 0;
}
