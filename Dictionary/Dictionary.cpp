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

	return "В словаре отсутствуют " + std::to_string(wordsCount) + " слов из текста\n" + "Слова, которые не входят в словарь: " + extraWords + "\n";
}