#include "Movie.h"

namespace sdds {

	sdds::Movie::Movie()
	{
		m_year = 0;
	}

	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		std::string temp = strMovie;
		std::string temp1 = " ";
		m_title = temp.substr(0, temp.find(','));
		cleanString(m_title);
		temp.erase(0, temp.find(',') + 1);
		temp1 = temp.substr(0, temp.find(','));
		cleanString(temp1);
		m_year = std::stoi(temp1);
		temp.erase(0, temp.find(',') + 1);
		m_description = temp;
		cleanString(m_description);
	}

	std::string Movie::cleanString(std::string& str)
	{
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
		return str;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os << std::setw(40) << movie.m_title << " | ";
		os << std::setw(4) << movie.m_year << " | ";
		os << movie.m_description << std::endl;
		return os;
	}

}
