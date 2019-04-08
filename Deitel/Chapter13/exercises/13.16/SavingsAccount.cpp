/*
 * =====================================================================================
 *
 *       Filename:  SavingsAccount.cpp
 *
 *    Description:  Exercise 12.10 - Account Inheritance Hierarchy
 *
 *        Version:  1.0
 *        Created:  24/07/16 20:28:01
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(double b, double ir)
    : Account(b), interestRate(ir) {
    Account::setAccountType("savings");
}
// calculate interest
double SavingsAccount::calculateInterest() const {
    return Account::getBalance() * interestRate;
}
void SavingsAccount::credit(double c) {
    Account::credit(calculateInterest() + c);
}
bool SavingsAccount::debit(double d) {
    if (!Account::debit(d)) {
        std::cout << "Error. Insufficient funds in savings account"
                  << std::endl;
        return false;
    }
    return true;
}
