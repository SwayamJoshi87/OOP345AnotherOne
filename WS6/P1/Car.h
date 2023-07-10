#include <iostream>
#include <string>
#include <iomanip>

#include "Vehicle.h"
#include "Utilities.h"

#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

namespace sdds
{

	enum class Condition
	{
		New,
		Used,
		Broken
	};

	class Car : public Vehicle
	{
		std::string m_maker = "";
		Condition m_condition = Condition::New;
		double m_topSpeed = 0.0;
	public:
		Car();
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		~Car() = default;
	};
}

#endif // !SDDS_CAR_H_
