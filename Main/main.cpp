#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Integer num1 = 2;
	Integer num2 = 10;

	Integer num11 = 11;
	Integer num22 = 10;

	Fraction num3 = {num1, num2};
	Fraction num4 = {num11, num22 };

	std::cout << "Целые числа\n\n";

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
	std::cout << (num1 == num2) << "\n";
	std::cout << (num1 != num2) << "\n";

	std::cout << "\n\n\n";

	std::cout << -num1 << "\n";
	std::cout << +num1 << "\n";

	std::cout << "\n\n\n";

	std::cout << num1.isPositive() << "\n";
	std::cout << num1.isNegative() << "\n";
	std::cout << num1.isOdd() << "\n";
	std::cout << num1.isEven() << "\n";
	std::cout << num1.isSimple() << "\n";
	std::cout << num1.isCoprime(num2) << "\n";
	std::cout << num1.Nod(num2) << "\n";
	std::cout << num1.Nok(num2) << "\n";



	std::cout << "\n\n\t\tДроби\n\n";

	std::cout << num3.isNumPositive() << "\n";
	std::cout << num3.isNumNegative() << "\n";
	std::cout << num3.isSame(num4) << "\n";    
	std::cout << num3.isEqual(num4) << "\n";     
	std::cout << num4.isProper() << "\n";
	std::cout << num4.isImProper() << "\n";
	std::cout << num3.ReduceFraction() << "\n";    
	std::cout << num3.ReverseFraction() << "\n";    
	std::cout << num3.CountUnits() << "\n";       // mistake 

	std::cout << "\n\n\n";

	// Весь код ниже работает не корректно и нуждается в доработке и дебаге
	std::cout << num3 + num4 << "\n";
	std::cout << num3 - num4 << "\n";
	std::cout << num3 * num4 << "\n";
	std::cout << num3 / num4 << "\n";

	std::cout << "\n\n\n";

	std::cout << (num3 < num4) << "\n";
	std::cout << (num3 > num4) << "\n";
	std::cout << (num3 <= num4) << "\n";
	std::cout << (num3 >= num4) << "\n";
	std::cout << (num3 == num4) << "\n";
	std::cout << (num3 != num4) << "\n";   

	std::cout << "\n\n\n";

	num3 += num4;
	std::cout << num3 << "\n";
	num3 -= num4;
	std::cout << num3 << "\n";
	num3 *= num4;
	std::cout << num3 << "\n";
	num3 /= num4;
	std::cout << num3 << "\n";

	std::cout << "\n\n\n";

	std::cout << -num3 << "\n";   // mistake 
	std::cout << +num3 << "\n";

	return 0;
}
