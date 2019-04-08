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

#include "Card.hpp"
#include "DeckOfCards.hpp"

#include <string>
#include <vector>

class Hand : public DeckOfCards {
 public:
    explicit Hand(bool = false, std::string = "player");

    void dealHand();
    Card dealCard();
    bool moreCards() const;
    void showHand() const;
    void sortHand();

    void turn();
    void dealerMove();
    void playerMove();

    bool discard(unsigned int);
    bool draw(unsigned int);

    // SCORING FUNCTIONS
    int scoreHand();
    std::string getScore();
    bool hasPair() const;
    bool hasTwoPair() const;
    bool hasThreeOfKind() const;
    bool hasFourOfKind() const;
    bool hasFlush() const;
    bool hasStraight();

    bool isDealer() const { return dealer; }

    std::string getName() const { return name; }

    int getNumScore() { return score; }
    void reset();

 private:
    const unsigned int MAX_DISCARD = 3;
    const unsigned int HAND_SIZE = 5;

    std::string name;

    std::vector<Card> hand;

    int score;

    bool isSorted;
    bool dealer;
    bool handScored;
};
