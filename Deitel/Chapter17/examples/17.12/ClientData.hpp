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

#include <string>

class ClientData {
 public:
    // default ClientData constructor
    ClientData(int = 0, std::string = "", std::string = "", double = 0.0f);

    // accessor functions for accountNumber
    void setAccountNumber(int);
    int getAccountNumber() const;

    // accesssor functions for lastName
    void setLastName(std::string);
    std::string getLastName() const;

    // accessor functions for firstName
    void setFirstName(std::string);
    std::string getFirstName() const;

    // accessor functions for balance
    void setBalance(double);
    double getBalance() const;

 private:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
};
