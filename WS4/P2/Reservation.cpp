#include "Reservation.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
namespace sdds {
	sdds::Reservation::Reservation()
	{
		strcpy(m_id,"");
		m_name = "";
		m_email = "";
		m_numOfPeople = 0;
		m_day = 0;
		m_hour = 0;
	}
	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
	}
	Reservation::Reservation(const std::string& res)
	{
		std::string temp = res;
		std::string tempID = temp.substr(0, temp.find(':'));
		cleanString(tempID);
		strcpy(m_id, tempID.c_str());
		temp.erase(0, temp.find(':') + 1);
		m_name = temp.substr(0, temp.find(','));
		cleanString(m_name);
		temp.erase(0, temp.find(',') + 1);
		m_email = temp.substr(0, temp.find(','));
		cleanString(m_email);
		temp.erase(0, temp.find(',') + 1);
		std::string tempNum = temp.substr(0, temp.find(','));
		cleanString(tempNum);
		m_numOfPeople = std::stoi(tempNum);
		temp.erase(0, temp.find(',') + 1);
		std::string tempDay = temp.substr(0, temp.find(','));
		cleanString(tempDay);
		m_day = std::stoi(tempDay);
		temp.erase(0, temp.find(',') + 1);
		cleanString(temp);
		m_hour = std::stoi(temp);
		temp.erase(0);
	}
	void Reservation::cleanString(std::string& str) const
	{
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		os << "Reservation " << std::right << std::setw(10) << res.m_id << ": " << std::setw(20) << res.m_name << "  " << std::left << std::setw(24) << "<" + res.m_email + ">";
		if (res.m_hour >= 6 && res.m_hour <= 9)
		{
			os << "Breakfast on day ";
		}
		else if (res.m_hour >= 11 && res.m_hour <= 15)
		{
			os << "Lunch on day ";
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21)
		{
			os << "Dinner on day ";
		}
		else
		{
			os << "Drinks on day ";
		}
		os << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numOfPeople << ((res.m_numOfPeople == 1) ? " person" : " people") << "." << std::endl;
		return os;
	}
}
