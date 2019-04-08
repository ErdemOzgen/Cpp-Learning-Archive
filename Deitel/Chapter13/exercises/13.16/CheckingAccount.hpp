/*
 * =====================================================================================
 *
 *       Filename:  CheckingAccount.hpp
 *
 *    Description:  Exercise 12.10 - Account Inheritance Hierarchy
 *
 *        Version:  1.0
 *        Created:  24/07/16 20:28:04
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

class CheckingAccount : public Account {
 public:
    CheckingAccount(double, double);

    void credit(double);
    bool debit(double);

 private:
    double feePerTransaction;
};
