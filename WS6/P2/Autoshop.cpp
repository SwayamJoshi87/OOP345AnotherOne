#include "Autoshop.h"

namespace sdds {

	Austoshop& sdds::Austoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void sdds::Austoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			(*i)->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

};