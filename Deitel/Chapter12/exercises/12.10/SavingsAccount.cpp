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
#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(double b, double ir)
    : Account(b), interestRate(ir) {}
// calculate interest
double SavingsAccount::calculateInterest() const {
    return Account::getBalance() * interestRate;
}
