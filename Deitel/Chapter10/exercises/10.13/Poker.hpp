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

#include "Hand.hpp"

class Poker {
 public:
    Poker();

    void go();

 private:
    unsigned int numPlayers;

    bool running;

    std::vector<Hand> players;

    void setPlayers();
    void processTurns();
    void showResult();
    bool playAgain();
};
