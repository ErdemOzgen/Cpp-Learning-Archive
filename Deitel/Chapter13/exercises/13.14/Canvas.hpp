/*
 * =====================================================================================
 *
 *       Filename:  Canvas.hpp
 *
 *    Description:  Exercise 13.14 - Project Polymorphic Screen Manager Using
 *                  Shape Hierarchy.
 *
 *                  Struct representing a canvas object (drawable area)
 *
 *        Version:  1.0
 *        Created:  22/08/16 16:57:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include <iostream>
#include <stdexcept>

struct Canvas {
    Canvas(int rows, int cols) {
        setRows(rows);
        setCols(cols);

        _canvas = new char[COLS * ROWS];

        initialise();
    }
    // initialise
    void initialise() {
        for (size_t i = 0; i < ROWS * COLS; ++i) {
            _canvas[i] = ' ';
        }
    }
    // rows
    void setRows(int rows) {
        if (rows > 0) {
            ROWS = rows;
        } else {
            throw std::invalid_argument("Canvas Error: rows must be > 0");
        }
    }
    unsigned int getRows() const { return ROWS; }
    // cols
    void setCols(int cols) {
        if (cols > 0) {
            COLS = cols;
        } else {
            throw std::invalid_argument("Canvas Error: cols must be > 0");
        }
    }
    unsigned int getCols() const { return COLS; }
    // add image to be rendered to _canvas
    // x,y is the top left corner of the image
    // image array is shape to be overlayed
    void addToCanvas(unsigned int x, unsigned int y, unsigned int width,
                     unsigned int height, const char* image) {
        // ensure x and y are not out of bounds
        if (x > COLS || y > ROWS) { return; }

        const char* imagePtr = image;

        for (unsigned int row = y; row < y + height; ++row) {
            for (unsigned int col = x; col < x + width; ++col) {
                _canvas[col + COLS * row] = *(imagePtr++);
            }
        }
    }
    // renders the canvas
    void render() const {
        for (unsigned int row = 0; row < ROWS; ++row) {
            for (unsigned int col = 0; col < COLS; ++col) {
                std::cout << _canvas[col + COLS * row];
            }
            std::cout << std::endl;
        }
    }

 private:
    unsigned int ROWS;
    unsigned int COLS;

    char* _canvas = nullptr;
};
