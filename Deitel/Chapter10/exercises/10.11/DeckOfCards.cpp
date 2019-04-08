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
#include <algorithm>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include <random>

#include "DeckOfCards.hpp"

DeckOfCards::DeckOfCards() : currentCard(0), gen(std::random_device()()), isSorted(false) {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            deck.push_back(Card(j, i));
        }
    }
}
void DeckOfCards::shuffle() {
    for (int i = 0, r1 = 0, r2 = 0; i < TOTAL_CARDS; ++i) {
        r1 = getRandomNumber();
        r2 = getRandomNumber();

        std::iter_swap(deck.begin() + r1, deck.begin() + r2);
    }
}
Card DeckOfCards::dealCard() {
    if (moreCards()) {
        return deck[currentCard++];
    } else {
        throw std::invalid_argument("end of deck reached");
    }
}
void DeckOfCards::dealHand() {
    for (int i = 0; i < HAND_SIZE; ++i) {
        hand.push_back(dealCard());
    }
}
bool DeckOfCards::moreCards() const { return currentCard < TOTAL_CARDS; }
void DeckOfCards::showHand() const {
    for (int i = 0; i < HAND_SIZE; ++i) {
        std::cout << hand[i].toString() << "\n";
    }
}
// sorts a hand into ascending order - bubble sort as there are only ever 5
// values
void DeckOfCards::sortHand() {
    int flag = 1;

    for (int i = 0; i < HAND_SIZE && flag; ++i) {
        flag = 0;
        for (int j = 0; j < HAND_SIZE - 1; ++j) {
            if (hand[j].getFace() > hand[j + 1].getFace()) {
                std::iter_swap(hand.begin() + j, hand.begin() + (j + 1));
                flag = 1;
            }
        }
    }
    isSorted = true;
}
// SCORING FUNCTIONS
void DeckOfCards::getScore() {
    bool pair = hasPair();
    bool twoPair = hasTwoPair();
    bool threeKind = hasThreeOfKind();
    bool fourKind = hasFourOfKind();
    bool flush = hasFlush();
    bool straight = hasStraight();

    if (!pair && !twoPair && !threeKind && !fourKind && !flush && !straight) {
        std::cout << "\nNo score" << std::endl;
        return;
    }

    std::cout << "\nScore for this hand:\n"
              << ((pair) ? "Pair\n" : "") << ((twoPair) ? "Two Pairs\n" : "")
              << ((threeKind) ? "Three of a kind\n" : "")
              << ((fourKind) ? "Four of a kind\n" : "")
              << ((flush) ? "Flush\n" : "") << ((straight) ? "Straight\n" : "");
}
bool DeckOfCards::hasPair() {
    for (int i = 0; i < HAND_SIZE; ++i) {
        for (int j = i + 1; j < HAND_SIZE; ++j) {
            if (hand[i].getFace() == hand[j].getFace()) {
                return true;
            }
        }
    }
    return false;
}
bool DeckOfCards::hasTwoPair() {
    int firstPairFace = 0;

    for (int i = 0; i < HAND_SIZE; ++i) {
        for (int j = i + 1; j < HAND_SIZE; ++j) {
            if (hand[i].getFace() == hand[j].getFace()) {
                firstPairFace = hand[j].getFace();

                for (int k = 0; k < HAND_SIZE; ++k) {
                    for (int l = k + 1; l < HAND_SIZE; ++l) {
                        if (hand[k].getFace() != firstPairFace &&
                            hand[k].getFace() == hand[l].getFace()) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool DeckOfCards::hasThreeOfKind() {
    for (int i = 0, counter = 0; i < HAND_SIZE; ++i, counter = 0) {
        for (int j = 0; j < HAND_SIZE; ++j) {
            if (hand[i].getFace() == hand[j].getFace()) {
                if (++counter == 3) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool DeckOfCards::hasFourOfKind() {
    for (int i = 0, counter = 0; i < HAND_SIZE; ++i, counter = 0) {
        for (int j = 0; j < HAND_SIZE; ++j) {
            if (hand[i].getFace() == hand[j].getFace()) {
                if (++counter == 4) {
                    return true;
                }
            }
        }
    }
    return false;
}
// all five cards of same suit
bool DeckOfCards::hasFlush() {
    std::string suit = hand[0].getSuit();

    for (int i = 0; i < HAND_SIZE; ++i) {
        if (hand[i].getSuit() != suit) {
            return false;
        }
    }
    return true;
}
// five cards of consecutive face
bool DeckOfCards::hasStraight() {
    if (!isSorted) {
        sortHand();
    }

    for (int i = 1; i < HAND_SIZE; ++i) {
        if ((hand[i - 1].getFace() + 1) == hand[i].getFace()) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

/**
 * Creates a random distribution and returns a value in the range min max.
 * @return int
 */
int DeckOfCards::getRandomNumber() {
    return std::uniform_int_distribution<int>{1, TOTAL_CARDS - 1}(gen);
}  // end method getRandomNumber
