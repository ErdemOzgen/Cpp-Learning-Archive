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
#include "Employee.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    // no objects exist; use class name and binary scope resolution
    // operator to access static member function getCount
    std::cout << "Number of employees before instantiation of any objects is "
              << Employee::getCount() << std::endl;

    // the following scope creates and destroys
    // Employee objects before main terminates
    {
        Employee e1("Susan", "Baker");
        Employee e2("Robert", "Jones");

        // two objects exist; call static member function getCount again
        // using the class name and the scope resolution operator
        std::cout << "Number of employees after objects are instantiated is "
                  << Employee::getCount();

        std::cout << "\n\nEmployee 1: " << e1.getFirstName() << " "
                  << e1.getLastName() << "\nEmployee 2: " << e2.getFirstName()
                  << " " << e2.getLastName() << "\n\n";
    }

    // no objects exist, so call static member function getCount again
    // using the class name and the scope resolution operator
    std::cout << "\nNuimber of employees after objects are deleted is "
              << Employee::getCount() << std::endl;

    return 0;
}
