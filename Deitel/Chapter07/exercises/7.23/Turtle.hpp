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

static const int ROWS = 20;
static const int COLS = 20;

enum class PENSTATE { UP, DOWN, ERASE };
enum class PENDIR { UP, DOWN, RIGHT, LEFT };

struct pen {
    PENSTATE state;
    PENDIR dir;
    int x;
    int y;

    pen(PENSTATE S, PENDIR D, int X, int Y) {
        state = S;
        dir = D;
        x = X;
        y = Y;
    }
};

class Turtle {
 private:
    bool _floor[ROWS][COLS] = {{}};
    bool _running;

    pen _pen;

 public:
    Turtle() :  _running(true), _pen(PENSTATE::UP, PENDIR::RIGHT, 0, 0) {}
    ~Turtle() {}

    void go();
    void printMenu();
    void printPen();
    int getInput();
    void process(int);
    void draw();
    void printArray();
    void reset();
};
