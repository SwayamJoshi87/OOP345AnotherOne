#include <iostream>
#include <string>

#include "Car.h"

#ifndef SDDS_RACECAR_H_
#define SDDS_RACECAR_H_

namespace sdds {

	class Racecar : public Car {
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};

}

#endif // !SDDS_RACECAR_H_
