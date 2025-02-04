#include <iostream>
#include <numeric>


class Integer
{
public:

	// constructors (конструктор по умолчанию и  конструкторы с параметрами)
	Integer() :Integer(false, 0u) {}
	Integer(bool sign, unsigned units) :sign_(sign), units_(units) {}
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


	// сеттеры и геттеры

	//setters
	bool SetSign(bool sign)
	{
		this->sign_ = sign;
	}

	void SetUnits(unsigned units)
	{
		this->units_ = units;
	}

	// getters
	bool GetSign()
	{
		return sign_;
	}

	unsigned GetUnits()
	{
		return units_;
	}



	// number check (проверка числа)

	// проверка на четность
	bool isOdd()const
	{
		return units_ % 2 == 0;
	}

	// проверка на положительность
	bool isPositive()const
	{
		return units_ > 0;
	}

	// проверка является ли число простым
	bool isSimple()const
	{
		if (units_ < 2)
		{
			return false;
		}
		for (int i = 2; i * i <= units_; i++)
		{
			if (units_ % i == 0)
			{
				return false;
			}
		}
		return true;
	}

	// проверка являются ли числа взаимнопростыми
	bool isCoprime(Integer other)const
	{
		return std::gcd(units_, other.units_) == 1;
	}

	// нахождение наибольшего общего делителя
	int Nod(Integer other)const
	{
		return std::gcd(units_, other.units_);
	}

	// нахождение наибольшего общего кратного
	int Nok(Integer other)const
	{
		return std::lcm(units_, other.units_);
	}



	// operators

	// Арифметические операторы  

	// Сумма
	friend Integer operator+(const Integer& a, const Integer& b)
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

	// Разность
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

	// Произведение
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

	// Частное
	friend Integer operator/(const Integer& a, const Integer& b)
	{
		if (b == 0)
		{
			std::cout << "Ошибка!! Деление на 0 запрещено!!\n\n";
			::exit(-1);		// принудетельное завершение программы (1 способ)
			//throw - 1;	// принудетельное завершение программы (2 способ)
		}

		Integer result;
		if (a.sign_ == b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.units_ / b.units_;
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

	// Деление по модулю
	friend Integer operator%(const Integer& a, const Integer& b)
	{
		Integer result;
		if (a.sign_ == b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.units_ % b.units_;
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



	// операторы инкремент и декремент

	// постфиксные инкремент и декремент

	// постфиксный инкремент
	Integer operator++(int)
	{
		if (sign_ == true)
		{
			units_++;
		}
		else
		{
			units_--;
		}
		return units_;
	}

	// постфиксный декремент
	Integer operator--(int)
	{
		if (sign_ == true)
		{
			units_--;
		}
		else
		{
			units_++;
		}
		return units_;
	}

	// префиксные инкремент и декремент


	// префиксный инкремент
	Integer operator++()
	{
		if (sign_ == true)
		{
			++(units_);
		}
		else
		{
			--(units_);
		}
		return units_;
	}

	// префиксный декремент
	Integer operator--()
	{
		if (sign_ == true)
		{
			--(units_);
		}
		else
		{
			++(units_);
		}
		return units_;
	}



	//Операторы сравнения

	bool operator==(Integer other) const
	{
		if (sign_ == other.sign_)
		{
			return units_ == other.units_;
		}
		return false;
	}

	bool operator!=(Integer other) const
	{
		if (sign_ == other.sign_)
		{
			return units_ != other.units_;
		}
		return true;
	}

	bool operator<(Integer other) const
	{
		if (sign_ == other.sign_)
		{
			return units_ < other.units_;
		}
		else if (sign_ == true && other.sign_ == false)
		{
			return false;
		}
		return true;
	}

	bool operator>(Integer other) const
	{
		if (sign_ == other.sign_)
		{
			return units_ > other.units_;
		}
		else if (sign_ == true && other.sign_ == false)
		{
			return true;
		}
		return false;
	}

	bool operator<=(Integer other) const
	{
		if (sign_ == other.sign_)
		{
			return units_ <= other.units_;
		}
		else if (sign_ == true && other.sign_ == false)
		{
			return false;
		}
		return true;
	}

	bool operator>= (Integer other) const
	{
		if (sign_ == other.sign_)
		{
			return units_ >= other.units_;
		}
		else if (sign_ == true && other.sign_ == false)
		{
			return true;
		}
		return false;
	}


	// Унарные операторы

	//Унарный плюс
	// + -> +
	// - -> -

	Integer operator+()
	{
		return units_;
	}


	// Унарный минус
	// - -> +
	// + -> -

	Integer operator-()
	{
		Integer res = { *this };
		if (sign_ == true)
		{
			res.sign_ = false;
		}
		else
		{
			res.sign_ = true;
		}
		return res;
	}



	// Оператор вывода
	friend std::ostream& operator<<(std::ostream& out, const Integer& other)
	{
		if (other.sign_ == true)
		{
			out << '-' << other.units_;
		}
		else
		{
			out << other.units_;
		}
		return out;
	}


	// поля класса
private:
	bool sign_;
	unsigned int units_;

};



int main()
{
	Integer num1 = 90;
	Integer num2 = 10;

	std::cout << num1 + num2 << "\n";
	std::cout << num1 - num2 << "\n";
	std::cout << num1 * num2 << "\n";
	std::cout << num1 / num2 << "\n";
	std::cout << num1 % num2 << "\n";

	std::cout << "\n\n";


	num1 += 10;
	std::cout << num1 << "\n";
	num1 -= 10;
	std::cout << num1 << "\n";
	num1 *= 10;
	std::cout << num1 << "\n";
	num1 /= 10;
	std::cout << num1 << "\n";
	num1++;
	std::cout << num1 << "\n";
	num1--;
	std::cout << num1 << "\n";
	++num1;
	std::cout << num1 << "\n";
	--num1;
	std::cout << num1 << "\n";

	std::cout << "\n\n\n";

	std::cout << (num1 < num2) << "\n";
	std::cout << (num1 > num2) << "\n";
	std::cout << (num1 <= num2) << "\n";
	std::cout << (num1 >= num2) << "\n";

	std::cout << "\n\n\n";

	std::cout << -num1 << "\n";
	std::cout << +num1 << "\n";


	return 0;
}
