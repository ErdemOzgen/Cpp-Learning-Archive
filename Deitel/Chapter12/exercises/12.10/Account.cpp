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
#include <iostream>

#include "Account.hpp"

Account::Account(double b) : balance(0) {
    if (b >= 0.0f) {
        balance = b;
    } else {
        std::cout << "ERROR: invalid balance. Defaulting to zero.";
    }
}
// credit
void Account::credit(double c) {
    if (c >= 0.0f) {
        balance += c;
    } else {
        std::cout << "ERROR: Cannot credit negative amount. Balance unchanged.";
    }
}
// debit
bool Account::debit(double d) {
    if (d >= 0.0f) {
        if (d <= balance) {
            balance -= d;
            return true;
        } else {
            return false;
        }
    }
    std::cout << "ERROR: Cannot debit negative amount. Balance unchanged.";
    return false;
}
