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

// define and initialise static data member at global namespace scope
int Employee::count = 0;

// define static member function that returns number of
// Employee objects instantiated (declared static in Employee.h)
int Employee::getCount() { return count; }

// constructor initialises non-static data members and
// increments static data member count
Employee::Employee(const std::string& first, const std::string& last)
    : firstName(first), lastName(last) {
    ++count;

    std::cout << "Employee constructor for " << firstName << ' ' << lastName
              << " called." << std::endl;
}
// destructor deallocates dynamically allocated memory
Employee::~Employee() {
    std::cout << "~Employee() called for " << firstName << ' ' << lastName
              << std::endl;

    --count;
}
// GETTERS
std::string Employee::getFirstName() const { return firstName; }
std::string Employee::getLastName() const { return lastName; }
