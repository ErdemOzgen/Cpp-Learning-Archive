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
#include "Date.hpp"

#include <iostream>

Employee::Employee(const std::string& first, const std::string& last,
                   const Date& dateOfBirth, const Date& dateOfHire)
    : firstName(first),
      lastName(last),
      birthDate(dateOfBirth),
      hireDate(dateOfHire) {
    // output Emplotee object to show when constructor is called
    std::cout << "Employee object constructor: " << firstName << ' ' << lastName
              << std::endl;
}
Employee::~Employee() {
    std::cout << "Employee object destructor : " << lastName << ' ' << firstName
              << std::endl;
}
// print Employee object
void Employee::print() const {
    std::cout << lastName << ", " << firstName << " Hired: ";
    hireDate.print();
    std::cout << " Birthday: ";
    birthDate.print();
    std::cout << std::endl;
}
