#include <string>
#include <sstream>
#include <iostream>

#include "Vehicle.h"

#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_

namespace sdds {

	Vehicle* createInstance(std::istream& in);
	std::string& trim(std::string& str);

};

#endif // !SDDS_UTILITIES_H_
