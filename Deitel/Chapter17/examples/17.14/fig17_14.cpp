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

int enterChoice();
void createTextFile(std::fstream &);
void updateRecord(std::fstream &);
void newRecord(std::fstream &);
void deleteRecord(std::fstream &);
void outputLine(std::ostream &, const ClientData &);
int getAccount(const char *const);

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };

int main(int argc, const char *argv[]) {
    // open file for reading and writing
    std::fstream inOutCredit("credit.dat",
                             std::ios::in | std::ios::out | std::ios::binary);

    // exit program if fstream cannot open file
    if (!inOutCredit) {
        std::cerr << "File could not be opened." << std::endl;
        return 1;
    }

    int choice;  // store user choice

    // enable user to specify action
    while ((choice = enterChoice()) != END) {
        switch (choice) {
            case PRINT:  // create text file from record file
                createTextFile(inOutCredit);
                break;
            case UPDATE:  // update record
                updateRecord(inOutCredit);
                break;
            case NEW:  // create record
                newRecord(inOutCredit);
                break;
            case DELETE:  // delete existing record
                deleteRecord(inOutCredit);
                break;
            default:  // display error if user does not select valid choice
                std::cerr << "Incorrect choice" << std::endl;
                break;
        }
    }

    inOutCredit.clear();  // reset end-of-file indicator

    return 0;
}
// enable user to input menu choice
int enterChoice() {
    // display available options
    std::cout << "\nEnter you choice" << std::endl
              << "1 - store a formatted text file of accounts" << std::endl
              << "    called \"print.txt\" for printing" << std::endl
              << "2 - update an account" << std::endl
              << "3 - add a new account" << std::endl
              << "4 - delete an account" << std::endl
              << "5 - end program\n? ";

    int menuChoice;

    std::cin >> menuChoice;  // input menu selection from user

    return menuChoice;
}
// create formatted text file for printing
void createTextFile(std::fstream &readFromFile) {
    // create text file
    std::ofstream outPrintFile("print.txt", std::ios::out);

    // exit program if ofstream cannot create file
    if (!outPrintFile) {
        std::cerr << "File could not be created" << std::endl;
        return;
    }

    outPrintFile << std::left << std::setw(10) << "Account" << std::setw(16)
                 << "Last Name" << std::setw(11) << "First Name" << std::right
                 << std::setw(10) << "Balance" << std::endl;

    // set file-position pointer to beginning of readFromFile
    readFromFile.seekg(0);

    // read first record from record file
    ClientData client;
    readFromFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    // copy all record from record file into text file
    while (!readFromFile.eof()) {
        // write single record to text file
        if (client.getAccountNumber() != 0)  // skip empty records
            outputLine(outPrintFile, client);

        // read next record from record file
        readFromFile.read(reinterpret_cast<char *>(&client),
                          sizeof(ClientData));
    }
}
// update balance in record
void updateRecord(std::fstream &updateFile) {
    // obtain number of account to update
    int accountNumber = getAccount("Enter account to update");

    // move file-position pointer to correct record in file
    updateFile.seekg((accountNumber - 1) * sizeof(ClientData));

    // read first record from file
    ClientData client;
    updateFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    // update record
    if (client.getAccountNumber() != 0) {
        outputLine(std::cout, client);  // display the record

        // request user to specify the transaction
        std::cout << "\nEnter charge (+) or payment (-): ";
        double transaction;  // char or payment
        std::cin >> transaction;

        // update record balance
        double oldBalance = client.getBalance();
        client.setBalance(oldBalance + transaction);
        outputLine(std::cout, client);  // display the record

        // move file-position pointer to correct record in file
        updateFile.seekp((accountNumber - 1) * sizeof(ClientData));

        // write updated record over old record in file
        updateFile.write(reinterpret_cast<const char *>(&client),
                         sizeof(ClientData));
    } else {  // display error if account does not exist
        std::cerr << "Account #" << accountNumber << " has no information."
                  << std::endl;
    }
}
// create and insert record
void newRecord(std::fstream &insertInFile) {
    // obtain number of accounts to create
    int accountNumber = getAccount("Enter new account number");

    // move file-position pointer to correct record in file
    insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));

    // read record from file
    ClientData client;
    insertInFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    // create record, if record does not previously exist
    if (client.getAccountNumber() == 0) {
        std::string lastName;
        std::string firstName;
        double balance;

        // user enters last name, first name, and balance
        std::cout << "Enter lastname, firstname, balance\n? ";
        std::cin >> std::setw(15) >> lastName;
        std::cin >> std::setw(10) >> firstName;
        std::cin >> balance;

        // user values to populate account values
        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);
        client.setAccountNumber(accountNumber);

        // move file-position pointer to correct record in file
        insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));

        // insert record in file
        insertInFile.write(reinterpret_cast<const char *>(&client),
                           sizeof(ClientData));
    } else {  // display error if account already exists
        std::cerr << "Account #" << accountNumber
                  << " already contains information." << std::endl;
    }
}
// delete an existing record
void deleteRecord(std::fstream &deleteFromFile) {
    // obtain number of account to delete
    int accountNumber = getAccount("Enter account to delete");

    // move file-position pointer to correct record in file
    deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));

    // read record from file
    ClientData client;
    deleteFromFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    // delete record, if record exists in file
    if (client.getAccountNumber() != 0) {
        ClientData blankClient;  // create blank record

        // move file-position pointer to correct record in file
        deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));

        // replace existing record with blank record
        deleteFromFile.write(reinterpret_cast<const char *>(&blankClient),
                             sizeof(ClientData));

        std::cout << "Account #" << accountNumber << " deleted.\n";
    } else {  // display error if record does not exist
        std::cerr << "Account #" << accountNumber << " is empty.\n";
    }
}
// display single record
void outputLine(std::ostream &output, const ClientData &record) {
    output << std::left << std::setw(10) << record.getAccountNumber()
           << std::setw(16) << record.getLastName() << std::setw(11)
           << record.getFirstName() << std::setw(10) << std::setprecision(2)
           << std::right << std::fixed << std::showpoint << record.getBalance()
           << std::endl;
}
// obtain account number value from user
int getAccount(const char *const prompt) {
    int accountNumber;

    // obtain account number value
    do {
        std::cout << prompt << " ( 1 - 100 ): ";
        std::cin >> accountNumber;
    } while (accountNumber < 1 || accountNumber > 100);

    return accountNumber;
}
