#pragma once

#include "../Integer/Integer.hpp"
#include "../Fraction/Fraction.hpp"
#include "../Real/Real.hpp"
#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"

template <typename T>

class Serialization
{
public:

	// Тут определяется формат сериализации 
	static std::string Serialize(const T& num, const std::string& form);

private:

	// txt
	static std::string SerializeToTxt(const T& num);

	// json
	static std::string SerializeToJson(const T& num);

	// xml
	static std::string SerializeToXML(const T& num);

};

