/*
 * =====================================================================================
 *
 *       Filename:  ex_2021.cpp
 *
 *    Description:  Exercise 20.21 - Recursively Search a List
 *
 *        Version:  1.0
 *        Created:  07/09/17 16:10:10
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "List.hpp"

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    static const int LIMIT = 20;

    List<int> intList;
    int value = 0;

    printf("Enter %d ints: \n", LIMIT);
    for (int i = 0; i < LIMIT; ++i) {
        std::cin >> value;

        intList.insertAtBack(value);
    }

    std::cin.clear();
    std::cin.ignore(INT8_MAX, '\n');

    std::cout << "Enter value to find in list: ";
    std::cin >> value;

    ListNode<int>* res = intList.searchList(value);

    printf("%d%sfound\n", value, ((res == nullptr) ? " not " : " "));

    return 0;
}  // end method main
