#include "Integer.hpp"
#include "Fraction.hpp"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Integer num1 = 2;
	Integer num2 = 2;

	Integer num11 = 1;
	Integer num22 = 2;

	Fraction num3 = (num1, num2);

	Fraction num4 = (num11, num22);

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

	std::cout << "\n\n\n";

	std::cout << -num1 << "\n";
	std::cout << +num1 << "\n";

	std::cout << "\n\n\n";

	std::cout << num1.isPositive() << "\n";
	std::cout << num1.isOdd() << "\n";
	std::cout << num1.isSimple() << "\n";
	std::cout << num1.isCoprime(num2) << "\n";
	std::cout << num1.Nod(num2) << "\n";
	std::cout << num1.Nok(num2) << "\n";

	std::cout << "\n\n\t\tДроби\n\n";

	std::cout << num3.isNumPositive() << "\n";
	std::cout << num3.isSame(num4) << "\n";   // mistake
	std::cout << num4.isProper() << "\n"; // mistake (idk how to solve it)
	//std::cout << num3.ReduceFraction() << "\n";     // mistake    need to fix operator<< 
	//std::cout << num3.ReverseFraction() << "\n";    // mistake    need to fix operator<< 
	std::cout << num3.CountUnits() << "\n"; // mistake

	std::cout << "\n\n\n";

	// mistakes!! need to fix operator<<     (idk how to solve it)
	//std::cout << num3 + num4 << "\n";
	//std::cout << num3 - num4 << "\n";
	//std::cout << num3 * num4 << "\n";
	//std::cout << num3 / num4 << "\n";

	return 0;
}
