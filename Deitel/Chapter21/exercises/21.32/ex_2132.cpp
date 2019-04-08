/*
 * =============================================================================
 *
 *       Filename:  ex_2132.cpp
 *
 *    Description:  Exercise 21.32 - Comparing Strings
 *
 *        Version:  1.0
 *        Created:  19/03/18 15:41:28
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =============================================================================
 */
#include <iostream>
#include <cstring>

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    char str1[15] = "ABCDEF";
    char str2[15] = "abcdef";

    int result = strcmp(str1, str2);

    if (result == 0) {
        std::cout << "str1 == str2" << std::endl;
    } else {
        std::cout << str1 << ((result < 0) ? " < " : " > ") << str2 << std::endl;
    }

    return 0;
}  // end method main
