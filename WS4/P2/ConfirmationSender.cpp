#include "ConfirmationSender.h"
#include "Reservation.h"

namespace sdds{
	ConfirmationSender::ConfirmationSender()
	{
		m_reservations = nullptr;
		m_cnt = 0;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept
	{
		*this = std::move(src);
	}
	ConfirmationSender::~ConfirmationSender()
	{
		if (m_reservations != nullptr) {
			for(int i = 0; i < m_cnt; i++)
				delete m_reservations[i];
			delete[] m_reservations;
			m_reservations = nullptr;
		}
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
		{
			if (this != &src) {
				m_cnt = src.m_cnt;
				if (m_reservations != nullptr) {
					for (int i = 0; i < m_cnt; i++)
						delete m_reservations[i];
					delete[] m_reservations;
					m_reservations = nullptr;
				}
				m_reservations = new const Reservation * [m_cnt];
				for (int i = 0; i < m_cnt; i++)
					m_reservations[i] = src.m_reservations[i];
			}
			return *this;
		}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept
	{
		//move operator
		if (this != &src) {
			m_cnt = src.m_cnt;
			m_reservations = src.m_reservations;
			src.m_cnt = 0;
			src.m_reservations = nullptr;
		}
		return *this;

	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		//add reservation to the array
		bool found = false;
		for (int i = 0; i < m_cnt; i++) {
			if (m_reservations[i] == &res) {
				found = true;
				break;
			}
		}	
		if (!found) {
			const Reservation** temp = new const Reservation * [m_cnt + 1];
			for (int i = 0; i < m_cnt; i++)
				temp[i] = m_reservations[i];
			temp[m_cnt] = &res;
			m_cnt++;
			delete[] m_reservations;
			m_reservations = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		//remove reservation from the array
		bool found = false;
		int index = 0;
		for (int i = 0; i < m_cnt; i++) {
			if (m_reservations[i] == &res) {
				found = true;
				index = i;
				break;
			}
		}
		if (found) {
			const Reservation** temp = new const Reservation * [m_cnt - 1];
			for (int i = 0; i < index; i++)
				temp[i] = m_reservations[i];
			for (int i = index; i < m_cnt - 1; i++)
				temp[i] = m_reservations[i + 1];
			m_cnt--;
			delete[] m_reservations;
			m_reservations = temp;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (src.m_cnt == 0)
			os << "The object is empty!" << std::endl;
		else {
			for (int i = 0; i < src.m_cnt; i++)
				os << *src.m_reservations[i];
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}