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

#include <string>

class Employee {
 public:
    Employee(const std::string&, const std::string&);
    ~Employee();

    std::string getFirstName() const;
    std::string getLastName() const;

    static int getCount();

 private:
    std::string firstName;
    std::string lastName;

    static int count;
};
