#include "Dictionary.hpp"

std::string Dictionary::InDict(std::string text)
{
	int wordsCount = 0;
	std::stringstream words(text);
	std::string word;
	std::string extraWords;

	while (words >> word)
	{
		wordsCount++;

		if (dict.contains(word))
		{
			wordsCount--;
		}
		else
		{
			extraWords += word;
			extraWords += ' ';
			dict2.insert(word);
		}
	}

	return "� ������� ����������� " + std::to_string(wordsCount) + " ���� �� ������\n" + "�����, ������� �� ������ � �������: " + extraWords + "\n";
}