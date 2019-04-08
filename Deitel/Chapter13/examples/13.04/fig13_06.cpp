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
    // create base-class object
    CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000,
                                          .06);

    // create base-class pointer
    CommissionEmployee *commissionEmployeePtr = 0;

    // create derived-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    // create dervied-class pointer
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

    // set floating-point output formatting
    std::cout << std::fixed << std::setprecision(2);

    // output objects using static binding
    std::cout << "Invoking print function on base-class and derived-class "
              << "\nobject with static binding\n\n";
    commissionEmployee.print();  // static binding
    std::cout << "\n\n";
    basePlusCommissionEmployee.print();  // static binding

    // output objects with dynamic binding
    std::cout << "\n\n\nInvoking print function on base-class and "
              << "derived-class \nobjects with dynamic binding";

    // aim base-class pointer at base-class object and print
    commissionEmployeePtr = &commissionEmployee;
    std::cout << "\n\nCalling virtual function print with derived-class "
              << "pointer\nto derived-class object invokes derived-class "
              << "print function:\n\n";
    basePlusCommissionEmployeePtr->print();

    // aim base-class pointer at derived-class object and print
    commissionEmployeePtr = &basePlusCommissionEmployee;
    std::cout << "\n\nCalling virtual function print with base-class pointer"
              << "\nto derived-class object invokes derived-class "
              << "print function:\n\n";

    // polymorphism; invokes BasePlusCommissionEmployee's print;
    // base-class pointer to derived-class object
    commissionEmployeePtr->print();

    std::cout << std::endl;

    return 0;
}
