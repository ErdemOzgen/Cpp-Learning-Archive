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
#pragma once

#include <vector>
#include <random>

#include "Card.hpp"

class DeckOfCards {
 public:
    DeckOfCards();

    void shuffle();
    Card dealCard();
    bool moreCards() const;

 private:
    const int TOTAL_CARDS = 52;

    std::vector<Card> deck;

    int currentCard;

    std::mt19937 gen;

    int getRandomNumber();
};
