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
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, const char *argv[]) {
    // ofstream constructor opens file
    std::ofstream outClientFile("clients.txt", std::ios::out);

    // exit program if unable to create file
    if (!outClientFile) {  // overloaded ! operator
        std::cerr << "File could not be opened" << std::endl;
        return 0;
    }

    std::cout << "Enter the account, name, and balance." << std::endl
              << "Enter end-of-file to end input.\n? ";

    int account;
    std::string name;
    double balance;

    // read account, name and balance from cin, then place in file
    while (std::cin >> account >> name >> balance) {
        outClientFile << account << ' ' << name << ' ' << balance << std::endl;
        std::cout << "? ";
    }

    return 0;
}
