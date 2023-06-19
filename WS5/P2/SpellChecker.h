
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


#ifndef SDDS_SPELLCHECKER
#define SDDS_SPELLCHECKER


namespace sdds {
	class SpellChecker {
		std::string m_badWords[6];
		std::string m_goodWords[6];
		size_t m_count = 0;
		size_t m_replacements[6] = { 0 };
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
};

#endif // !SPELLCHECKER