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
#include "Card.hpp"

std::string Card::suits[5] = {"", "clubs", "diamonds", "hearts", "spades"};
std::string Card::faces[14] = {"",     "ace",  "two",   "three", "four",
                               "five", "six",  "seven", "eight", "nine",
                               "ten",  "jack", "queen", "king"};

Card::Card(int f, int s) {
    face = f;
    suit = s;
}
std::string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}
