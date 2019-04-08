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
#include "TortoiseAndHare.hpp"

// initialises member variables
void TortoiseAndHare::initialise() {
    srand(time(0));

    _gameState = GameStates::PLAY;

    _tortoise.name = "T";
    _hare.name = "H";

    std::cout << "BANG !!!!!\n"
              << "AND THEY'RE OFF !!!!!" << std::endl;
}

// entry point
void TortoiseAndHare::go() {
    initialise();

    while (_gameState != GameStates::EXIT) {
        moveTortoise(_tortoise);
        moveHare(_hare);

        printProgress();

        if (isWinner(_tortoise) || isWinner(_hare)) {
            _gameState = GameStates::EXIT;
        }
    }

    summarise();
}

// move tortoise
void TortoiseAndHare::moveTortoise(participant &t) {
    int tMove = getRandomNumber();

    // fast plod
    if (tMove >= 1 && tMove <= 5) {
        t.position = (((t.position + 3) > COURSE_LIMIT) ? COURSE_LIMIT : t.position += 3);
        // slip
    } else if (tMove <= 7) {
        t.position = ((t.position <= 6) ? 1 : t.position -= 6);
        // slow plod
    } else {
        t.position = (((t.position + 1) > COURSE_LIMIT) ? COURSE_LIMIT : t.position += 1);
    }
}

// move hare
void TortoiseAndHare::moveHare(participant &h) {
    int hMove = getRandomNumber();

    // big hop
    if (hMove == 3 || hMove == 4) {
        h.position = (((h.position + 9) > COURSE_LIMIT) ? COURSE_LIMIT : h.position + 9);
        // big slip
    } else if (hMove == 5) {
        h.position = ((h.position <= 12) ? 1 : h.position -= 12);
        // small hop
    } else if (hMove <= 8) {
        h.position =
            (((h.position + 1) > COURSE_LIMIT) ? COURSE_LIMIT : h.position + 1);
        // small slip
    } else if (hMove <= 10) {
        h.position = ((h.position <= 2) ? 1 : h.position -= 2);
    }
    // sleep do nothing
}

// check if participant has won
bool TortoiseAndHare::isWinner(participant &p) {
    return p.position >= COURSE_LIMIT;
}

// print race progress
void TortoiseAndHare::printProgress() {
    for (unsigned int i = 1; i <= COURSE_LIMIT; ++i) {
        if (_tortoise.position == i && _hare.position == i) {
            std::cout << "OUCH";
            i += 3;  // avoid excess course printing
        } else if (_tortoise.position == i) {
            std::cout << _tortoise.name;
        } else if (_hare.position == i) {
            std::cout << _hare.name;
        } else {
            std::cout << "-";
        }
    }
    std::cout << std::endl;
}

// prints race results
void TortoiseAndHare::summarise() {
    if (_tortoise.position == COURSE_LIMIT && _hare.position == COURSE_LIMIT) {
        std::cout << "\n***** It's a Draw ***** \n" << std::endl;
    } else if (_tortoise.position == COURSE_LIMIT) {
        std::cout << "\n***** TORTOISE WINS !!!! *****\n" << std::endl;
    } else {
        std::cout << "\n***** HARE WINS ***** \n" << std::endl;
    }

    int choice;

    std::cout << "1. Play again\n2. Exit\n> ";
    std::cin >> choice;

    if (choice == 1) { reset(); }
}

void TortoiseAndHare::reset() {
    _tortoise.position = 0;
    _hare.position = 0;
    go();
}

/**
 * Creates a random distribution and returns a value in the range min max.
 * @return int
 */
int TortoiseAndHare::getRandomNumber() {
    return std::uniform_int_distribution<int>{1, 10}(gen);
}  // end method getRandomNumber
