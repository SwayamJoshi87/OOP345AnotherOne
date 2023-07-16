#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

#ifndef SDDS_CRIMESTATISTICS_H_
#define SDDS_CRIMESTATISTICS_H_

namespace sdds {

	struct Crime {
		std::string province;
		std::string district;
		std::string crime;
		int numberOfCases;
		int year;
		int numberOfResolvedCases;
	};

	class CrimeStatistics {
		//Collection of Crime objects
		std::vector<Crime> m_crimes;
	public:
		//Custom consdtructor with file name as parameter
		CrimeStatistics(const char* filename);
		//display
		void display(std::ostream& out)const;
		//friend helper function
		friend std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
	};

}


#endif // !SDDS_CRIMESTATISTICS_H_
