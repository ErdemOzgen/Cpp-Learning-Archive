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

#include <iomanip>
#include <iostream>

int main(int argc, const char *argv[]) {
    // create base class object
    CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000,
                                          .06);

    // create base class pointer
    CommissionEmployee *commissionEmployeePtr = 0;

    // create derived class object
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    // create derived class pointer
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

    // set floating-point output formatting
    std::cout << std::fixed << std::setprecision(2);

    // output objects commissionEmployee and basePlusCommissionEmployee
    std::cout << "Print base-class and derived-class objects:\n\n";
    commissionEmployee.print();
    std::cout << "\n\n";
    basePlusCommissionEmployee.print();

    // aim base-class pointer at base-class object and print
    commissionEmployeePtr = &commissonEmployee;
    std::cout << "\n\n\nCallint print with base-class pointer to "
              << "\nbase-class object invokes base-class print function:\n\n";
    commissionEmployeePtr->print();

    // aim derived-class pointer at derived-class object and print
    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    std::cout << "\n\n\nCallint print with derived-class pointer to "
              << "\nderived-class object invokes derived-class "
              << "print function:\n\n";
    basePlusCommissionEmployeePtr->print();

    // aim base-class pointer at derived-class object and print
    commissionEmployeePtr = &basePlusCommissionEmployee;
    std::cout << "\n\n\nCalling print with base-class pointer to "
              << "derived-class object\ninvokes base-class print "
              << "function on that derived-class object:\n\n";
    commissionEmployeePtr->print();

    std::cout << std::endl;

    return 0;
}
