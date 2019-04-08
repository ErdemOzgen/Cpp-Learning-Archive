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
#include "TicTacToe.hpp"

#include <vector>

// Initialise board and players to default values
bool TicTacToe::initialise() {
    int choice = printMenu();

    if (choice == 0) {
        return false;
    }

    _player1.state = PlayerState::PLAY;
    _player1.token = 1;
    _player1.name = "Player1";

    _player2.state = PlayerState::PLAY;
    _player2.token = 2;
    _player2.name = "Player2;";

    _player2.human = (choice == 1);

    resetBoard();
    _moves = 0;

    _gameState = GameState::RUN;

    return true;
}
void TicTacToe::go() {
    while (initialise()) {
        gameLoop();
    }

    if (_board != nullptr) {
        delete[] _board;
    }
}
void TicTacToe::gameLoop() {
    while (_gameState == GameState::RUN && movesRemaining()) {
        if (playerTurn(_player1)) {
            std::cout << "WINNER" << std::endl;
            _player1.state = PlayerState::WIN;
            _player2.state = PlayerState::LOSE;

            _gameState = GameState::EXIT;
        }
        if (_gameState == GameState::RUN) {
            if (movesRemaining()) {
                if (playerTurn(_player2)) {
                    _player2.state = PlayerState::WIN;
                    _player1.state = PlayerState::LOSE;

                    _gameState = GameState::EXIT;
                }
            } else {
                _gameState = GameState::EXIT;

                _player1.state = PlayerState::DRAW;
                _player2.state = PlayerState::DRAW;
            }
        }
    }
    printSummary();
}
// prints menu
int TicTacToe::printMenu() {
    int choice = 0;
    std::cout << "\n***** Welcome to TicTacToe *****\n"
              << "1. Player vs Player\n"
              << "2. Player vs Computer\n"
              << "0. Exit\n"
              << "> ";

    std::cin >> choice;

    return choice;
}
// Processes player turn
// returns win condition (if any)
bool TicTacToe::playerTurn(Player& pl) {
    ++_moves;

    std::cout << *(this);

    if (pl.human) {
        unsigned int x = -99;
        unsigned int y = -99;

        while (!isValidMove(x, y)) {
            std::cout << "\nMove " << _moves << ". " << pl.name
                      << " enter Row & Col number to move: ";

            if (std::cin >> y) {
                // account for no space between coords
                if (y > 9) {
                    x = y % 10;
                    y /= 10;
                } else {
                    std::cin >> x;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(80, '\n');

                continue;
            }
        }

        move(pl, x, y);
    } else {
        // computer move
    }

    return isWinner(pl);
}
// adds the specified token to the game board
// position needs validating before function call
void TicTacToe::move(Player& pl, int x, int y) {
    _board[x + COLS * y] = pl.token;
}
// IO OPERATIONS
// prints game results
void TicTacToe::printSummary() {
    std::cout << "\n******** GAME OVER ********\n"
              << "\nMOVES: " << _moves << "\nRESULT: ";
    if (_player1.state == PlayerState::DRAW) {
        std::cout << "It's a DRAW!!!!!\n\n";
    } else {
        std::cout << ((_player1.state == PlayerState::WIN) ? "Player1 "
                                                           : "Player2 ")
                  << "WON!!!!!\n\n";
    }

    // print the board
    std::cout << *(this) << std::endl;
}
std::ostream& TicTacToe::printBoard(std::ostream& out) {
    // print headers
    out << "   ";

    for (unsigned int i = 0; i < COLS; ++i) {
        out << i << " ";
    }
    out << "\n   " << std::setfill('-') << std::setw(COLS * 2) << "";
    out << std::setw(0) << "\n";

    for (unsigned int y = 0; y < ROWS; ++y) {
        out << y << "| ";
        for (unsigned int x = 0; x < COLS; ++x) {
            if (_board[x + COLS * y] == 0) {
                out << "  ";
            } else {
                out << ((_board[x + COLS * y] == 1) ? "X " : "O ");
            }
        }
        out << "\n";
    }
    return out;
}
// UTILITY FUNCTIONS
// resets board to default values
void TicTacToe::resetBoard() {
    for (unsigned int i = 0; i < ROWS * COLS; ++i) {
        _board[i] = 0;
    }
}
// check for valid move
// no need to check >= 0 as unsigned
bool TicTacToe::isValidMove(unsigned int x, unsigned int y) {
    // no need to check >= 0 as unsigned
    if ((x < COLS) && (y < ROWS)) {
        return _board[x + COLS * y] == 0;
    }
    return false;
}
// checks for win condition
// x + WIDTH*y
bool TicTacToe::isWinner(Player& pl) {
    // ROWS AND COLS
    // y count counts row[x]
    // x count counts col[y]
    int dX = COLS - 1;  // diagonal cols (need decrementing for right to left)

    // === ROWS === //
    for (unsigned int y = 0, rCount = 0, lrCount = 0, rlCount = 0; y < ROWS;
         ++y, rCount = 0) {
        // DIAGONAL WIN
        // left to right
        if (_board[0 + COLS * 0] == pl.token &&
            _board[y + COLS * y] == pl.token) {
            if (++lrCount == COLS) {
                return true;
            }
        }
        // right to left
        if (_board[COLS - 1 + COLS * 0] == pl.token &&
            _board[dX + COLS * y] == pl.token) {
            if (++rlCount == COLS) {
                return true;
            }
            --dX;  // decrement diagonal columns
        }
        // === COLS === //
        for (unsigned int x = 0; x < COLS; ++x) {
            // ROW WIN
            if (_board[x + COLS * y] == pl.token) {
                if (++rCount == COLS) {
                    return true;
                }
                // COL WIN
                // only iterate if token is present on first row
                if (y == 0) {
                    for (unsigned int wRow = 1, cCount = 1; wRow < ROWS;
                         ++wRow) {
                        if (_board[x + COLS * wRow] == pl.token) {
                            if (++cCount == ROWS) {
                                return true;
                            }
                        } else {  // no need to continue
                            break;
                        }
                    }
                }
            }
        }
    }
    return false;
}
// check for remaining moves
inline bool TicTacToe::movesRemaining() { return (_moves < (ROWS * COLS)); }
