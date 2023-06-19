#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"

#ifndef SDDS_CONFIRMATIONSENDER_H_
#define SDDS_CONFIRMATIONSENDER_H_

namespace sdds {
	class ConfirmationSender {
		const Reservation** m_reservations;
		size_t m_cnt;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src) noexcept;
		~ConfirmationSender();
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender& operator=(ConfirmationSender&& src) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src);
	};
}

#endif // !SDDS_CONFIRMATIONSENDER_H_

