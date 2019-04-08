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
#include <random>

#include "DeckOfCards.hpp"

unsigned int DeckOfCards::currentCard = 0;
std::vector<Card> DeckOfCards::deck;

DeckOfCards::DeckOfCards() { reset(); }
void DeckOfCards::reset() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            deck.push_back(Card(j, i));
        }
    }
    currentCard = 0;
    shuffle();
}
void DeckOfCards::shuffle() {
    for (unsigned int i = 0, r1 = 0, r2 = 0; i < TOTAL_CARDS; ++i) {
        r1 = getRandomNumber();
        r2 = getRandomNumber();

        std::iter_swap(deck.begin() + r1, deck.begin() + r2);
    }
}
// returns the number of cards remaning in the deck
unsigned int DeckOfCards::cardsRemaining() { return TOTAL_CARDS - currentCard; }

/**
 * Creates a random distribution and returns a value in the range min max.
 * @return int
 */
int DeckOfCards::getRandomNumber() {
    return std::uniform_int_distribution<int>{1, TOTAL_CARDS - 1}(gen);
}  // end method getRandomNumber
