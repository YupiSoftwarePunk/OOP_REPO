#pragma once

#include "../Integer/Integer.hpp"
#include "../Fraction/Fraction.hpp"
#include "../Real/Real.hpp"
#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>

//помогает заниматься серилизацией классов, вложенных в библиотеку
template <typename T>

class Serialization
{
public:

	Serialization(const T& num) {}


	// Тут определяется формат сериализации 
	static std::string Serialize(const T& num, const std::string& form)
	{
		if (form == "txt")
		{
			return SerializeToTxt(num);
		}
		else if (form == "json")
		{
			return SerializeToJson(num);
		}
		else if (form == "xml")
		{
			return SerializeToXml(num);
		}
		else
		{
			throw std::invalid_argument("Unsupported format: " + form);
		}
	}


private:

	// txt
	static std::string SerializeToTxt(const T& num)
	{
		std::ostringstream oss;
		oss << num << " " << typeName();



		std::ofstream fout;
		fout.open("TXT_Data.txt");

		if (fout.is_open())
		{
			fout << oss.str();
		}

		fout.close();

		return oss.str();
	}


	// json
	static std::string SerializeToJson(const T& num)
	{
		std::ostringstream oss;
		oss << "{\"type\":\"" << typeName() << "\",\"value\":\"" << num << "\"}";



		std::ofstream fout;
		fout.open("JSON_Data.json");

		if (fout.is_open())
		{
			fout << oss.str();
		}

		fout.close();

		return oss.str();
	}


	// xml
	static std::string SerializeToXml(const T& num)
	{
		std::ostringstream oss;
		oss << "<" << typeName() << ">" << num << "</" << typeName() << ">";



		std::ofstream fout;
		fout.open("XML_Data.xml");

		if (fout.is_open())
		{
			fout << oss.str();
		}

		fout.close();

		return oss.str();
	}



	// Определение типа
	static const char* typeName() 
	{
		if constexpr (std::is_same_v<T, Integer>)
		{
			return "Integer";
		}
		else if constexpr (std::is_same_v<T, Fraction>)
		{
			return "Fraction";
		}
		else if constexpr (std::is_same_v<T, Real>)
		{
			return "Real";
		}
		else if constexpr (std::is_same_v<T, Point2d>)
		{
			return "Point2d";
		}
		else if constexpr (std::is_same_v<T, Segment>)
		{
			return "Segment";
		}
		else static_assert(false, "Unsupported type");
	}

};

