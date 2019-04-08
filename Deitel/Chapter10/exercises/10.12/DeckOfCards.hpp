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

    static void shuffle();
    Card dealCard();
    void dealHand();
    void sortHand();

    bool moreCards() const;

    void showHand() const;
    int cardsRemaining() const;

    // SCORING FUNCTIONS
    int getScore();
    void printScore() const;
    bool hasPair();
    bool hasTwoPair();
    bool hasThreeOfKind();
    bool hasFourOfKind();
    bool hasFlush();
    bool hasStraight();

 private:
    static const int TOTAL_CARDS = 52;
    static const int HAND_SIZE = 5;

    static std::vector<Card> deck;
    std::vector<Card> hand;

    static int currentCard;
    int score;

    bool isSorted;

    static int getRandomNumber();
};
