#include <iostream>
#include "Reservation.h"

#ifndef SDDS_RESTAURANT_H_
#define SDDS_RESTAURANT_H_

namespace sdds {
	class Restaurant {
		Reservation** m_reservations;
		size_t m_numOfReservations;
		static unsigned int CALL_CNT;
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size() const;
		~Restaurant();
		//Friend helper function
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
		//Copy and move constructors
Restaurant(const Restaurant& src);
Restaurant(Restaurant&& src) noexcept;
		//Copy and move assignment operators
Restaurant& operator=(const Restaurant& src);
Restaurant& operator=(Restaurant&& src) noexcept;
	};
}

#endif // !SDDS_RESTAURANT_H_


