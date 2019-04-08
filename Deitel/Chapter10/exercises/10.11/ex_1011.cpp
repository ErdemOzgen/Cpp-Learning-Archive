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
    DeckOfCards deck;

    deck.shuffle();

    deck.dealHand();
    deck.sortHand();

    deck.showHand();

    deck.getScore();

    return 0;
}
