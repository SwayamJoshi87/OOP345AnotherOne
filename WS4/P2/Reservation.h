#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

namespace sdds {

	class Reservation {
		char m_id[10];
		std::string m_name;
		std::string m_email;
		unsigned int m_numOfPeople;
		size_t m_day;
		size_t m_hour;
	public:
		//default constructor
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);

		//Friend operators
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);

		//helper function to clean up the strings
		void cleanString(std::string& str) const;
	};

}

#endif // !SDDS_RESERVATION_H

