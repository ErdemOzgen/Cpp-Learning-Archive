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
#include "Turtle.hpp"

void Turtle::go() {
    std::cout << "\n*** Welcome to the Turtle Graphics Program ***\n\n";

    while (_running) {
        printMenu();
        process(getInput());
    }
}
// prints the selection menu
void Turtle::printMenu() {
    std::cout << "1   - Pen Up\n"
              << "2   - Pen Down\n"
              << "3   - Pen Erase\n"
              << "4   - Turn Right\n"
              << "5   - Turn Left\n"
              << "6   - Move Forward n Spaces\n"
              << "7   - Print Your Creation\n"
              << "9   - Exit Program\n"
              << "13  - Reset and Redraw" << std::endl;
}
// prints the current pen metrics
void Turtle::printPen() {
    std::cout << "\nState:";
    switch (_pen.state) {
        case PENSTATE::UP:
            std::cout << " UP ";
            break;
        case PENSTATE::DOWN:
            std::cout << " DOWN ";
            break;
        case PENSTATE::ERASE:
            std::cout << " ERASE ";
            break;
    }
    std::cout << "\nDirection:";

    switch (_pen.dir) {
        case PENDIR::RIGHT:
            std::cout << " RIGHT ";
            break;
        case PENDIR::LEFT:
            std::cout << " LEFT ";
            break;
        case PENDIR::UP:
            std::cout << " UP ";
            break;
        case PENDIR::DOWN:
            std::cout << " DOWN ";
            break;
    }
    std::cout << "\n(" << _pen.x << "," << _pen.y << ")\n" << std::endl;
}
// fetches the input
int Turtle::getInput() {
    int choice = 0;

    while (true) {
        std::cout << "> ";
        std::cin >> choice;

        if ((choice >= 1 && choice <= 9) || choice == 13) {
            return choice;
        } else {
            std::cout << "Incorrect Input" << std::endl;
        }
    }
}
// processes the input - updates pen or sets exit condition
void Turtle::process(int choice) {
    if (choice == 9) { _running = !_running; }

    switch (choice) {
        case 1:
            _pen.state = PENSTATE::UP;
            break;
        case 2:
            _pen.state = PENSTATE::DOWN;
            break;
        case 3:
            _pen.state = PENSTATE::ERASE;
            break;
        case 4:
            if (_pen.dir == PENDIR::RIGHT) {
                _pen.dir = PENDIR::DOWN;
            } else if (_pen.dir == PENDIR::DOWN) {
                _pen.dir = PENDIR::LEFT;
            } else if (_pen.dir == PENDIR::LEFT) {
                _pen.dir = PENDIR::UP;
            } else if (_pen.dir == PENDIR::UP) {
                _pen.dir = PENDIR::RIGHT;
            }
            break;
        case 5:
            if (_pen.dir == PENDIR::RIGHT) {
                _pen.dir = PENDIR::UP;
            } else if (_pen.dir == PENDIR::UP) {
                _pen.dir = PENDIR::LEFT;
            } else if (_pen.dir == PENDIR::LEFT) {
                _pen.dir = PENDIR::DOWN;
            } else if (_pen.dir == PENDIR::DOWN) {
                _pen.dir = PENDIR::RIGHT;
            }
            break;
        case 6:
            int steps, limit;
            std::cout << "Enter number of spaces to move: ";
            std::cin >> steps;

            // increment position considering direction and prevent out of
            // bounds
            if (_pen.dir == PENDIR::RIGHT) {
                limit = COLS - 1;

                // if pen is up just update pen coords
                if (_pen.state == PENSTATE::UP) {
                    _pen.x =
                        ((_pen.x + steps) > limit) ? limit : (_pen.x + steps);
                    // pen is down so draw
                } else {
                    for (; steps >= 0; ++_pen.x, --steps) {
                        draw();
                        // prevent out of bounds
                        if (_pen.x == limit) { break; }
                    }
                }
            }
            if (_pen.dir == PENDIR::LEFT) {
                limit = 0;

                // pen is up update coords
                if (_pen.state == PENSTATE::UP) {
                    _pen.x =
                        ((_pen.x - steps) > limit) ? (_pen.x - steps) : limit;
                    // pen is down draw
                } else {
                    for (; steps >= 0; --_pen.x, --steps) {
                        draw();
                        // prevent out of bounds
                        if (_pen.x == limit) { break; }
                    }
                }
            }
            if (_pen.dir == PENDIR::UP) {
                limit = 0;

                // pen is up update coords
                if (_pen.state == PENSTATE::UP) {
                    _pen.y =
                        ((_pen.y - steps) > limit) ? (_pen.y - steps) : limit;
                    // pen is down draw
                } else {
                    for (; steps >= 0; --_pen.y, --steps) {
                        draw();
                        // prevent out of bounds
                        if (_pen.y == limit) { break; }
                    }
                }
            }
            if (_pen.dir == PENDIR::DOWN) {
                limit = ROWS - 1;

                // pen is up update coords
                if (_pen.state == PENSTATE::UP) {
                    _pen.y =
                        ((_pen.y + steps) < limit) ? (_pen.y + steps) : limit;
                    // pen is down draw
                } else {
                    for (; steps >= 0; ++_pen.y, --steps) {
                        draw();
                        // prevent out of bounds
                        if (_pen.y == limit) { break; }
                    }
                }
            }
            break;
        case 7:
            printArray();
            break;
        case 13:
            reset();
            break;
    }

    printPen();
}
// updates the array
void Turtle::draw() {
    // only draw if pen is down
    if (_pen.state == PENSTATE::DOWN) {
        _floor[_pen.y][_pen.x] = true;
    }
    if (_pen.state == PENSTATE::ERASE) {
        _floor[_pen.y][_pen.x] = false;
    }
}
// prints the current array
void Turtle::printArray() {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (_floor[row][col]) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}
// resets program to draw again
void Turtle::reset() {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            _floor[row][col] = false;
        }
    }
    _pen.state = PENSTATE::UP;
    _pen.dir = PENDIR::RIGHT;
    _pen.x = 0;
    _pen.y = 0;
}
