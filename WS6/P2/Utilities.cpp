#include "Utilities.h"
#include "Racecar.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in)
    {
        //use string stream
        std::string temp = "";
        std::getline(in, temp);
        std::stringstream ss(temp);
		std::string type;
		std::getline(ss, type, ',');
		trim(type);
		if (type == "c" || type == "C")
		{
			return new sdds::Car(ss);
		}
		else if (type == "r" || type == "R")
		{
			return new Racecar(ss);
		}
		else if(type != "c" && type != "C" && type != "r" && type != "R" && type != "")
		{
			//throw unrecognised record type along with [type]
			throw std::string("Unrecognized record type: [") + type + std::string("]");

		}
		else {
			return nullptr;
		}
    }
    std::string& trim(std::string& str)
    {
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
		return str;
    }

};
