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


template <typename T>

class Deserialization
{
public:

    // Тут определяется формат десериализации
    static T Deserialize(const std::string& data, const std::string& form)
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

private:

    // txt
    static T DeserializeFromTxt(const std::string& data)
    {
        T num;

        std::istringstream iss(data);
        iss >> num;

        if (iss.fail()) 
        {
            throw std::runtime_error("Failed to parse number from TXT format");
        }
        return num;
    }


    // json
    static T DeserializeFromJson(const std::string& data)
    {
        size_t valuePos = data.find("\"value\":\"");

        if (valuePos == std::string::npos) 
        {
            throw std::runtime_error("Invalid JSON format");
        }

        valuePos += 9; 
        size_t valueEnd = data.find('"', valuePos);

        if (valueEnd == std::string::npos) 
        {
            throw std::runtime_error("Invalid JSON format");
        }

        std::string value = data.substr(valuePos, valueEnd - valuePos);
        return DeserializeFromTxt(value);
    }


    // xml
    static T DeserializeFromXml(const std::string& data)
    {
        size_t startTagEnd = data.find('>');
        size_t endTagStart = data.find('<', startTagEnd + 1);

        if (startTagEnd == std::string::npos || endTagStart == std::string::npos)
        {
            throw std::runtime_error("Invalid XML format");
        }

        std::string value = data.substr(startTagEnd + 1, endTagStart - startTagEnd - 1);
        return DeserializeFromTxt(value);
    }
};


