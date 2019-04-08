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
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"

int main(int argc, const char *argv[]) {
    SavingsAccount sa(1000, .5);
    CheckingAccount ca(1000, 1.5);

    std::cout << "Savings Account initial balance: " << sa.getBalance();
    sa.credit(50);
    std::cout << "\ncredit 50: " << sa.getBalance();
    sa.debit(100);
    std::cout << "\ndebit 100: " << sa.getBalance()
              << "\nChecking Account initial balance: " << ca.getBalance();
    ca.credit(50);
    std::cout << "\ncredit 50: " << ca.getBalance();
    ca.debit(100);
    std::cout << "\ndebit 100: " << ca.getBalance() << std::endl;

    return 0;
}
