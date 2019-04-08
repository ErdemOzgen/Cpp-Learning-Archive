/*
 * =====================================================================================
 *
 *       Filename:  SavingsAccount.hpp
 *
 *    Description:  Exercise 12.10 - Account Inheritance Hierarchy
 *
 *        Version:  1.0
 *        Created:  24/07/16 20:27:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "Account.hpp"

class SavingsAccount : public Account {
 public:
    SavingsAccount(double, double);

    double calculateInterest() const;

    void credit(double);
    bool debit(double);

 private:
    double interestRate;
};
