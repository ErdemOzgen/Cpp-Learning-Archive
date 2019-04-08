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
#include <string>

class Employee {
 private:
    std::string firstName;
    std::string lastName;
    int monthlySalary;

 public:
    Employee(const std::string &, const std::string&, int);

    // SETTERS
    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setMonthlySalary(int);

    // GETTERS
    std::string getFirstName() const;
    std::string getLastName() const;
    int getMonthlySalary() const;
    int calculateSalary(int) const;

    void giveRaise(int);

    void showEmployee() const;
};
