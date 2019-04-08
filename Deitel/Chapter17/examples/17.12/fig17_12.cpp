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
#include "ClientData.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, const char* argv[]) {
    int accountNumber;
    std::string lastName;
    std::string firstName;
    double balance;

    std::fstream outCredit("credit.dat",
                           std::ios::in | std::ios::out | std::ios::binary);

    // exit program if fstream cannot open file
    if (!outCredit) {
        std::cerr << "File could not be opened." << std::endl;
        return 1;
    }

    std::cout << "Enter account number (1 to 100, 0 to end input)\n? ";

    // require user to specify account number
    ClientData client;
    std::cin >> accountNumber;

    // user enters information, which is copied into file
    while (accountNumber > 0 && accountNumber <= 100) {
        // user enters last name, first name and balance
        std::cout << "Enter lastname, firstname, balance\n? ";
        std::cin >> lastName;
        std::cin >> firstName;
        std::cin >> balance;

        // set record accountNumber, lastName, firstName and balance values
        client.setAccountNumber(accountNumber);
        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);

        // seek position in file of user-specified record
        outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));

        // write user-specified information in file
        outCredit.write(reinterpret_cast<const char*>(&client),
                        sizeof(ClientData));

        // enable user to enter another account
        std::cout << "Enter account number\n? ";
        std::cin >> accountNumber;
    }

    return 0;
}
