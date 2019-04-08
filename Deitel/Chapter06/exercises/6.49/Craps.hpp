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

#include <iostream>
#include <random>

class Craps {
 private:
    enum class Status { CONTINUE, WON, LOST, QUIT };

    Status _gameStatus;

    const int MIN = 1;
    const int MAX = 6;

    int _myPoint;
    int _bankBalance;
    int _wager;

    std::mt19937 gen;

    int rollDice();
    void setWager();
    void checkScore(int);
    void getStatus();
    int getRandomNumber();

 public:
    Craps();
    ~Craps();

    void run();
};
