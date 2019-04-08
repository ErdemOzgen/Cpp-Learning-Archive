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
#include <vector>
#include <random>

#include "DeckOfCards.hpp"

int DeckOfCards::currentCard = 0;
std::vector<Card> DeckOfCards::deck;

DeckOfCards::DeckOfCards() : isSorted(false) {
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
// returns the number of cards remaning in the deck
int DeckOfCards::cardsRemaining() const { return TOTAL_CARDS - currentCard; }
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
// fetch highest score available
int DeckOfCards::getScore() {
    if (hasStraight()) {
        score = 6;
    } else if (hasFlush()) {
        score = 5;
    } else if (hasFourOfKind()) {
        score = 4;
    } else if (hasThreeOfKind()) {
        score = 3;
    } else if (hasTwoPair()) {
        score = 2;
    } else if (hasPair()) {
        score = 1;
    } else {
        score = 0;
    }

    return score;
}
// print the score
void DeckOfCards::printScore() const {
    switch (score) {
        case 1:
            std::cout << "Pair";
            break;
        case 2:
            std::cout << "Two Pairs";
            break;
        case 3:
            std::cout << "Three of a Kind";
            break;
        case 4:
            std::cout << "Four of a Kind";
            break;
        case 5:
            std::cout << "Flu.hpp";
            break;
        case 6:
            std::cout << "Straight";
            break;
        default:
            std::cout << "No Hand";
            break;
    }
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
