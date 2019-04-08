/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include "BasePlusCommissionEmployee.hpp"
#include "CommissionEmployee.hpp"
#include "Employee.hpp"
#include "SalariedEmployee.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

void virtualViaPointer(const Employee* const);  // prototype
void virtualViaReference(const Employee&);      // prototype

int main(int argc, const char* argv[]) {
    // set floating-point output formatting
    std::cout << std::fixed << std::setprecision(2);

    // create derived-class objects
    SalariedEmployee salariedEmployee("John", "Smi.hpp", "111-11-1111", 800);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000,
                                          .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "444-44-4444", 5000, .04, 300);

    std::cout << "Employees processed individually using static binding:\n\n";

    // output each Employee's information and earnings using static binding
    salariedEmployee.print();
    std::cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    std::cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    std::cout << "\n\nearned $" << basePlusCommissionEmployee.earnings()
              << "\n\n";

    // create vector of three base-class pointers
    std::vector<Employee*> employees(3);

    // initialise vector with Employees
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;

    std::cout << "Employees processed polymorphically via dynamic binding:\n\n";

    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding
    std::cout << "Virtual function call made off base-class pointers:\n\n";

    for (size_t i = 0; i < employees.size(); ++i) {
        virtualViaPointer(employees[i]);
    }

    // call virtualViaReference to print each Employee's information
    // and earnings using dynamic binding
    std::cout << "Virtual function calls made off base-class references:\n\n";

    for (size_t i = 0; i < employees.size(); ++i) {
        virtualViaReference(*employees[i]);  // not dereferencing
    }

    return 0;
}
// call Employee virtual functions print and earnings off a
// base-class pointer using dynamic binding
void virtualViaPointer(const Employee* const baseClassPtr) {
    baseClassPtr->print();
    std::cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}
// call Employee virtual function print and earnings off a
// base-class reference using dynamic binding
void virtualViaReference(const Employee& baseClassRef) {
    baseClassRef.print();
    std::cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
}
