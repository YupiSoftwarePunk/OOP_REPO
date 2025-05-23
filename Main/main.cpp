#include "../Fraction/Fraction.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"
#include "../Dictionary/Dictionary.hpp"
#include "../Matrix/Matrix.hpp"
#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"
#include "../VectorArr/VectorArr.hpp"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Integer num1 = 5;
	Integer num2 = 2;

	Integer num11 = 10;
	Integer num22 = 2;

	Fraction num3 = { num1, num2 };
	Fraction num4 = { num11, num22 };

	Real num5 = { num1, num3 };
	Real num6 = { num2, num4 };

	Point2d p1(num5, num6);
	Point2d p2(num6, num5);

	Segment seg1(p1, p2);
	Segment seg2(p2, p1);
	Segment seg3;


	std::cout << "\t\t�������\n\n";

	/*
				������ ����������� � ���, ����� ��������� ���� �� ����� �� ������ � ������� � ���������� ����� ����,
				������� ����������� � ������� � ����������� ��
	*/

	std::string text = "One orange fox watched TV last night";

	Dictionary dict;

	std::cout << dict.InDict(text);
	//----------------------------------------------------------------------



	std::cout << "\n\n\t\t����� �����\n\n";

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



	std::cout << "\n\n\t\t�����\n\n";

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



	std::cout << "\n\n\t\t���������� �����\n\n";

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

	num5 += num6;
	std::cout << num5 << "\n";
	num5 -= num6;
	std::cout << num5 << "\n";
	num5 *= num6;
	std::cout << num5 << "\n";
	// ����������� �������� ��� ����
	/*num5 /= num6;                  -- ��� � �� ���� ����� ��������
	std::cout << num5 << "\n";	*/
	// ������ �������� ������ ��� ������� �� 0
	//----------------------------------------

	std::cout << "\n\n\n";

	std::cout << -num5 << "\n";
	std::cout << +num5 << "\n";



	std::cout << "\n\n\t\t�������\n\n";

	Matrix<Integer, 3, 3> table;

	table(0, 0) = 1;
	table(0, 1) = 2;
	table(0, 2) = 3;
	table(1, 0) = 4;
	table(1, 1) = 5;
	table(1, 2) = 6;
	table(2, 0) = 7;
	table(2, 1) = 8;
	table(2, 2) = 9;


	Matrix<Integer, 3, 3> table2;

	table2(0, 0) = 1;
	table2(0, 1) = 2;
	table2(0, 2) = 3;
	table2(1, 0) = 4;
	table2(1, 1) = 5;
	table2(1, 2) = 6;
	table2(2, 0) = 7;
	table2(2, 1) = 8;
	table2(2, 2) = 9;

	std::cout << table(0, 0) << "\n";

	std::cout << "\n\n\n";

	Matrix<Integer, 3, 3> table3 = table + table2;
	std::cout << table3 << "\n";
	Matrix<Integer, 3, 3> table4 = table - table2;
	std::cout << table3 << "\n";
	Matrix<Integer, 3, 3> table5 = table * table2;
	std::cout << table3 << "\n";
	Matrix<Integer, 3, 3> table6 = table / table2;
	std::cout << table3 << "\n";


	std::cout << "\n\n\n";


	std::cout << table << "\n";
	table += table2;
	std::cout << table << "\n";
	table -= table2;
	std::cout << table << "\n";
	table *= table2;
	std::cout << table << "\n";
	table /= table2;
	std::cout << table << "\n";


	std::cout << "\n\n\n";


	std::cout << (table == table2) << "\n";
	std::cout << (table != table2) << "\n";
	std::cout << (table > table2) << "\n";
	std::cout << (table < table2) << "\n";
	std::cout << (table >= table2) << "\n";
	std::cout << (table <= table2) << "\n";




	std::cout << "\n\n\t\t�����\n\n";

	std::cout << p1 << "\n";
	std::cout << p2 << "\n";

	std::cout << (p1 == p1) << "\n";
	std::cout << p1.IsEqualPoints(p2) << "\n";
	std::cout << p2.MySqrt(num5) << "\n";
	std::cout << DistanceBetweenPoints(p1, p2) << "\n";





	std::cout << "\n\n\t\t�������\n\n";

	std::cout << seg1.GetPointer1() << "\n";
	std::cout << seg1.GetPointer1Ref() << "\n";
	std::cout << seg1.IsEqualSegments(seg2) << "\n";
	std::cout << seg1.IsSegmentsCrossed(seg2) << "\n";

	/*
	��� ����� ��������

	����� ������� ����, ������� �� ���������� ����� � ����������� ��� ������������ ��� ������, ������� ��� �������������
	� ���������� �� ��� ��� � �������� ���� � ����� ���� �� ����� ����� ��� ������� ������� � ����� ����� ����

	������:
	������� ����� ���� Real:
	� ����� ���������� �� ��� ����� � txt ������

	� ���� ����������� ����� ������� ��� ����� �� ����� ������� � ����� � ���� �� ���� ������
	*/


	std::cout << "\n\n\t\t����� �����\n";

	std::cin >> num1;
	std::cout << num1;


	std::cout << "\n\t\t�����\n";

	std::cin >> num3;
	std::cout << num3;


	std::cout << "\n\t\t���������� �����\n";

	std::cin >> num5;   
	std::cout << num5;


	std::cout << "\n\t\t�����\n";

	std::cin >> p1;   
	std::cout << p1;


	std::cout << "\n\t\t�������\n";
	std::cin >> seg3;     // 1(11/22)2(22/33)3(33/44)4(44/55)
	std::cout << seg3;



	std::cout << "\n\t\t��������� ������������ ������\n";

	Vector<int> vector(3, 4);

	Vector<double> dynVector = 
	{
	{1.1, 2.2, 3.3},  
	{4.4, 5.5, 6.6},
	{56.99, 77.45, 90.34}
	};




	return 0;
}