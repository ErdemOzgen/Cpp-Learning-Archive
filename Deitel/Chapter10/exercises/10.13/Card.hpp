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

#include <string>

class Card {
 public:
    Card(int, int);

    std::string toString() const;

    std::string getSuit() const { return suits[suit]; }

    int getFace() const { return face; }

 private:
    static std::string suits[];
    static std::string faces[];

    int face;
    int suit;
};
