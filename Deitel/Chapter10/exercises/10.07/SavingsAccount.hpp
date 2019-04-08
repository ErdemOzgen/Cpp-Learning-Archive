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

class SavingsAccount {
 public:
    explicit SavingsAccount(double, double = 0.0f);

    void calculateMonthlyInterest();

    static void modifyInterestRate(double);
    static double getInterestRate();

    friend std::ostream& operator<<(std::ostream& out, SavingsAccount acc) {
        return acc.printBalance(out);
    }

    std::ostream& printBalance(std::ostream&) const;

 private:
    static double annualInterestRate;
    double savingsBalance;
};
