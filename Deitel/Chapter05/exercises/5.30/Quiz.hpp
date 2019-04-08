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
#include <vector>

#include "Question.hpp"

enum class GameStates { INIT, PLAY, EXIT };

class Quiz {
 private:
    std::vector<Question> _questions;

    GameStates _currentState;

    int _correctAnswers;

 public:
    Quiz() : _currentState(GameStates::INIT), _correctAnswers(0) {}

    ~Quiz() { cleanup(); }

    void run();

    bool initialise();
    bool setQuestions();

    void gameLoop();

    void askQuestion();

    int checkScore();

    void cleanup();
};
