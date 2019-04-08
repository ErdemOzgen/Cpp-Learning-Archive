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
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>

#include "Maze.hpp"

Maze::Maze(const std::string& fname) {
    if (!loadMaze(fname)) {
        std::cout << "Error loading maze: Invalid filename" << std::endl;
    }
}  // end constructor Maze

Maze::~Maze() {
}  // end destructor Maze

/**
 * Loads the maze
 * @param string
 */
bool Maze::loadMaze(const std::string& fname) {
    std::ifstream file(fname, std::ios::in | std::ios::binary);

    if (!file.is_open()) { return false; }

    // read contents into maze
    if (file.good()) {
        // set width and height
        file >> WIDTH >> HEIGHT;

        // read file char by char into maze
        char c;
        while (file.get(c)) {
            if (c == '\n') { continue; }
            maze.emplace_back(c);
        }

        file.close();

        return (setStartPosition(start, START) && setStartPosition(exit, EXIT));
    }

    return false;
}  // end method loadMaze

/**
 * Generic function to set position of given entity.
 * @param Coord2D
 * @param char
 * @return bool
 */
bool Maze::setStartPosition(Coord2D& pos, const char& token) {
    auto itr = std::find(maze.begin(), maze.end(), token);

    // get index of entity in vector
    if (itr != maze.end()) {
        int index = std::distance(maze.begin(), itr);

        // convert to 2d coords
        pos = Coord2D((index % WIDTH), (index / HEIGHT));

        // replace token with path
        *(itr) = PATH;
    } else {
        std::cout << "Entity " << token << " not found in map" << std::endl;
        return false;
    }

    return true;
}  // end method setStartPosition

/**
 * Traverses the maze.
 * @param std::vector<char>
 * @param Coord2D
 * @return bool
 */
bool Maze::traverse(std::vector<char>& maze, Coord2D current) {
    // outside of maze / not PATH
    if (!isValid(current)) { return false; }

    maze[toIndex(current)] = VISITED;

    // found exit
    if (current == exit) { return true; }

    printMaze();

    // .25 second sleep to follow along
    usleep(250000);

    // NORTH
    if (traverse(maze, Coord2D(current.x, current.y - 1))) { return true; }

    // EAST
    if (traverse(maze, Coord2D(current.x + 1, current.y))) { return true; }

    // SOUTH
    if (traverse(maze, Coord2D(current.x, current.y + 1))) { return true; }

    // WEST
    if (traverse(maze, Coord2D(current.x - 1, current.y))) { return true; }

    maze[toIndex(current)] = PATH;

    return false;
}  // end method traverse

/**
 * Converts Coord2D to 1D index subscript.
 * @param Coord2D
 * @return int
 */
int Maze::toIndex(const Coord2D& coord) const {
    return WIDTH * coord.y + coord.x;
}  // end method Maze::toIndex

/**
 * Determines whether given Coord2D is out of bounds.
 * @param Coord2D
 */
bool Maze::isValid(const Coord2D& coord) const {
    return ((coord.x >= 0) && (coord.y >= 0)) &&
        ((coord.x <= WIDTH) && (coord.y <= HEIGHT)) &&
        (maze[toIndex(coord)] == PATH);
}  // end method isValid

/**
 * Prints the maze
 */
void Maze::printMaze() const {
    for (int row = 0; row < WIDTH; ++row) {
        for (int col = 0; col < HEIGHT; ++col) {
            std::cout << ((maze[toIndex(Coord2D(col, row))] == PATH) ? ' ' : maze[toIndex(Coord2D(col, row))]);
        }
        std::cout << std::endl;
    }
}  // end method printMaze

/**
 * Entry point
 */
void Maze::go() {
    if (traverse(maze, start)) {
        std::cout << "SUCCESS" << std::endl;
    } else {
        std::cout << "FAILURE" << std::endl;
    }

    printMaze();
}  // end method go
