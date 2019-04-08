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
#include "Quiz.hpp"

void Quiz::run() {
    if (_currentState != GameStates::INIT) {
        return;
    }
    if (!initialise()) {
        std::cout << "ERROR: Quiz failed to initialise" << std::endl;
        return;
    }
    gameLoop();
    cleanup();
}
bool Quiz::initialise() {
    // if game already played reset to default
    if (!_questions.empty()) {
        _questions.clear();
        _correctAnswers = 0;
    }
    if (setQuestions()) {
        return true;
    }
    return false;
}
// set questions and answers
bool Quiz::setQuestions() {
    _questions.push_back(
        Question("What...is your name?", "Sir Lancelot of Camelot",
                 "Uh...er...ah...Joe?", "Uh...Princess Peach Fuzz?",
                 "Sir Geldof of Bob?"));
    _questions.push_back(
        Question("What...is your quest?", "To seek the Holy Grail",
                 "To...uh...find the cup of Christ", "To not do well at chess",
                 "To not choose this answer"));
    _questions.push_back(Question("What...is your favourite color?", "Blue",
                                  "Blue! NO! YELLOOOOOOOOWW!!!", "Greeeen?",
                                  "Uh...er...Africa"));
    _questions.push_back(Question(
        "What...is the capital of Assyria?", "Ninev.hpp", "Used to be Assur",
        "In the past it was Numrud", "At one time it was at Dur Sarukin"));
    _questions.push_back(
        Question("What...is the airspeed velocity of an unladen swallow?",
                 "An African or European Swallow?", "Uh uh .hpp", "Uh...er...ah",
                 "Well...I don't know..."));

    _currentState = GameStates::PLAY;
    return true;
}
void Quiz::gameLoop() {
    char choice;

    while (_currentState != GameStates::EXIT) {
        askQuestion();
        checkScore();

        std::cout << "You scored: " << _correctAnswers << "/5" << std::endl;
        printf("%s\n",
               (_correctAnswers == 5) ? "I say, jolly well done old chap"
                                      : "Better luck next time. Perhaps "
                                        "something with less thinking would be "
                                        "more your style.");

        std::cout << "Play Again? ";
        std::cin >> choice;

        if (choice == 'n' || choice == 'N') {
            _currentState = GameStates::EXIT;
        } else {
            // reinitialise the questions
            initialise();
        }
    }
}
// loop through questions and print question and choices
void Quiz::askQuestion() {
    int choice = 0;

    for (unsigned int i = 0; i < _questions.size(); i++) {
        std::cout << "Question " << i + 1 << ": ";
        _questions[i].getQuestion();

        std::cout << "Answer (1-4): ";
        std::cin >> choice;

        if (choice > 4) {
            std::cout << "Incorrect choice" << std::endl;
            i--;
            continue;
        }
        // answer the question
        _questions[i].answer(choice);
    }
}
// loop through each question and check correct flag
int Quiz::checkScore() {
    // loop through each question and check if it was answered correctly
    for (unsigned int i = 0; i < _questions.size(); i++) {
        if (_questions[i].isCorrect()) {
            _correctAnswers++;
        }
    }
    return _correctAnswers;
}
void Quiz::cleanup() {
    _questions.clear();
    _correctAnswers = 0;
}
