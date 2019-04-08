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
#include <map>
#include <string>

int checkFile(std::istream&);  // return total phising point total
int checkWord(std::string);    // returns word point (0,1,2,3)

std::map<std::string, int> PHISING_LIST;

int main(int argc, const char* argv[]) {
    // open phising list
    std::ifstream plist("phising_list.txt", std::ios::in);

    if (!plist) {
        std::cerr << "could not open phising list." << std::endl;
        return 1;
    }

    // add list to vector
    std::string key;
    int value;

    while (plist >> key >> value) { PHISING_LIST[key] = value; }

    // ask for user file to scan
    std::string fname;
    std::cout << "Enter filename to scan: ";
    std::cin >> fname;

    std::ifstream inputfile(fname, std::ios::in);

    if (!inputfile) {
        std::cerr << "Unable to open input file" << std::endl;
        return 1;
    }

    std::cout << "The phising score for the file " << fname
              << " is: " << checkFile(inputfile) << std::endl;

    return 0;
}
// return total phising points for given file
int checkFile(std::istream& inputFile) {
    int score = 0;

    std::string word;
    while (inputFile >> word) {
        score += checkWord(word);
    }

    return score;
}
// return word point
int checkWord(std::string word) {
    for (auto it = PHISING_LIST.cbegin(); it != PHISING_LIST.cend(); ++it) {
        // remove trailing punctuation from word.
        if (ispunct(word[word.length() - 1])) { word.erase(word.length() - 1, 1); }

        if (it->first == word) { return it->second; }
    }

    return 0;
}
