#include "Racecar.h"

namespace sdds {

	sdds::Racecar::Racecar(std::istream& in) : Car(in) {
		in.seekg(std::ios::beg);
		std::string temp;
		std::getline(in, temp);
		temp = temp.substr(temp.find_last_of(',') + 1);
		trim(temp);
		m_booster = std::stod(temp);
	}

	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}

}