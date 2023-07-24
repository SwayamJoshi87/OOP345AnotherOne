#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's

		bool isValid(const std::string sin) const {
			if (sin.size() != 9) {
				return false; // SIN must be exactly 9 characters long
			}

			int sum = 0;
			bool alternate = false;

			for (int i = 8; i >= 0; i--) {
				if (sin[i] < '0' || sin[i] > '9') {
					return false; // SIN must contain only digits
				}

				int digit = sin[i] - '0';

				if (alternate) {
					digit *= 2;
					if (digit > 9) {
						digit -= 9;
					}
				}

				sum += digit;
				alternate = !alternate;
			}

			return sum % 10 == 0;
		}


		//TODO: Overload the += operator with a raw pointer
		// as a second operand.

		void operator+=(const T* t) {
				list.push_back(*t);
		}


		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
