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

class Coord2D {
 public:
    explicit Coord2D(int X = 0, int Y = 0) {
        setX(X);
        setY(Y);
    }

    // SETTERS
    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }

    // GETTERS
    int getX() { return x; }
    int getY() { return y; }

 private:
    int x;
    int y;
};
