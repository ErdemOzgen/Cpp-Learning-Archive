/*
 * =============================================================================
 *
 *       Filename:  ex_2121.cpp
 *
 *    Description:  Exercise 21.21 - Searching for Characters.
 *
 *        Version:  1.0
 *        Created:  14/03/18 11:48:31
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
 * Finds the number of times needle occurs in haystack using strchr.
 * @param char*
 * @param char
 * @param int
 * @return int
 */
int findOccurances(char* haystack, char needle, int occurances = 0) {
    char* charPtr = strchr(haystack, needle);

    if (charPtr == nullptr) { return occurances; }

    return findOccurances(charPtr + 1, needle, ++occurances);
}  // end method findOccurances

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    char haystack[255];

    std::cout << "Enter string to be searched: ";
    std::cin.getline(haystack, 255);

    std::cout << "Enter char to search for: ";
    char needle = getchar();

    printf("\'%c\' occurs %d times in the given string.\n",
            needle, findOccurances(haystack, needle));

    return 0;
}  // end method main
