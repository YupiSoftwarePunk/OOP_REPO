#pragma once
#include <iostream>
#include <set>
#include <string>
#include <Windows.h>
#include <sstream>

class Dictionary
{
public:
	std::set<std::string> dict
	{
		"bread", "milk", "orange", "fox"
	};

	std::string InDict(std::string text);

	std::set<std::string> dict2;
};

