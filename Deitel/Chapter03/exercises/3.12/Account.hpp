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

class Account {
 private:
    int accountBalance;

 public:
    explicit Account(int);//https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_73/rzarg/explicit_conversion_constructors.htm

    // GETTERS
    int getBalance();

    void credit(int);  // credit account
    void debit(int);   // debit account
};
