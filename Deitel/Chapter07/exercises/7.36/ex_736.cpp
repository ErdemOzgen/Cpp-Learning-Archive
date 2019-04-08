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
#include <iostream>
#include <string>

void stringReverse(const std::string&, int start = -1);

int main(int argc, const char* argv[]) {
    std::cout << "Program to recursively print a string backwards" << std::endl;

    std::string string1 = "This is a string1";
    std::string string2 = "String 2 looks like this";

    std::cout << string1 << std::endl;
    stringReverse(string1, string1.length());

    std::cout << std::endl;

    std::cout << string2 << std::endl;
    stringReverse(string2);

    return 0;
}
// recursively prints a string in reverse
void stringReverse(const std::string& st, int start) {
    // account for lack of start index
    if (start == -1) { start = st.length(); }

    std::cout << st[start];

    // base case
    if (start == 0) {
        std::cout << std::endl;
        return;
    }

    stringReverse(st, --start);
}
