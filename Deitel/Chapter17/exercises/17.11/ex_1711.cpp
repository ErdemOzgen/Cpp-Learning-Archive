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
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

struct Tool {
    int id = 0;
    char name[100];
    int quantity = 0;
    double cost = 0.0f;

    void setId(int ID) { id = ID; }
    void setName(std::string NAME) {
        std::memset(name, '\0', 100);

        int length = NAME.size();
        length = (length < 100 ? length : 99);

        NAME.copy(name, length);

        NAME[length] = '\0';
    }
    void setQuantity(int Q) { quantity = Q; }
    void setCost(double C) { cost = C; }
};

enum Choices { LIST = 1, UPDATE, NEW, DELETE, END };

void initialiseEmpty(std::fstream &);
int enterChoice();
void listRecords(std::fstream &);
void updateRecord(std::fstream &);
void newRecord(std::fstream &);
void deleteRecord(std::fstream &);
void printHeader();
void outputLine(std::ostream &, const Tool &);
int getToolId(const char *const);

int main(int argc, const char *argv[]) {
    std::fstream inOutHardware("hardware.dat",
                               std::ios::in | std::ios::out | std::ios::binary);

    // exit program if fstream cannot open file
    if (!inOutHardware) {
        std::cerr << "File could not be opened." << std::endl;
        return 1;
    }

    // initialiseEmpty(inOutHardware);

    int choice;

    while ((choice = enterChoice()) != END) {
        switch (choice) {
            case LIST:
                listRecords(inOutHardware);
                break;
            case UPDATE:
                updateRecord(inOutHardware);
                break;
            case NEW:
                newRecord(inOutHardware);
                break;
            case DELETE:
                deleteRecord(inOutHardware);
                break;
            default:
                std::cerr << "Incorrect choice" << std::endl;
                break;
        }
        inOutHardware.clear();  // reset end-of-file indicator
    }
    return 0;
}
// main menu
int enterChoice() {
    std::cout << "\nEnter your choice" << std::endl
              << "1 - List current records on file" << std::endl
              << "2 - Update a record" << std::endl
              << "3 - Add a new record" << std::endl
              << "4 - Delete a record" << std::endl
              << "5 - End program\n? ";

    int menuChoice;
    std::cin >> menuChoice;

    return menuChoice;
}
// initialises file to 100 empty records
void initialiseEmpty(std::fstream &inOutHardware) {
    Tool t;

    for (int i = 0; i < 100; ++i) {
        inOutHardware.write(reinterpret_cast<const char *>(&t), sizeof(Tool));
    }
}
// lists current records
void listRecords(std::fstream &inOutHardware) {
    printHeader();

    // set file-position pointer to beginning of file
    inOutHardware.seekg(0);

    Tool t;

    // read first record from file
    inOutHardware.read(reinterpret_cast<char *>(&t), sizeof(Tool));

    // read all records from file
    while (inOutHardware && !inOutHardware.eof()) {
        // display record
        if (t.id != 0) { outputLine(std::cout, t); }

        // read next from file
        inOutHardware.read(reinterpret_cast<char *>(&t), sizeof(Tool));
    }
}
// update any record in file
void updateRecord(std::fstream &inOutHardware) {
    // obtain record number
    int id = getToolId("Enter id of tool to update");

    // move file-position pointer to correct record in file
    inOutHardware.seekg((id - 1) * sizeof(Tool));

    // read first record from file
    Tool t;
    inOutHardware.read(reinterpret_cast<char *>(&t), sizeof(Tool));

    // update record
    if (t.id != 0) {
        // display the record
        printHeader();
        outputLine(std::cout, t);

        // request user to specify which information to change

        int choice = 0;

        do {
            std::cout << "\nSpecify information to change\n"
                      << "1 - Id" << std::endl
                      << "2 - Name" << std::endl
                      << "3 - Quantity" << std::endl
                      << "4 - Price" << std::endl
                      << "5 - Cancel Update\n? ";

            std::cin >> choice;
        } while (choice < 1 || choice > 5);

        switch (choice) {
            case 1: {  // id
                int id = getToolId("Enter new id");

                // check if id is available
                inOutHardware.seekg(0);
                // move file-postion pointer
                inOutHardware.seekg((id - 1) * sizeof(Tool));

                Tool t2;
                inOutHardware.read(reinterpret_cast<char *>(&t2), sizeof(Tool));

                if (t2.id == 0) {
                    std::cout << "update" << std::endl;
                    // delete old record of t (overrite with blank t2)

                    // move file-position pointer to correct record in file
                    inOutHardware.seekp((t.id - 1) * sizeof(Tool));

                    // write updated record over old record in file
                    inOutHardware.write(reinterpret_cast<const char *>(&t2),
                                        sizeof(Tool));

                    // change id of t
                    t.setId(id);
                } else {
                    std::cerr << "A record with id #" << t2.id
                              << " already exists" << std::endl;
                    return;
                }
            } break;
            case 2: {  // name
                std::string name;

                std::cin.ignore();  // skip leading '\n'
                std::cout << "Enter new Name: ";
                std::getline(std::cin, name);

                t.setName(name);
            } break;
            case 3: {  // quantity
                int quantity;

                std::cout << "Enter updated quantity: ";
                std::cin >> quantity;

                t.setQuantity(quantity);
            } break;
            case 4: {  // price
                double cost;

                std::cout << "Enter updated price: ";
                std::cin >> cost;

                t.setCost(cost);
            } break;
            case 5:  // exit
                return;
                break;
            default:
                std::cout << "Incorrect choice" << std::endl;
                return;
                break;
        }

        printHeader();
        outputLine(std::cout, t);

        // move file-position pointer to correct record in file
        inOutHardware.seekp((t.id - 1) * sizeof(Tool));

        // write updated record over old record in file
        inOutHardware.write(reinterpret_cast<const char *>(&t), sizeof(Tool));
    } else {
        std::cout << "\nRecord #" << id << " does not exist" << std::endl;
    }
}
// inserts a new record into the file
void newRecord(std::fstream &inOutHardware) {
    Tool t;

    int id = getToolId("Enter new tool id");

    // move file-position pointer to correct record in file
    inOutHardware.seekg((id - 1) * sizeof(Tool));

    // read record from file
    inOutHardware.read(reinterpret_cast<char *>(&t), sizeof(Tool));

    // create record if does not exist
    if (t.id == 0) {
        std::string name;
        int quantity;
        double cost;

        // enter name, quantity and cost
        std::cin.ignore();
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        std::cout << "Enter cost: ";
        std::cin >> cost;

        t.setId(id);
        t.setName(name);
        t.setQuantity(quantity);
        t.setCost(cost);

        // seek position in file of user-specified tool
        inOutHardware.seekp((t.id - 1) * sizeof(Tool));

        // write user specified information to file
        inOutHardware.write(reinterpret_cast<const char *>(&t), sizeof(Tool));
    } else {
        std::cerr << "Tool with id #" << id << " already exists." << std::endl;
    }
}
// delete record
void deleteRecord(std::fstream &inOutHardware) {
    // obtain account number to delte
    int id = getToolId("Enter tool id to delete");

    // move file-position pointer to correct record in file
    inOutHardware.seekg((id - 1) * sizeof(Tool));

    // read record from file
    Tool t;
    inOutHardware.read(reinterpret_cast<char *>(&t), sizeof(Tool));

    // delete record if exists
    if (t.id != 0) {
        Tool tBlank;

        inOutHardware.seekp((id - 1) * sizeof(Tool));

        // replace existing record with blank
        inOutHardware.write(reinterpret_cast<const char *>(&tBlank),
                            sizeof(Tool));

        std::cout << "Id #" << id << " deleted" << std::endl;
    } else {
        std::cerr << "Record with id #" << id << " does not exist."
                  << std::endl;
    }
}
// print list header
void printHeader() {
    std::cout << std::string(41, '-') << std::endl
              << std::left << std::setw(5) << "Id" << std::setw(16) << "Name"
              << std::setw(10) << "Quantity" << std::setw(10) << std::right
              << "Price" << std::endl
              << std::string(41, '-') << std::endl;
}
// display single record
void outputLine(std::ostream &output, const Tool &t) {
    output << std::left << std::setw(5) << t.id << std::setw(16) << t.name
           << std::setw(10) << t.quantity << std::setw(10)
           << std::setprecision(2) << std::right << std::fixed << std::showpoint
           << t.cost << std::endl;
}
// obtain record number from user
int getToolId(const char *const prompt) {
    int id;

    do {
        std::cout << prompt << " (1-100): ";
        std::cin >> id;
    } while (id < 1 || id > 100);

    return id;
}
