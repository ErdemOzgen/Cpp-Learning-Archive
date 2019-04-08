/*
 * =====================================================================================
 *
 *       Filename:  ex_1316.cpp
 *
 *    Description:  Exercise 13.16 - Polymorphic Banking Program Using Account
 *                  Hierarchy.
 *
 *        Version:  1.0
 *        Created:  01/09/16 17:50:34
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

#include "Account.hpp"
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"

int main(int argc, const char *argv[]) {
    std::vector<Account *> accounts;

    accounts.push_back(new SavingsAccount(1000, .5));
    accounts.push_back(new CheckingAccount(1000, 1.5));

    for (std::size_t i = 0; i < accounts.size(); ++i) {
        double cd = 0;

        std::cout << "\nAccount " << i + 1 << std::endl;
        std::cout << "Initial balance: $" << accounts[i]->getBalance()
                  << std::endl;

        std::cout << "\nEnter credit ammount: ";
        std::cin >> cd;

        accounts[i]->credit(cd);

        std::cout << "Enter debit ammount: ";
        std::cin >> cd;

        accounts[i]->debit(cd);

        std::cout << "\nFinal balance: $" << accounts[i]->getBalance()
                  << std::endl;
    }

    for (std::size_t i = 0; i < accounts.size(); ++i) {
        delete accounts[i];
    }
    return 0;
}
