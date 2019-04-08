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

static std::random_device rd;
static std::mt19937 gen(rd());

class DeckOfCards {
 public:
    DeckOfCards();

    static void reset();

    static void shuffle();

    static unsigned int cardsRemaining();

 protected:
    static const unsigned int TOTAL_CARDS = 52;

    static std::vector<Card> deck;

    static unsigned int currentCard;

    static int getRandomNumber();
};
