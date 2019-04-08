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
#include <typeinfo>
#include <vector>

int main(int argc, const char *argv[]) {
    // set floating-point output formatting
    std::cout << std::fixed << std::setprecision(2);

    // create vector of three base-class pointers
    std::vector<Employee *> employees(3);

    // Initialise vector with various kinds of Employees
    employees[0] = new SalariedEmployee("John", "Smi.hpp", "111-11-1111", 800);
    employees[1] =
        new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
    employees[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444",
                                                  5000, .04, 300);

    // polymorphically process each element in vector employees
    for (size_t i = 0; i < employees.size(); ++i) {
        employees[i]->print();  // output employee information
        std::cout << std::endl;

        // downcast pointer
        BasePlusCommissionEmployee *derivedPtr =
            dynamic_cast<BasePlusCommissionEmployee *>(employees[i]);

        // determine wheter element points to base-salaried
        // commission employee
        if (derivedPtr != 0) {  // 0 if not BasePlusCommissionEmployee
            double oldBaseSalary = derivedPtr->getBaseSalary();
            std::cout << "old base salary: $" << oldBaseSalary << std::endl;
            derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
            std::cout << "new base salary with 10% increase is: $"
                      << derivedPtr->getBaseSalary() << std::endl;
        }
        std::cout << "earned $" << employees[i]->earnings() << "\n\n";
    }

    // release object pointed to by vector's elements
    for (size_t j = 0; j < employees.size(); ++j) {
        // output class name
        std::cout << "deleting object of " << typeid(*employees[j]).name()
                  << std::endl;

        delete employees[j];
    }
    return 0;
}
