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

const int capacity = 11;

enum class Availability { BOTH, FIRST, SECOND, FULL };

class ReservationSystem {
 private:
    bool _plane[capacity] = {};

    Availability _availability;

 public:
    ReservationSystem();

    void go();
    void printMenu();
    void printSeatingPlan();
    bool isSeatAvailable(int);
    int bookSeat(int);
    void checkCapacity();
    void printBoardingPass(int);
};
