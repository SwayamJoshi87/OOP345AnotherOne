#include <iostream>
#include <string>
#include <iomanip>

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_

namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		//Friend helper functions
		friend std::ostream& operator<<(std::ostream& os, const Book& book);

		//clean string
		std::string cleanString(std::string& str);
	};
};

#endif // !SDDS_BOOK_H_
