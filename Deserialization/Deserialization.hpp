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

    // Тут определяется формат десериализации
	static T Deserialize(const std::string& data, const std::string& format);

private:

    // txt
	static T DeserializeFromTxt(const std::string& data);

    // json
	static T DeserializeFromJson(const std::string& data);

    // xml
	static T DeserializeFromXml(const std::string& data);
};




// Тут определяется формат десериализации
template<typename T>

inline T Deserialization<T>::Deserialize(const std::string& data, const std::string& form)
{
    if (form == "txt")
    {
        return DeserializeFromTxt(data);
    }
    else if (form == "json")
    {
        return DeserializeFromJson(data);
    }
    else if (form == "xml")
    {
        return DeserializeFromXml(data);
    }
    else
    {
        throw std::invalid_argument("Unsupported format: " + form);
    }
}
