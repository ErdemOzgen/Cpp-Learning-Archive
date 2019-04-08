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
#include <string>
#include <vector>

// 2D representation of point in maze
struct Coord2D {
    int x;
    int y;

    Coord2D() {}
    Coord2D(const Coord2D& C) { this->x = C.x; this->y = C.y; }
    Coord2D(int X, int Y) : x(X), y(Y) {}

    Coord2D& operator= (const Coord2D& C) {
        this->x = C.x;
        this->y = C.y;

        return *this;
    }

    bool operator== (const Coord2D& rhs) {
        return (this->x == rhs.x) && (this->y == rhs.y);
    }

    bool operator!= (const Coord2D& rhs) {
        return !(*this == rhs);
    }

    friend std::ostream& operator<< (std::ostream& os, const Coord2D& C) {
        os << C.x << ',' << C.y;

        return os;
    }
};

class Maze {
 public:
        explicit Maze(const std::string&);
        ~Maze();

        void go();

 private:
        const char START = 'X';
        const char EXIT = '@';
        const char WALL = '#';
        const char PATH = '.';
        const char VISITED = 'O';

        int WIDTH;
        int HEIGHT;

        Coord2D start;
        Coord2D exit;

        std::vector<char> maze;

        bool loadMaze(const std::string&);
        bool setStartPosition(Coord2D&, const char&);
        bool traverse(std::vector<char>&, Coord2D);
        int toIndex(const Coord2D&) const;
        bool isValid(const Coord2D&) const;
        void printMaze() const;

};  // end class Maze
