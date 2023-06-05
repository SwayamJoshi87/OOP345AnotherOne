#include "Dictionary.h"

namespace sdds {

	std::ostream& operator<<(std::ostream& os, const Dictionary& d)
	{
		std::string def = d.getDefinition();
		os << std::right
			<< std::setw(20)
			<< d.getTerm()
			<< ": "
			<< std::left
			<< std::setw(def.length())
			<< d.getDefinition();

		return os;
	}

	bool Dictionary::operator==(const Dictionary& rhs) const
	{
		return m_term == rhs.m_term;
	}

}