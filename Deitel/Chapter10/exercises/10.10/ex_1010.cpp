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

#include "DeckOfCards.hpp"

int main(int argc, const char *argv[]) {
    DeckOfCards deck1;

    deck1.shuffle();

    while (deck1.moreCards()) {
        std::cout << deck1.dealCard().toString() << std::endl;
    }
    return 0;
}
