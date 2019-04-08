/*
 * =====================================================================================
 *
 *       Filename:  ScreenManager.cpp
 *
 *    Description:  Exercise 13.14 - Project: Polymorphic Screen Manager Using
 *                  Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  19/08/16 18:10:30
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

#include "ScreenManager.hpp"

ScreenManager::ScreenManager(int r, int c) {
    if (r > 0) {
        ROWS = r;
    } else {
        ROWS = 50;
    }
    if (c > 0) {
        COLS = c;
    } else {
        COLS = 50;
    }
    _canvas = new Canvas(ROWS, COLS);
}
ScreenManager::~ScreenManager() {
    if (_canvas != nullptr) { delete[] _canvas; }

    for (unsigned int i = 0; i < _shapes.size(); ++i) {
        delete _shapes[i];
    }

    _shapes.clear();
}
// adds a new shape onto current shapes list
void ScreenManager::add(Shape* s) { _shapes.push_back(s); }
// print the current shapes
void ScreenManager::render() const {
    // draw shapes and add to canvas
    for (unsigned int i = 0; i < _shapes.size(); ++i) {
        _canvas->addToCanvas(_shapes[i]->getX(), _shapes[i]->getY(),
                             _shapes[i]->getWidth(), _shapes[i]->getHeight(),
                             _shapes[i]->draw());
    }
    _canvas->render();
}
