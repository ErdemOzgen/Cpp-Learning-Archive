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
#include <string>

#include "CAI.hpp"

// INITIALISATION
void CAI::initialise() {
    _currentState = QuizStates::INIT;

    // build response vectors
    _correctResponses.push_back("\\(^-^)/ Very good!");
    _correctResponses.push_back("Excellent!");
    _correctResponses.push_back("Nice work!");
    _correctResponses.push_back("Keep up the good work!");
    _incorrectResponses.push_back("No. Please try again.");
    _incorrectResponses.push_back("Wrong. Try once more.");
    _incorrectResponses.push_back("Don't give up!");
    _incorrectResponses.push_back("No. Keep trying.");
}

// prints a menu and sets the difficulty level
void CAI::setDifficulty() {
    int choice = 0;

    while (choice == 0) {
        std::cout << "Welcome to the quiz.\nPlease select your difficulty level:\n"
                  << "1. Super mega easy.\n"
                  << "2. Normal\n"
                  << "3. Insane\n"
                  << "4. Genius Mode\n"
                  << "> ";

        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            _currentState = QuizStates::PLAY;
            _difficulty = choice;
        } else {
            choice = 0;
        }
    }
}

// prints a menu and sets the problem type
void CAI::chooseProblemType() {
    int choice = 0;

    while (choice == 0) {
        std::cout << "Please select the type of problems to solve:\n"
                  << "1. Addition.\n"
                  << "2. Subtraction.\n"
                  << "3. Multiplication.\n"
                  << "4. Division.\n"
                  << "5. Randomised.\n"
                  << "> ";

        std::cin >> choice;

        if (choice >= 1 && choice <= 5) {
            setProblemType(choice);
        } else {
            choice = 0;
        }
    }
}

// set problem type separately from printing as if choice is random needs to be
// done at beginning of each question.
void CAI::setProblemType(int type) {
    switch (type) {
        case 1:
            _problemType = ProblemTypes::ADDITION;
            break;
        case 2:
            _problemType = ProblemTypes::SUBTRACTION;
            break;
        case 3:
            _problemType = ProblemTypes::MULTIPLICATION;
            break;
        case 4:
            _problemType = ProblemTypes::DIVISION;
            break;
        case 5:
            _randomProblem = 1;
            break;
        default:
            break;
    }
}

// generates and assigns a pair of random numbers for the current question
void CAI::generateQuestion() {
    //                    v padding
    static int limit[5] = {0, 9, 99, 999, 9999};

    // randomise division from 1 so as to avoid divide by zero
    if (_problemType == ProblemTypes::DIVISION) {
        _doubleQuestion.init(getRandomNumber(1, limit[_difficulty]), getRandomNumber(1, limit[_difficulty]));
    } else {
        _intQuestion.init(getRandomNumber(0, limit[_difficulty]), getRandomNumber(0, limit[_difficulty]));
    }
}
// asks the question
void CAI::askQuestion() {
    int intSolution = 0;

    double doubleSolution = 0;

    bool correct;

    std::string questionOperator;

    ++_questionCount;

    if (_randomProblem == 1) {
        setProblemType(getRandomNumber(1, 4));
    }

    // question needs generating after random problem
    // division requires double type
    generateQuestion();

    switch (_problemType) {
        case ProblemTypes::ADDITION:
            questionOperator = " + ";
            intSolution = _intQuestion.add();
            break;
        case ProblemTypes::SUBTRACTION:
            questionOperator = " - ";
            intSolution = _intQuestion.subtract();
            break;
        case ProblemTypes::MULTIPLICATION:
            questionOperator = " * ";
            intSolution = _intQuestion.multiply();
            break;
        case ProblemTypes::DIVISION:
            questionOperator = " / ";
            doubleSolution = _doubleQuestion.divide();
            break;
        default:
            break;
    }

    std::cout << "\n" << _questionCount << "/" << MAX_QUESTIONS << ": ";

    if (_problemType == ProblemTypes::DIVISION) {
        double doubleAnswer;

        std::cout << _doubleQuestion.num1 << questionOperator
                  << _doubleQuestion.num2 << "? ";
        std::cin >> doubleAnswer;

        while (std::cin.fail()) {
            std::cout << _doubleQuestion.num1 << questionOperator
                      << _doubleQuestion.num2 << "? ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> doubleAnswer;
        }

        correct = checkAnswer(doubleAnswer, doubleSolution);
    } else {
        int intAnswer;

        std::cout << _intQuestion.num1 << questionOperator << _intQuestion.num2
                  << "? ";
        std::cin >> intAnswer;

        while (std::cin.fail()) {
            std::cout << _intQuestion.num1 << questionOperator
                      << _intQuestion.num2 << "? ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> intAnswer;
        }

        correct = checkAnswer(intAnswer, intSolution);
    }

    printResponse(correct);

    (correct) ? ++_correct : ++_incorrect;
}
// prints response based on whether the question was answered correctly
void CAI::printResponse(bool correct) {
    //   srand(static_cast<int>(time(0)));

    if (correct) {
        std::cout << "\n\t*** "
                  << _correctResponses[getRandomNumber(0, _correctResponses.size() -1)]
                  << " ***" << std::endl;
    } else {
        std::cout << "\n\t*** "
                  << _incorrectResponses[getRandomNumber(0, _incorrectResponses.size() -1)]
                  << " ***" << std::endl;
    }
}
// calculates and prints the players performance report
void CAI::printReport() {
    double percent =
        (static_cast<double>(_correct) / static_cast<double>(MAX_QUESTIONS)) *
        100;

    std::cout << "\nYou scored " << percent << "%" << std::endl;

    if (percent < 75.0f) {
        std::cout << "\n*** Please ask your teacher for extra help. ***"
                  << std::endl;
    } else {
        std::cout << "\n*** (/.__.)/\\(.__.\\) Congratulations, you are ready "
                     "to go on to the next level! ***"
                  << std::endl;
    }
}
void CAI::reset() {
    _questionCount = 0;
    _correct = 0;
    _incorrect = 0;
    _difficulty = 0;
    _randomProblem = 0;

    _currentState = QuizStates::INIT;

    srand(static_cast<int>(time(0)));
}
// main game loop
void CAI::run() {
    char cont;

    while (_currentState != QuizStates::EXIT) {
        if (_questionCount == 0) {
            setDifficulty();
            chooseProblemType();
        }

        askQuestion();

        if (_questionCount == MAX_QUESTIONS) {
            printReport();

            std::cout << "\nPlay again (y/n)? ";
            std::cin >> cont;

            if (cont == 'y') {
                reset();
            } else {
                _currentState = QuizStates::EXIT;
            }
        }
    }
}

/**
 * Creates a random distribution and returns a value in the range min max.
 * @param int
 * @param int
 * @return int
 */
int CAI::getRandomNumber(const int& min, const int& max) {
    return std::uniform_int_distribution<int>{min, max}(gen);
}  // end method getrandomnumber
