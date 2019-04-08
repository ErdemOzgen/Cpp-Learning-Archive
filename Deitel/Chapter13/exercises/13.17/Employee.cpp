/*
 * =====================================================================================
 *
 *       Filename:  Employee.cpp
 *
 *    Description:  Fig. 13.10: Abstract-base-class Employee member-function
 *                  definitions.
 *                  Note: No definitions are given for pure virtual functions.
 *
 *        Version:  1.0
 *        Created:  12/08/16 19:23:10
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

#include "Employee.hpp"

Employee::Employee(const std::string& first, const std::string& last,
                   const std::string& ssn)
    : firstName(first), lastName(last), socialSecurityNumber(ssn) {}
// set first name
void Employee::setFirstName(const std::string& first) { firstName = first; }
// get first name
std::string Employee::getFirstName() const { return firstName; }
// set last name
void Employee::setLastName(const std::string& last) { lastName = last; }
// get last name
std::string Employee::getLastName() const { return lastName; }
// set social security number
void Employee::setSocialSecurityNumber(const std::string& ssn) {
    socialSecurityNumber = ssn;  // should validate
}
// get social security number
std::string Employee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}
// Print Employee's information (virtual, but not pure virtual)
void Employee::print() const {
    std::cout << getFirstName() << ' ' << getLastName()
              << "\nSocial Security Number: " << getSocialSecurityNumber();
}
