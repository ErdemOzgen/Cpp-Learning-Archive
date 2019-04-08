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

enum class GameStates { PLAY, EXIT, WON };

class GuessTheNumber {
 private:
    GameStates _currentState;

    const int MIN = 0;
    const int MAX = 1000;

    int _randNumber;
    int _playerGuess;
    char _playerContinue;

    std::mt19937 gen;

    void initialise();
    GameStates guess(int) const;
    int getRandomNumber();

 public:
    GuessTheNumber();
    ~GuessTheNumber() {}

    void run();
};
