/*
 * =====================================================================================
 *
 *       Filename:  ex_2009.cpp
 *
 *    Description:  Exercise 20.09 - Copying a List in Reverse Order
 *
 *        Version:  1.0
 *        Created:  13/06/17 12:12:56
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
    List<char> charList;
    List<char> charListRev;

    // populate base list
    for (char c = 'a'; c <= 'j'; ++c) {
        charList.insertAtBack(c);
    }

    // iterate over base insert at front on charListRev
    auto iter = charList.begin();

    while (iter != charList.end()) {
        charListRev.insertAtFront(iter->getData());

        iter = iter->next();

        if (iter == charList.end()) { charListRev.insertAtFront(iter->getData()); }
    }

    charList.print();
    std::cout << std::endl;
    charListRev.print();
    std::cout << std::endl;

    return 0;
}
