#include "Book.h"

namespace sdds {
	Book::Book()
	{
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0;
		m_description = "";
	}

	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	Book::Book(const std::string& strBook)
	{
		std::string temp = strBook;
		std::string temp1 = " ";
		m_author = temp.substr(0, temp.find(','));
		cleanString(m_author);
		temp.erase(0, temp.find(',') + 1);
		m_title = temp.substr(0, temp.find(','));
		cleanString(m_title);
		temp.erase(0, temp.find(',') + 1);
		m_country = temp.substr(0, temp.find(','));
		cleanString(m_country);
		temp.erase(0, temp.find(',') + 1);
		temp1 = temp.substr(0, temp.find(','));
		cleanString(temp1);
		m_price = std::stod(temp1);
		temp.erase(0, temp.find(',') + 1);
		temp1 = temp.substr(0, temp.find(','));
		cleanString(temp1);
		m_year = std::stoi(temp1);
		temp.erase(0, temp.find(',') + 1);
		m_description = temp;
		cleanString(m_description);
	}

	std::string Book::cleanString(std::string& str)
	{
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
		return str;
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os << std::setw(20) << book.m_author << " | " 
			<< std::setw(22) << book.m_title << " | "
			<< std::setw(5) << book.m_country << " | "
			<< std::setw(4) << book.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | "
			<< book.m_description << std::endl;
		return os;
	}

}