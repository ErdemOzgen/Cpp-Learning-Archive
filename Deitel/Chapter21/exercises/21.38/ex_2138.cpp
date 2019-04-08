/*
 * =============================================================================
 *
 *       Filename:  ex_2138.cpp
 *
 *    Description:  Exercise 21.38 - Tokenizing and Reversing a String.
 *
 *        Version:  1.0
 *        Created:  26/03/18 10:32:24
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
#include <cctype>

/**
 * Reverses the given string.
 * @param char*
 */
void reverseString(char* raw) {
    const char delim[2] = " ";

    int i = 0;
    int BLOCK_SIZE = 3;
    int current_size = BLOCK_SIZE;

    char** array = reinterpret_cast<char**>(calloc(current_size, sizeof(char*)));

    if (array == nullptr) { return; }

    char* token = strtok(raw, delim);

    while (token != nullptr) {
        array[i++] = strdup(token);

        if (i == current_size) {
            current_size += BLOCK_SIZE;
            char** ptr = reinterpret_cast<char**>(realloc(array, sizeof(*array) * current_size));

            if (ptr == nullptr) { break; }

            array = ptr;
        }
        token = strtok(nullptr, delim);
    }

    // initial decrement for null terminator
    for (--i; i >= 0; --i) { printf("%s ", array[i]); }

    std::cout << std::endl;

    free(array);
}  // end method reverseString

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    char raw[255];

    std::cout << "Enter a string: ";
    std::cin.getline(raw, 255);

    std::cout << "Your string reversed:" << std::endl;

    reverseString(raw);

    return 0;
}  // end method main
