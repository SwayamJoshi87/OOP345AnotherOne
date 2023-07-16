#include "CrimeStatistics.h"

namespace sdds {

	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| " << std::setw(21) << std::left << theCrime.province << " | "
			<< std::setw(15) << std::left << theCrime.district << " | "
			<< std::setw(20) << std::left << theCrime.crime << " | "
			<< std::setw(6) << std::right << theCrime.year << " | "
			<< std::setw(4) << std::right << theCrime.numberOfCases << " | "
			<< std::setw(3) << std::right << theCrime.m_resolved << " |";
		return out;
	}

	

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
				crime.m_resolved = std::stoi(line.substr(85, 5));

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

	

	void sdds::CrimeStatistics::display(std::ostream& out) const {
		int totalCases = 0;
		int totalResolved = 0;
		std::for_each(m_crimes.begin(), m_crimes.end(), [&out, &totalCases, &totalResolved](const Crime& crime) {
			out << crime << '\n';
			totalCases += crime.numberOfCases;
			totalResolved += crime.m_resolved;
		});
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" << std::setw(80) << std::right << "Total Crimes:  " << totalCases << " |" << std::endl;
		out << "|" << std::setw(80) << std::right << "Total Resolved Cases:  " << totalResolved << " |" << std::endl;
		
	}

	// Sort the collection based on the specified field
	void sdds::CrimeStatistics::sort(const std::string& field) {
		if (field == "Province") {
			std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& a, const Crime& b) {
				return a.province < b.province;
				});
		}
		else if (field == "Crime") {
			std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& a, const Crime& b) {
				return a.crime < b.crime;
				});
		}
		else if (field == "Cases") {
			std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& a, const Crime& b) {
				return a.numberOfCases < b.numberOfCases;
				});
		}
		else if (field == "Resolved") {
			std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& a, const Crime& b) {
				return a.m_resolved < b.m_resolved;
				});
		}
	}
	
	// Remove [None] from the crime field for invalid crimes
	void sdds::CrimeStatistics::cleanList() {
		std::transform(m_crimes.begin(), m_crimes.end(), m_crimes.begin(), [](Crime& crime) {
			if (crime.crime == "[None]") {
				crime.crime = "";
			}
			return crime;
		});
	}

	// Check if the collection contains a record with the given crime
	bool sdds::CrimeStatistics::inCollection(const std::string& crimeName) const {
		return std::any_of(m_crimes.begin(), m_crimes.end(), [&crimeName](const Crime& crime) {
			return crime.crime == crimeName;
		});
	}

	// Get the list of crimes for the specified province
	std::list<Crime> sdds::CrimeStatistics::getListForProvince(const std::string& provinceName) const {
		std::list<Crime> provinceCrimes;

		std::copy_if(m_crimes.begin(), m_crimes.end(), std::back_inserter(provinceCrimes), [&provinceName](const Crime& crime) {
			return crime.province == provinceName;
			});

		return provinceCrimes;
	}

	
};

