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
#include <string>
#include <random>

struct participant {
    std::string name;
    unsigned int position;

    participant() : position(1) {}
};

enum class GameStates { PLAY, EXIT };

class TortoiseAndHare {
 private:
    static const size_t COURSE_LIMIT = 70;

    participant _tortoise;
    participant _hare;

    GameStates _gameState;

    std::mt19937 gen;

    void initialise();
    void moveTortoise(participant &);
    void moveHare(participant &);
    bool isWinner(participant &);
    void printProgress();
    void summarise();
    void reset();
    int getRandomNumber();

 public:
    TortoiseAndHare() : _gameState(GameStates::PLAY), gen(std::random_device()()) {}

    ~TortoiseAndHare() {}

    void go();
};
