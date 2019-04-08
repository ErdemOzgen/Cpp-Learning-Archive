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

#include "Question.hpp"

// INITIALISATION
// checks if question and answers are set and sets them if not
// creates and randomises an answers vector
void Question::initialise() {
    std::string tmp;
    if (_q.empty()) {
        std::cout << "Enter a question: ";
        std::cin >> tmp;
        setQuestion(tmp);
    }
    if (_a.empty()) {
        std::cout << "Enter correct answer: ";
        std::cin >> tmp;
        setA(tmp);
    }
    if (_b.empty()) {
        std::cout << "Enter first incorrect answer: ";
        std::cin >> tmp;
        setB(tmp);
    }
    if (_c.empty()) {
        std::cout << "Enter second incorrect answer: ";
        std::cin >> tmp;
        setC(tmp);
    }
    if (_d.empty()) {
        std::cout << "Enter third incorrect answer: ";
        std::cin >> tmp;
        setD(tmp);
    }

    // build the answers vector
    _answers.push_back(_a);
    _answers.push_back(_b);
    _answers.push_back(_c);
    _answers.push_back(_d);

    // randomise answers vector
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(_answers.begin(), _answers.end(), std::default_random_engine(seed));
}
// SETTERS
void Question::setQuestion(const std::string& Q) { _q = Q; }
void Question::setA(const std::string& A) { _a = A; }
void Question::setB(const std::string& B) { _b = B; }
void Question::setC(const std::string& C) { _c = C; }
void Question::setD(const std::string& D) { _d = D; }

// GETTERS
// prints the question and randomised answers vector
void Question::getQuestion() const {
    // question
    std::cout << _q << std::endl << std::endl;

    // answers
    for (unsigned int i = 0; i < _answers.size(); i++) {
        std::cout << _answers[i] << std::endl;
    }
    std::cout << std::endl;
}
// answer the question
// CHAR ANSWER
bool Question::answer(char& ans) {
    if (ans == 'a' && _answers[0] == _a) {
        _correct = 1;
        return true;
    }
    if (ans == 'b' && _answers[1] == _a) {
        _correct = 1;
        return true;
    }
    if (ans == 'c' && _answers[2] == _a) {
        _correct = 1;
        return true;
    }
    if (ans == 'd' && _answers[3] == _a) {
        _correct = 1;
        return true;
    }
    return false;
}
// INT ANSWER
bool Question::answer(int ans) {
    ans--;

    if (_answers[ans] == _a) {
        _correct = 1;
        return true;
    }
    return false;
}
