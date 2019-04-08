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

#include <iomanip>
#include <iostream>
#include <string>

class Poll {
 private:
    static const size_t TOPICS = 5;
    static const size_t RESPONSES = 10;

    std::string topics[TOPICS];
    int responses[TOPICS][RESPONSES];

 public:
    Poll();
    ~Poll() {}

    void initialise();
    void go();
    void askPoll();
    void printResults();
};
