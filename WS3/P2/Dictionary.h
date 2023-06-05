#include <iostream>
#include <string>
#include <iomanip>

#ifndef SDDS_DICTIONARY_H_
#define SDDS_DICTIONARY_H_

namespace sdds {

	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
		Dictionary(){}
		// A simple setter function
		void set(const std::string& term, const std::string definition);

		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.

		//insertion operator
		friend std::ostream& operator<<(std::ostream& os, const Dictionary& d);
		//comparison operator
		bool operator==(const Dictionary& rhs) const;
		

	};

};
#endif // !SDDS_DICTIONARY_H_

