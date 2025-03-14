#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"
#include "../Dictionary/Dictionary.hpp"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Integer num1 = 5;
	Integer num2 = 2;

	Integer num11 = 10;
	Integer num22 = 2;

	Fraction num3 = {num1, num2};
	Fraction num4 = {num11, num22 };

	Real num5 = { num1, num3 };
	Real num6 = { num2, num4 };


	std::cout << "\t\tСловарь\n\n";

	/* 
					задача заключалось в том, чтобы проверять есть ли слова из текста в словаре и возвратить число слов,
					которые отсутствуют в словаре и перечислить их 
	 */

	std::string text = "One orange fox watched TV last night";

	Dictionary dict;

	std::cout << dict.InDict(text);
	//----------------------------------------------------------------------



	std::cout << "\n\n\t\tЦелые числа\n\n";

	std::cout << num1 << "\n";
	std::cout << num2 << "\n";

	std::cout << "\n\n\n";

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
	num1 = 0;
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
	std::cout << num1.Gcd(num2) << "\n";
	std::cout << num1.Lcm(num2) << "\n";



	std::cout << "\n\n\t\tДроби\n\n";

	std::cout << num3 << "\n";
	std::cout << num4 << "\n";

	std::cout << "\n\n\n";

	std::cout << num3.isNumPositive() << "\n";
	std::cout << num3.isNumNegative() << "\n";
	std::cout << num3.isSame(num4) << "\n";    
	std::cout << num3.isEqual(num4) << "\n";     
	std::cout << num4.isProper() << "\n";
	std::cout << num4.isImProper() << "\n";
	std::cout << num3.ReduceFraction() << "\n";    
	std::cout << num3.ReverseFraction() << "\n";    
	std::cout << num3.CountUnits() << "\n";      

	std::cout << "\n\n\n";

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

	std::cout << -num3 << "\n";   
	std::cout << +num3 << "\n";	  



	std::cout << "\n\n\t\tДесятичные Дроби\n\n";

	std::cout << num5 << "\n";
	std::cout << num6 << "\n";

	std::cout << "\n\n\n";

	std::cout << num5.isDecimalPositive() << "\n";
	std::cout << num5.isDecimalNegative() << "\n";
	std::cout << num5.isDecimal() << "\n";
	std::cout << num5.isDecimalSame(num6) << "\n";

	std::cout << "\n\n\n";

	std::cout << num5 + num6 << "\n";
	std::cout << num6 - num5 << "\n";
	std::cout << num5 * num6 << "\n"; 
	std::cout << num6 / num5 << "\n";

	std::cout << "\n\n\n";

	std::cout << (num5 < num6) << "\n";
	std::cout << (num5 > num6) << "\n";
	std::cout << (num5 <= num6) << "\n";
	std::cout << (num5 >= num6) << "\n";
	std::cout << (num5 == num6) << "\n";
	std::cout << (num5 != num6) << "\n";

	std::cout << "\n\n\n";

	// некорректно работает код ниже
	num5 += num6;
	std::cout << num5 << "\n";
	num5 -= num6;
	std::cout << num5 << "\n";
	num5 *= num6;
	std::cout << num5 << "\n";
	num5 /= num6;
	std::cout << num5 << "\n";
	//----------------------------------------

	std::cout << "\n\n\n";

	std::cout << -num5 << "\n";
	std::cout << +num5 << "\n";

	return 0;
}
