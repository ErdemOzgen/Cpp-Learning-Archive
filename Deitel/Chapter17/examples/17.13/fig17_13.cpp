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
#include <iomanip>
#include <iostream>

void outputLine(std::ostream &, const ClientData &);

int main(int argc, const char *argv[]) {
    std::ifstream inCredit("credit.dat", std::ios::in | std::ios::binary);

    // exit program if ifstream cannot open file
    if (!inCredit) {
        std::cerr << "File could not be opened." << std::endl;
        return 1;
    }

    std::cout << std::left << std::setw(10) << "Account" << std::setw(16)
              << "Last Name" << std::setw(11) << "First Name" << std::left
              << std::setw(10) << std::right << "Balanace" << std::endl;

    ClientData client;  // create record

    // read first record from file
    inCredit.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    // read all records from file
    while (inCredit && !inCredit.eof()) {
        // display record
        if (client.getAccountNumber() != 0) outputLine(std::cout, client);

        // read next from file
        inCredit.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
    }

    return 0;
}
// display single record
void outputLine(std::ostream &output, const ClientData &record) {
    output << std::left << std::setw(10) << record.getAccountNumber()
           << std::setw(16) << record.getLastName() << std::setw(11)
           << record.getFirstName() << std::setw(10) << std::setprecision(2)
           << std::right << std::fixed << std::showpoint << record.getBalance()
           << std::endl;
}
