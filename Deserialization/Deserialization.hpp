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
#include <regex>

template <typename T>
class Deserialization
{
public:
    Deserialization(const std::string& filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        fileData = buffer.str();
        file.close();

        format = DetermineFormat(filename);
    }

    T Deserialize()
    {
        if (format == "txt")
        {
            return DeserializeFromTxt(fileData);
        }
        else if (format == "json")
        {
            return DeserializeFromJson(fileData);
        }
        else if (format == "xml")
        {
            return DeserializeFromXml(fileData);
        }
        else
        {
            throw std::invalid_argument("Unsupported format: " + format);
        }
    }

private:
    std::string fileData;
    std::string format;

    std::string DetermineFormat(const std::string& filename)
    {
        if (filename.ends_with(".txt"))
            return "txt";
        else if (filename.ends_with(".json"))
            return "json";
        else if (filename.ends_with(".xml"))
            return "xml";
        else
            throw std::invalid_argument("Unknown file format for: " + filename);
    }

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

    static T DeserializeFromJson(const std::string& data)
    {
        std::regex jsonRegex(R"(\{.*"value"\s*:\s*"(.*?)"".*\\)");

        std::smatch match;

        if (std::regex_search(data, match, jsonRegex))
        {
            return DeserializeFromTxt(match[1]);
        }
        throw std::runtime_error("Invalid JSON format");
    }


    static T DeserializeFromXml(const std::string& data)
    {
        std::regex xmlRegex(R"(<.*?>(.*?)</.*?>)");
        std::smatch match;

        if (std::regex_search(data, match, xmlRegex))
        {
            return DeserializeFromTxt(match[1]);
        }
        throw std::runtime_error("Invalid XML format");
    }
};

