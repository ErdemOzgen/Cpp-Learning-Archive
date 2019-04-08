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

// constructor
Account::Account(int balance) {
    if (balance >= 0) {
        accountBalance = balance;
    } else {
        std::cout << "Error: Unable to initialise balance. Invalid entry." << std::endl;
    }
}
// GETTERS
int Account::getBalance() { return accountBalance; }

// Increase current balance by amount
void Account::credit(int amount) {
    if (amount > 0) { accountBalance += amount; }
}

// Decrease current balance by amount
void Account::debit(int amount) {
    if (amount <= accountBalance) { accountBalance -= amount; }
}
