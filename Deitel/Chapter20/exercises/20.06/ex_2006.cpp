/*
 * =====================================================================================
 *
 *       Filename:  ex_2006.cpp
 *
 *    Description:  Exercise 20.06 - Concatenating Lists
 *
 *        Version:  1.0
 *        Created:  17/03/17 15:50:14
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "List.hpp"

int main(int argc, const char* argv[]) {
    List<char> charList1;
    List<char> charList2;

    for (char c = 'a'; c <= 'z'; ++c) {
        if (c < 'n') {
            charList1.insertAtBack(c);
        } else {
            charList2.insertAtBack(c);
        }
    }

    std::cout << "List 1 : ";
    charList1.print();
    std::cout << "size : " << charList1.size() << "\nList 2 : ";
    charList2.print();
    std::cout << "size : " << charList2.size() << std::endl;

    charList1.concatenate(charList2);

    std::cout << "List 1 after concatenate: ";
    charList1.print();
    std::cout << " size : " << charList1.size() << std::endl;

    return 0;
}
