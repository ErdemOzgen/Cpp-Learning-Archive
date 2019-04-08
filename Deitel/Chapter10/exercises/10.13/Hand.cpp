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
#include <iostream>
#include <stdexcept>
#include <string>

#include "Hand.hpp"

Hand::Hand(bool dealer, std::string n)
    : isSorted(false), dealer(dealer), handScored(false) {
    if (dealer) {
        name = "Dealer";
    } else {
        name = n;
    }

    dealHand();
}
void Hand::dealHand() {
    for (unsigned int i = 0; i < HAND_SIZE; ++i) {
        hand.push_back(dealCard());
    }
    sortHand();
}
Card Hand::dealCard() {
    if (moreCards()) {
        return deck[currentCard++];
    } else {
        throw std::invalid_argument("end of deck reached");
    }
}
bool Hand::moreCards() const { return currentCard < TOTAL_CARDS; }
void Hand::showHand() const {
    for (unsigned int i = 0; i < HAND_SIZE; ++i) {
        std::cout << i << ": " << hand[i].toString() << "\n";
    }
}
// sorts a hand into ascending order - bubble sort as there are only ever 5
// values
void Hand::sortHand() {
    int flag = 1;

    for (unsigned int i = 0; i < HAND_SIZE && flag; ++i) {
        flag = 0;
        for (unsigned int j = 0; j < HAND_SIZE - 1; ++j) {
            if (hand[j].getFace() > hand[j + 1].getFace()) {
                std::iter_swap(hand.begin() + j, hand.begin() + (j + 1));
                flag = 1;
            }
        }
    }
    isSorted = true;
}
// PLAYER AND DEALER TURNS
void Hand::turn() {
    scoreHand();

    if (dealer) {
        dealerMove();
    } else {
        playerMove();
    }
}
void Hand::dealerMove() {
    if (score == 1) {  // PAIR
        // get face of existing pair
        int pairFace = 0;
        for (unsigned int i = 0; i < HAND_SIZE; ++i) {
            for (unsigned int j = i + 1; j < HAND_SIZE; ++j) {
                if (hand[i].getFace() == hand[j].getFace()) {
                    pairFace = hand[i].getFace();

                    // find first 3 indices whose faces != pairFace
                    for (unsigned int k = 0; k < HAND_SIZE; ++k) {
                        if (hand[k].getFace() != pairFace) {
                            discard(k);
                            draw(1);
                        }
                    }
                }
            }
        }
        std::cout << "Dealer takes 3" << std::endl;
    } else if (score == 2) {  // TWO PAIRS
        int pairFace1 = 0;
        bool flag = 1;

        for (unsigned int i = 0; i < HAND_SIZE && flag; ++i) {
            for (unsigned int j = i + 1; j < HAND_SIZE; ++j) {
                if (hand[i].getFace() == hand[j].getFace()) {
                    pairFace1 = hand[j].getFace();

                    for (unsigned int k = 0; k < HAND_SIZE; ++k) {
                        for (unsigned int l = k + 1; l < HAND_SIZE; ++l) {
                            if (hand[k].getFace() != pairFace1 &&
                                hand[k].getFace() == hand[l].getFace()) {
                                // discard remaining index card
                                // index is the difference of total index sum
                                // and paired card indices
                                discard((0 + 1 + 2 + 3 + 4) - (i + j + k + l));
                                draw(1);
                                flag = 1 - flag;
                                break;
                            }
                        }
                    }
                }
            }
        }
        std::cout << "Dealer takes one" << std::endl;
    } else if (score == 3) {  // 3 OF A KIND
        int face = 0;

        for (unsigned int i = 0, counter = 0; i < HAND_SIZE; ++i, counter = 0) {
            if (face != 0) {  // determine face
                for (unsigned int j = 0; j < HAND_SIZE; ++j) {
                    if (hand[i].getFace() == hand[j].getFace()) {
                        if (++counter == 3) {
                            face = hand[i].getFace();
                            i = 0;  // reset outer loop
                            break;
                        }
                    }
                }
            } else {
                if (hand[i].getFace() != face) {
                    discard(i);
                    draw(1);
                }
            }
        }
        std::cout << "Dealer takes two" << std::endl;
    } else if (score == 4) {  // 4 OF A KIND
        int face = 0;

        for (unsigned int i = 0, counter = 0; i < HAND_SIZE; ++i, counter = 0) {
            if (face != 0) {  // determine face
                for (unsigned int j = 0; j < HAND_SIZE; ++j) {
                    if (hand[i].getFace() == hand[j].getFace()) {
                        if (++counter == 4) {
                            face = hand[i].getFace();
                            i = 0;  // reset outer loop
                            break;
                        }
                    }
                }
            } else {
                if (hand[i].getFace() != face) {
                    discard(i);
                    draw(1);
                    break;
                }
            }
        }
        std::cout << "Dealer takes one" << std::endl;
    } else if (score == 5) {  // FLUSH
        std::cout << "Dealer passes" << std::endl;
        return;
    } else if (score == 6) {  // STRAIGHT
        std::cout << "Dealer passes" << std::endl;
        return;
    } else {  // NOTHING
        for (unsigned int i = 0; i < MAX_DISCARD; ++i) {
            discard(i);
        }
        draw(MAX_DISCARD);

        std::cout << "Dealer takes 3" << std::endl;
    }

    sortHand();
}
void Hand::playerMove() {
    unsigned int numDiscard = 0;
    int discardIndex = 0;

    while (true) {
        std::cout << "Enter number of cards to discard: ";
        std::cin >> numDiscard;

        if (numDiscard > MAX_DISCARD) {
            std::cout << "Can discard a maximum of 3 cards. Try again"
                      << std::endl;
        } else {
            break;
        }
    }

    for (unsigned int i = 0; i < numDiscard; ++i) {
        std::cout << "Enter the index (0-4) of card number " << i + 1
                  << " to discard: ";
        std::cin >> discardIndex;

        discard(discardIndex);
    }

    draw(numDiscard);
    sortHand();
    scoreHand();

    std::cout << getName() << " takes " << numDiscard << std::endl;
}
// Discard up to three cards
// pass indice of card to remove
bool Hand::discard(unsigned int index) {
    if (index < HAND_SIZE) {
        hand.erase(hand.begin() + index);
        return true;
    }
    std::cout << "Cannot remove card. Invalid index\n";

    return false;
}
// draw n up to 3 cards from the deck
bool Hand::draw(unsigned int n) {
    // std::cout << "n: " << n << " cardsRemaning: " << cardsRemaining() <<
    // std::endl;

    if (hand.size() == HAND_SIZE) {
        std::cout << "Hand at capacity. Need to discard cards first.\n";
    } else if (n >= 1 && n <= MAX_DISCARD && cardsRemaining() >= n) {
        for (unsigned int i = 0; i < n && moreCards(); ++i) {
            hand.push_back(dealCard());
        }
        return true;
    } else {
        std::cout << "Cannot draw more than " << MAX_DISCARD
                  << " cards. Try again\n";
    }
    return false;
}
// SCORING FUNCTIONS
// fetch highest score available
int Hand::scoreHand() {
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

    handScored = true;

    return score;
}
// print the score
std::string Hand::getScore() {
    if (!handScored) {
        scoreHand();
    }
    switch (score) {
        case 1:
            return "Pair";
            break;
        case 2:
            return "Two Pairs";
            break;
        case 3:
            return "Three of a Kind";
            break;
        case 4:
            return "Four of a Kind";
            break;
        case 5:
            return "Flu.hpp";
            break;
        case 6:
            return "Straight";
            break;
        default:
            return "No Hand";
            break;
    }
}
bool Hand::hasPair() const {
    for (unsigned int i = 0; i < HAND_SIZE; ++i) {
        for (unsigned int j = i + 1; j < HAND_SIZE; ++j) {
            if (hand[i].getFace() == hand[j].getFace()) {
                return true;
            }
        }
    }
    return false;
}
bool Hand::hasTwoPair() const {
    int firstPairFace = 0;

    for (unsigned int i = 0; i < HAND_SIZE; ++i) {
        for (unsigned int j = i + 1; j < HAND_SIZE; ++j) {
            if (hand[i].getFace() == hand[j].getFace()) {
                firstPairFace = hand[j].getFace();

                for (unsigned int k = 0; k < HAND_SIZE; ++k) {
                    for (unsigned int l = k + 1; l < HAND_SIZE; ++l) {
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
bool Hand::hasThreeOfKind() const {
    for (unsigned int i = 0, counter = 0; i < HAND_SIZE; ++i, counter = 0) {
        for (unsigned int j = 0; j < HAND_SIZE; ++j) {
            if (hand[i].getFace() == hand[j].getFace()) {
                if (++counter == 3) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool Hand::hasFourOfKind() const {
    for (unsigned int i = 0, counter = 0; i < HAND_SIZE; ++i, counter = 0) {
        for (unsigned int j = 0; j < HAND_SIZE; ++j) {
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
bool Hand::hasFlush() const {
    std::string suit = hand[0].getSuit();

    for (unsigned int i = 0; i < HAND_SIZE; ++i) {
        if (hand[i].getSuit() != suit) {
            return false;
        }
    }
    return true;
}
// five cards of consecutive face
bool Hand::hasStraight() {
    if (!isSorted) {
        sortHand();
    }

    for (unsigned int i = 1; i < HAND_SIZE; ++i) {
        if ((hand[i - 1].getFace() + 1) == hand[i].getFace()) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}
// resets hand
void Hand::reset() {
    isSorted = false;
    handScored = false;

    hand.clear();

    dealHand();
}
