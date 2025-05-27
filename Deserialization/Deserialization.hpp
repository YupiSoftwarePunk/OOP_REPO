#pragma once

#include "../Integer/Integer.hpp"
#include "../Fraction/Fraction.hpp"
#include "../Real/Real.hpp"
#include "../Point2d/Point2d.hpp"
#include "../Segment/Segment.hpp"

template <typename T>

class Deserialization
{
public:

	static T Deserialize(const std::string& data, const std::string& format);

private:

	static T DeserializeFromTxt(const std::string& data);

	static T DeserializeFromJson(const std::string& data);

	static T DeserializeFromXml(const std::string& data);
};