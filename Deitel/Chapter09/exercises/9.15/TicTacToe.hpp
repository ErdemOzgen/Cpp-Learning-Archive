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

#include <iomanip>
#include <iostream>
#include <string>

enum class GameState { RUN, EXIT, INIT };
enum class PlayerState { PLAY, WIN, LOSE, DRAW };

struct Player {
    PlayerState state = PlayerState::PLAY;
    int token;
    std::string name;
    bool human = true;  // human/ai player
};

class TicTacToe {
 public:
    explicit TicTacToe(size_t cols = 3, size_t rows = 3) : ROWS(rows), COLS(cols) {
        _gameState = GameState::INIT;
    }
    ~TicTacToe() {}

    void go();

    // IO OPERATIONS
    friend std::ostream& operator<<(std::ostream& out, TicTacToe ttt) {
        return ttt.printBoard(out);
    }

    std::ostream& printBoard(std::ostream&);

 protected:
    const size_t ROWS;
    const size_t COLS;

    int* _board = new int[ROWS * COLS];  // _board[x + width*y]

    unsigned int _moves;

    GameState _gameState;

    Player _player1;
    Player _player2;

    bool initialise();  // initialises game variables
    int printMenu();
    void gameLoop();
    bool playerTurn(Player&);      // handles player move
    void move(Player&, int, int);  // moves player
    void printSummary();

    // UTILITY FUNCTIONS
    void resetBoard();                             // resets board
    bool isValidMove(unsigned int, unsigned int);  // check if move is valid
    bool isWinner(Player&);                        // check for win condition
    bool movesRemaining();                         // checks for remaining moves
};
