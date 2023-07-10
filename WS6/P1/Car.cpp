#include "Car.h"

namespace sdds {

	Car::Car()
	{
		m_maker = "";
		m_condition = Condition::New;
		m_topSpeed = 0;
	}

	Car::Car(std::istream& is)
	{
		std::string temp;
		getline(is, temp);
		m_maker = temp.substr(0, temp.find(','));
		trim(m_maker);
		temp.erase(0, temp.find(',') + 1);
		std::string temp1 = temp.substr(0, temp.find(','));
		trim(temp1);
		temp.erase(0, temp.find(',') + 1);
		m_condition = temp1[0] == 'n' || temp1[0] == 'N' ? Condition::New : temp1[0] == 'u' || temp1[0] == 'U' ? Condition::Used : temp1[0] == 'b' || temp1[0] == 'B' ? Condition::Broken : Condition::New;
		trim(temp);
		m_topSpeed = stoi(temp);
	}

	std::string Car::condition() const
	{
		return m_condition == Condition::New ? "new" : m_condition == Condition::Used ? "used" : m_condition == Condition::Broken ? "broken" : "";
	}

	double Car::topSpeed() const
	{
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| " << std::setw(10) << std::right << m_maker << " | " << std::setw(6) << std::left << condition() << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
};