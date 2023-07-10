#include <iostream>
#include <string>
#include <vector>

#include "Vehicle.h""
#include "Car.h"

#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_

namespace sdds {

	class Austoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Austoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
	};
};

#endif // !SDDS_AUTOSHOP_H_
