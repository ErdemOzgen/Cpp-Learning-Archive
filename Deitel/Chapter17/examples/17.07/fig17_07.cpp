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
#include <iomanip>
#include <iostream>
#include <string>

enum requestType { ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END };
int getRequest();
bool shouldDisplay(int, double);
void outputLine(int, const std::string, double);

int main(int argc, const char* argv[]) {
    // ifstream constructor opens the file
    std::ifstream inClientFile("clients.txt", std::ios::in);

    // exit program if ifstream could not open file
    if (!inClientFile) {
        std::cerr << "file could not be opened" << std::endl;
        return 1;
    }

    int request;
    int account;
    std::string name;
    double balance;

    // get user's request (e.g., zero, credit or debit balance)
    request = getRequest();

    // process user's request
    while (request != END) {
        switch (request) {
            case ZERO_BALANCE:
                std::cout << "\nAccounts with zero balances:\n";
                break;
            case CREDIT_BALANCE:
                std::cout << "\nAccounts with credit balances:\n";
                break;
            case DEBIT_BALANCE:
                std::cout << "\nAccounts with debit balances:\n";
                break;
        }  // end switch

        // read account, name and balance from file
        inClientFile >> account >> name >> balance;

        // display file contents (until eof)
        while (!inClientFile.eof()) {
            // display record
            if (shouldDisplay(request, balance))
                outputLine(account, name, balance);

            // read account, name and balance from file
            inClientFile >> account >> name >> balance;
        }  // end innner while

        inClientFile.clear();   // reset eof for next input
        inClientFile.seekg(0);  // reposition to beginning of file
        request = getRequest();
    }  // end outer while

    std::cout << "End of run." << std::endl;

    return 0;
}
// obtain request from user
int getRequest() {
    int request;

    // display request options
    std::cout << "\nEnter request" << std::endl
              << " 1 - List accounts with zero balances" << std::endl
              << " 2 - List accounts with credit balancs" << std::endl
              << " 3 - List accounts with debit balances" << std::endl
              << " 4 - End of run" << std::fixed << std::showpoint;

    do {
        std::cout << "\n? ";
        std::cin >> request;
    } while (request < ZERO_BALANCE && request > END);

    return request;
}
// determine whether to display given record
bool shouldDisplay(int type, double balance) {
    // determine whether to display zero balances
    if (type == ZERO_BALANCE && balance == 0) return true;

    // determine whether to display credit balances
    if (type == CREDIT_BALANCE && balance < 0) return true;

    // determine whether to display debit balances
    if (type == DEBIT_BALANCE && balance > 0) return true;

    return false;
}
// display single record from file
void outputLine(int account, const std::string name, double balance) {
    std::cout << std::left << std::setw(10) << account << std::setw(13) << name
              << std::setw(7) << std::setprecision(2) << std::right << balance
              << std::endl;
}
