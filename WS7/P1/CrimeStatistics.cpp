#include "CrimeStatistics.h"

namespace sdds {

	sdds::CrimeStatistics::CrimeStatistics(const char* filename)
	{
		std::ifstream file(filename);
		if(!file){
			throw "bad file name!";
		}
		else
		{
			std::string line;
			while (std::getline(file, line, '\n')) {
				Crime crime;

				// Extracting data from fixed-size fields
				crime.province = line.substr(0, 25);
				crime.district = line.substr(25, 25);
				crime.crime = line.substr(50, 25);
				crime.year = std::stoi(line.substr(75, 5));
				crime.numberOfCases = std::stoi(line.substr(80, 5));
				crime.numberOfResolvedCases = std::stoi(line.substr(85, 5));

				// Remove leading and trailing whitespace from each field
				crime.province = crime.province.substr(crime.province.find_first_not_of(' '));
				crime.province = crime.province.substr(0, crime.province.find_last_not_of(' ') + 1);

				crime.district = crime.district.substr(crime.district.find_first_not_of(' '));
				crime.district = crime.district.substr(0, crime.district.find_last_not_of(' ') + 1);

				crime.crime = crime.crime.substr(crime.crime.find_first_not_of(' '));
				crime.crime = crime.crime.substr(0, crime.crime.find_last_not_of(' ') + 1);

				// Add the extracted crime to the collection
				m_crimes.push_back(crime);
			}
			
		}
	}

	// Overload << operator to display Crime object
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime) {
		out << "| " << std::setw(21) << std::left << theCrime.province << " | "
			<< std::setw(15) << std::left << theCrime.district << " | "
			<< std::setw(20) << std::left << theCrime.crime << " | "
			<< std::setw(6) << std::right << theCrime.year << " | "
			<< std::setw(4) << std::right << theCrime.numberOfCases << " | "
			<< std::setw(3) << std::right << theCrime.numberOfResolvedCases << " |";
		return out;
	}

	void sdds::CrimeStatistics::display(std::ostream& out) const {
		std::for_each(m_crimes.begin(), m_crimes.end(), [&out](const Crime& crime) {
			out << crime << '\n';
			});
	}

	
	
};

