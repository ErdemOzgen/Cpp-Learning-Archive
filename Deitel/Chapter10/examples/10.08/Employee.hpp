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

#include "Date.hpp"

#include <string>

class Employee {
 public:
    Employee(const std::string&, const std::string&, const Date&, const Date&);
    ~Employee();

    void print() const;

 private:
    std::string firstName;
    std::string lastName;
    const Date birthDate;
    const Date hireDate;
};
