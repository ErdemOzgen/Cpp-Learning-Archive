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

#include <algorithm>  // shuffle
#include <chrono>     // system_clock
#include <iostream>
#include <random>  // random_engine
#include <string>
#include <vector>

class Question {
 private:
    std::string _q;
    std::string _a;
    std::string _b;
    std::string _c;
    std::string _d;

    std::vector<std::string> _answers;

    int _correct;

 public:
    Question() : _correct(0) { initialise(); }

    Question(const std::string& Q, const std::string& A, const std::string& B,
             const std::string& C, const std::string& D)
        : _q(Q), _a(A), _b(B), _c(C), _d(D), _correct(0) {
        initialise();
    }
    ~Question() { cleanup(); }

    void initialise();

    // SETTERS
    void setQuestion(const std::string&);
    void setA(const std::string&);
    void setB(const std::string&);
    void setC(const std::string&);
    void setD(const std::string&);

    // GETTERS
    void getQuestion() const;

    // answer the question - Letter or numerical answer
    bool answer(char&);
    bool answer(int);

    // check if answered correctly
    bool isCorrect() { return _correct == 1; }

    void cleanup() { _answers.clear(); }
};
