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

Employee::Employee(const std::string& first, const std::string& last,
                   const std::string& ssn, Date dob)
    : firstName(first),
      lastName(last),
      socialSecurityNumber(ssn),
      birthDate(dob) {}
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
// set birthDate
void Employee::setBirthDate(int m, int d, int y) { birthDate = Date(m, d, y); }
// get birthDate
Date Employee::getBirthDate() const { return birthDate; }
// Print Employee's information (virtual, but not pure virtual)
void Employee::print() const {
    std::cout << getFirstName() << ' ' << getLastName()
              << "\nDate of birth: " << birthDate
              << "\nsocial security number: " << getSocialSecurityNumber();
}
