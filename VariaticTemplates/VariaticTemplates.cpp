//#include <iostream>
//#include <array>
//#include <vector>
//#include <tuple>
//
//#include <type_traits>
//#include <scoped_allocator>
//
//// Вариативные шаблоны
//// variatic templates
//
//
//template<typename Type=bool, typename Alloc = std::allocator<Type>>  // Динамический массив
//class DinArray {};
//
//template<typename Type, rsize_t size, typename Alloc = std::allocator<Type>> // статический массив
//class StatArray{
//
//
//private:
//	Alloc allocator_;
//	Type data_[size];
//};
//
//
//
//
//template<typename Type>
//void Print(Type var) {
//	std::cout << var << "\n";
//}
//
//template<typename Type, typename ...Args>
//void Print(Type var, const Args&... args) {
//	std::cout << var << "\n";
//	Print(args...);
//}
//
//
//
//int main()
//{
//	std::vector<int, std::allocator<int>> vect;
//	DinArray<int> dinArr;
//
//	std::array<int, 5> arr;
//
//	std::tuple<int, double, bool, std::string> tuple{123, false, 3.4, "qwerty"};
//	auto qool_tuple = std::make_tuple(122, std::string("true"), 45.f, "qwerttt");
//	Print(122, std::string("true"), 45.f, "qwerttt");
//}
