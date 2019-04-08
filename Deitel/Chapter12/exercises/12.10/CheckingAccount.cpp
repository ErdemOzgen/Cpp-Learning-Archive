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

#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(double b, double fpt)
    : Account(b), feePerTransaction(fpt) {}
// credit
void CheckingAccount::credit(double c) {
    Account::credit(c + feePerTransaction);
}
// debit
void CheckingAccount::debit(double d) {
    if (Account::debit(d)) {
        Account::debit(feePerTransaction);
    } else {
        std::cout << "Error insufficient funds in checking account";
    }
}
