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
#include <random>

#include "GuessTheNumber.hpp"

GuessTheNumber::GuessTheNumber() : gen(std::random_device()()) {
        initialise();
}  // end constructor GuessTheNumber

// initialises and resets member variables
void GuessTheNumber::initialise() {
    _currentState = GameStates::PLAY;

    _randNumber = getRandomNumber();

    // print here so as to avoid having it print ever turn
    printf("I have a number between %d and %d\n", MIN, MAX);
}

// takes the player guess and compares to number
GameStates GuessTheNumber::guess(int playerGuess) const {
    if (playerGuess == _randNumber) {
        std::cout << "Excellent! You guessed the number!" << std::endl;
        return GameStates::WON;
    }

    printf("Too %s Try again.\n", (playerGuess < _randNumber ? "low" : "high"));
    return GameStates::PLAY;
}

// main game loop
void GuessTheNumber::run() {
    while (_currentState != GameStates::EXIT) {
        if (_currentState == GameStates::PLAY) {
            printf("\nCan you guess my number?\nPlease type your guess: ");
            std::cin >> _playerGuess;

            _currentState = guess(_playerGuess);
        }
        if (_currentState == GameStates::WON) {
            std::cout << "Would you like to play again (y or n)? ";
            std::cin >> _playerContinue;

            if (_playerContinue == 'y') {
                initialise();
            } else {
                _currentState = GameStates::EXIT;
            }
        }
    }
}

/**
 * Creates a random distribution and returns a value in the range min max.
 * @return int
 */
int GuessTheNumber::getRandomNumber() {
    return std::uniform_int_distribution<int>{MIN, MAX}(gen);
}  // end method getRandomNumber
