/*
 * =====================================================================================
 *
 *       Filename:  ScreenManager.hpp
 *
 *    Description:  Exercise 13.14 - Project: Polymorphic Screen Manager Using
 *                  Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  19/08/16 18:11:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "Canvas.hpp"
#include "Shape.hpp"

#include <vector>

class ScreenManager {
 public:
    explicit ScreenManager(int = 50, int = 50);
    ~ScreenManager();

    void add(Shape*);
    void render() const;

 private:
    unsigned int ROWS;
    unsigned int COLS;

    Canvas* _canvas = nullptr;

    std::vector<Shape*> _shapes;
};
