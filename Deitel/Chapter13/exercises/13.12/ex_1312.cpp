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
#include <iomanip>
#include <iostream>
#include <vector>

#include "BasePlusCommissionEmployee.hpp"
#include "CommissionEmployee.hpp"
#include "Date.hpp"
#include "Employee.hpp"
#include "SalariedEmployee.hpp"

int main(int argc, const char *argv[]) {
    // set floating-point output formatting
    std::cout << std::fixed << std::setprecision(2);

    SalariedEmployee salariedEmployee("John", "Smi.hpp", "111-11-1111",
                                      Date(5, 13, 1975), 800);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333",
                                          Date(6, 18, 1985), 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "444-44-4444", Date(8, 25, 1954), 5000, .04, 300);

    // create vector of three base-class pointers
    std::vector<Employee *> employees(3);

    // initialise vector with Employees
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;

    int currMonth = 0;

    std::cout << "Enter current month (1-12): ";
    std::cin >> currMonth;

    for (size_t i = 0; i < employees.size(); ++i) {
        employees[i]->print();
        std::cout << "\nearned $"
                  << ((employees[i]->getBirthDate().getMonth() == currMonth)
                          ? 100
                          : 0) +
                         employees[i]->earnings();
        std::cout << "\n\n";
    }

    return 0;
}
