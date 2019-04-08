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

#include "Account.hpp"

class CheckingAccount : public Account {
 public:
    CheckingAccount(double, double);

    void credit(double);
    void debit(double);

 private:
    double feePerTransaction;
};
