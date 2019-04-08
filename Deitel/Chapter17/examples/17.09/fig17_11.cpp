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
    std::ofstream outCredit("credit.dat", std::ios::out | std::ios::binary);

    // exit program if ofstream could not open file
    if (!outCredit) {
        std::cerr << "File could not be opened." << std::endl;
        return 1;
    }

    ClientData blankClient;  // constructor zeros out each data member

    // output 100 blank records to file
    for (int i = 0; i < 100; ++i) {
        outCredit.write(reinterpret_cast<const char*>(&blankClient),
                        sizeof(ClientData));
    }

    return 0;
}
