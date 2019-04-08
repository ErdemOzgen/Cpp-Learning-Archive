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
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, const char* argv[]) {
    // open oldmast.dat for input
    std::ifstream inOldMaster("oldmast.dat", std::ios::in);

    if (!inOldMaster) {
        std::cerr << "oldmast.dat could not be opened" << std::endl;
        return 0;
    }
    // open transaction file for input
    std::ifstream inTransaction("trans.dat", std::ios::in);

    if (!inTransaction) {
        std::cerr << "trans.dat could not be opened" << std::endl;
        return 0;
    }
    // open newmast.dat for output (and creation)
    std::ofstream outNewMaster("newmast.dat", std::ios::out);

    if (!outNewMaster) {
        std::cerr << "newmast.dat could not be created" << std::endl;
        return 0;
    }

    int transAccountNum = 0;
    int mastAccountNum = 0;
    double transDollarAmount;
    double mastDollarAmount;
    std::string fName;
    std::string lName;

    // handling files with one record
    inTransaction >> transAccountNum >> transDollarAmount;
    inOldMaster >> mastAccountNum >> fName >> lName >> mastDollarAmount;

    // process changes
    while (!inOldMaster.eof() && !inTransaction.eof()) {
         if (transAccountNum < mastAccountNum) {
            std::cout << "Unmatched transaction record for account number: "
                      << transAccountNum << std::endl;
            inTransaction >> transAccountNum >> transDollarAmount;
        } else if (transAccountNum == mastAccountNum) {
            do {
                mastDollarAmount += transDollarAmount;
                inTransaction >> transAccountNum >> transDollarAmount;
            } while (transAccountNum == mastAccountNum && !inTransaction.eof());
            outNewMaster << mastAccountNum << " " << fName << " " << lName
                         << " " << mastDollarAmount << std::endl;
            inOldMaster >> mastAccountNum >> fName >> lName >> mastDollarAmount;
        } else if (transAccountNum > mastAccountNum) {
            outNewMaster << mastAccountNum << " " << fName << " " << lName
                         << " " << mastDollarAmount << std::endl;
            inOldMaster >> mastAccountNum >> fName >> lName >> mastDollarAmount;
        }
    }

    // if trans.dat reachs to end of file before oldmast.dat
    while ( !inOldMaster.eof() ) {
        outNewMaster << mastAccountNum << " " << fName << " " << lName
                     << " " << mastDollarAmount << std::endl;
        inOldMaster >> mastAccountNum >> fName >> lName >> mastDollarAmount;
    }

    // if oldmast.dat reachs to end of file before trans.dat
    while ( !inTransaction.eof() ) {
        std::cout << "Unmatched transaction record for account number: "
                  << transAccountNum << std::endl;
            inTransaction >> transAccountNum >> transDollarAmount;
    }

    return 0;
}
