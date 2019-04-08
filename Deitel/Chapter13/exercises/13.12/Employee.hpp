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
#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#include "Date.hpp"

class Employee {
 public:
    Employee(const std::string&, const std::string&, const std::string&, Date);

    void setFirstName(const std::string&);
    std::string getFirstName() const;

    void setLastName(const std::string&);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string&);
    std::string getSocialSecurityNumber() const;

    void setBirthDate(int, int, int);
    Date getBirthDate() const;

    // pure virtual function makes Employee an abstract base class
    virtual double earnings() const = 0;  // pure virtual
    virtual void print() const;           // virtual

 private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;

    Date birthDate;
};
