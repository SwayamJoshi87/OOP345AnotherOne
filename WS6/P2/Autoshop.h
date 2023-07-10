#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Vehicle.h"
#include "Car.h"

#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_

namespace sdds {

	class Austoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Austoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		~Austoshop()
		{
			for (auto& i : m_vehicles)
				delete i;
		}

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto& i : m_vehicles)
			{
				if (test(i))
					vehicles.push_back(i);
			}
		}
	};
};

#endif // !SDDS_AUTOSHOP_H_
