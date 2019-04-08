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
    void dealHand();
    void sortHand();

    bool moreCards() const;

    void showHand() const;

    // SCORING FUNCTIONS
    void getScore();
    bool hasPair();
    bool hasTwoPair();
    bool hasThreeOfKind();
    bool hasFourOfKind();
    bool hasFlush();
    bool hasStraight();

 private:
    const int TOTAL_CARDS = 52;
    const int HAND_SIZE = 5;

    std::vector<Card> deck;
    std::vector<Card> hand;

    int currentCard;
    std::mt19937 gen;

    bool isSorted;

    int getRandomNumber();
};
