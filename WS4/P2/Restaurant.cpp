#include "Restaurant.h"

namespace sdds {

	unsigned int Restaurant::CALL_CNT = 0;

	sdds::Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_reservations = new Reservation*[cnt];
		m_numOfReservations = cnt;
		for (size_t i = 0; i < cnt; i++) {
			m_reservations[i] = new Reservation(*reservations[i]);
		}
	}
	size_t Restaurant::size() const
	{
		return m_numOfReservations;
	}
	Restaurant::~Restaurant()
	{
		for (size_t i = 0; i < m_numOfReservations; i++) {
			delete m_reservations[i];
		}
		delete[] m_reservations;
	}
	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << ++res.CALL_CNT << std::endl;
		os << "--------------------------" << std::endl;
		if(res.m_numOfReservations == 0) {
			os << "The restaurant is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < res.m_numOfReservations; i++) {
				os << *res.m_reservations[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}

	//copy constructor
Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}
	//copy assignment operator
	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src) {
			m_numOfReservations = src.m_numOfReservations;
			m_reservations = new Reservation*[m_numOfReservations];
			for (size_t i = 0; i < m_numOfReservations; i++) {
				m_reservations[i] = new Reservation(*src.m_reservations[i]);
			}
		}
		return *this;
	}
//move constructor
Restaurant::Restaurant(Restaurant&& src) noexcept
	{
		*this = std::move(src);
	}
//move assignment operator
	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept
	{
		if (this != &src) {
			m_numOfReservations = src.m_numOfReservations;
			m_reservations = src.m_reservations;
			src.m_numOfReservations = 0;
			src.m_reservations = nullptr;
		}
		return *this;
	}
}