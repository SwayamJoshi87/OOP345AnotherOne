#include "SpellChecker.h"

using namespace sdds;
namespace sdds {

	sdds::SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "Bad file name!";
		}
		else
		{
			std::string line;
			size_t i = 0;
			while (std::getline(file, line))
			{
				m_badWords[i] = line.substr(0, line.find(' '));
				line.erase(0, line.find(' ') + 1);
				m_goodWords[i] = line;
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
				i++;
			}
		}
	}

	void sdds::SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			while (text.find(m_badWords[i]) != std::string::npos)
			{
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
				m_count++;
				m_replacements[i]++;
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replacements[i] << " replacements" << std::endl;
		}
		//out << std::setw(15) << std::right << "Total " << ": " << m_count << " replacements" << std::endl;
	}

};