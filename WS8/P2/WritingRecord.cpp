#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					//check if the salary is valid
					EmployeeWage* newEmp = new EmployeeWage(emp[i].name, sal[j].salary);
					if (emp.isValid(emp[i].id) && sal.isValid(sal[j].id)) {
						try {
							newEmp->rangeValidator();
						}
						catch (std::string err) {
							delete newEmp;
							throw err;
						}
						activeEmp += newEmp;
						delete newEmp;
					}
					else {
						delete newEmp;
						throw std::string("Invalid employee or salary record");

					}
				}
			}
		}
		return activeEmp;
	
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers

		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					//check if the salary is valid
					//EmployeeWage* newEmp = new EmployeeWage(emp[i].name, sal[j].salary);
					std::unique_ptr<EmployeeWage> newEmp(new EmployeeWage(emp[i].name, sal[j].salary));
					if (emp.isValid(emp[i].id) && sal.isValid(sal[j].id)) {
						try {
							newEmp->rangeValidator();
						}
						catch (std::string err) {
							newEmp.reset();
							throw err;
						}
						activeEmp += newEmp;
						newEmp.reset();
					}
					else {
						newEmp.reset();
						throw std::string("Invalid employee or salary record");

					}
				}
			}
		}
		return activeEmp;
	}
}