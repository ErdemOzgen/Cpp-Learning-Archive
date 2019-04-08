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
#include <iomanip>
#include <iostream>
#include <string>

enum CHOICES { LIST = 1, NEW, END };

char letters[8][4] = {{'A', 'B', 'C', ' '}, {'D', 'E', 'F', ' '},
                      {'G', 'H', 'I', ' '}, {'J', 'K', 'L', ' '},
                      {'M', 'N', 'O', ' '}, {'P', 'Q', 'R', 'S'},
                      {'T', 'U', 'V', ' '}, {'W', 'X', 'Y', 'Z'}};

int enterChoice();
std::string getNumber(const std::string&);
bool validate(const std::string&);
void generateWords(const std::string&);
void writeLine(const std::string&);

int main(int argc, const char* argv[]) {
    int choice;
    std::string number;

    while ((choice = enterChoice()) != END) {
        switch (choice) {
            case LIST:  // read last generated file
                break;
            case NEW:  // generate new list
                do {
                    number = getNumber(
                        "Enter a 7 digit telephone number (xxx-xxxx)");
                } while (!validate(number));

                generateWords(number);
                break;
            default:
                std::cerr << "Incorrect choice" << std::endl;
                break;
        }
    }
    return 0;
}
// main menu
int enterChoice() {
    std::cout << "\nEnter your choice" << std::endl
              << "1 - List last generated words" << std::endl
              << "2 - Generate new list" << std::endl
              << "3 - Exit\n? ";

    int choice;
    std::cin >> choice;

    return choice;
}
// get number
std::string getNumber(const std::string& prompt) {
    std::cout << prompt << ": ";

    std::string number;
    std::cin >> number;

    return number;
}
// validate given number
bool validate(const std::string& number) {
    if ((number.length() < 7) || (number.length() > 8) ||
        ((number.length() == 8) && (number[3] != '-'))) {
        return false;
    }

    // check range of individual digits
    for (const char& c : number) {
        if (c == '-') { continue; }

        if (((c - '0') < 2) || ((c - '0') > 9)) { return false; }
    }
    return true;
}
// generate list of words
void generateWords(const std::string& number) {
    std::ofstream outFile("phone.dat", std::ios::out);

    if (!outFile) {
        std::cerr << "phone.dat could not be opened" << std::endl;
        return;
    }

    std::string sanNum = "";

    // remove '-' from number
    if (number.length() == 8) {
        for (const char& c : number) {
            if (c == '-') { continue; }

            sanNum.push_back(c);
        }
    } else {
        sanNum = number;
    }

    // TODO(me): Anything other than this.
    for (int i = 0; i < 4; ++i) {
        if (letters[(sanNum[0] - '0') - 2][i] == ' ') { continue; }
        for (int j = 0; j < 4; ++j) {
            if (letters[(sanNum[1] - '0') - 2][j] == ' ') { continue; }
            for (int k = 0; k < 4; ++k) {
                if (letters[(sanNum[2] - '0') - 2][k] == ' ') { continue; }
                for (int l = 0; l < 4; ++l) {
                    if (letters[(sanNum[3] - '0') - 2][l] == ' ') { continue; }
                    for (int m = 0; m < 4; ++m) {
                        if (letters[(sanNum[4] - '0') - 2][m] == ' ') { continue; }
                        for (int n = 0; n < 4; ++n) {
                            if (letters[(sanNum[5] - '0') - 2][n] == ' ') { continue; }
                            for (int o = 0; o < 4; ++o) {
                                if (letters[(sanNum[6] - '0') - 2][o] == ' ') { continue; }

                                outFile << letters[(sanNum[0] - '0') - 2][i]
                                        << letters[(sanNum[1] - '0') - 2][j]
                                        << letters[(sanNum[2] - '0') - 2][k]
                                        << letters[(sanNum[3] - '0') - 2][l]
                                        << letters[(sanNum[4] - '0') - 2][m]
                                        << letters[(sanNum[5] - '0') - 2][n]
                                        << letters[(sanNum[6] - '0') - 2][o]
                                        << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}
