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

class CreditLimits {
 private:
    int accountNumber = 0;
    double beginningBalance = 0.0f;
    double newBalance = 0.0f;
    double totalMonthCharges = 0.0f;
    double totalMonthCredit = 0.0f;
    double creditLimit = 0.0f;

 public:
    CreditLimits();
    ~CreditLimits();

    // SETTERS
    void setAccountNumber(int);
    void setBeginningBalance(double);
    void setNewBalance();
    void setTotalMonthCharges(double);
    void setTotalMonthCredit(double);
    void setCreditLimit(double);

    // GETTERS
    int getAccountNumber() const;
    double getBeginningBalance() const;
    double getNewBalance() const;
    double getTotalMonthCharges() const;
    double getTotalMonthCredit() const;
    double getCreditLimit() const;

    bool isCreditLimitExceeded() const;

    void run();
    void printInfo() const;
};
