#include <cstdlib>
#include <iostream>

using namespace std;

#define EDGE	3

const int X = 1, O = -1, EMPTY = 0;
int board[EDGE][EDGE];		// 3x3 board
int currentPlayer;

void clearBoard() {
  if (system("CLS")) system ("clear"); // Clear terminal
  for (int i = 0; i < EDGE; i++) {
    for (int j = 0; j < EDGE; j++) {
      board[i][j] = EMPTY;
    }
  }
  currentPlayer = X;
}

void putMark (int i, int j) {
  board[i][j] = currentPlayer;
  currentPlayer = -currentPlayer;
}

bool isWin(int mark) {
  int win = EDGE*mark;
  int score0, score1;
  // Check rows/ccolumns:
  for (int i = 0; i < EDGE; i++) {
    score0 = 0;			// For rows
    score1 = 0;			// For columns
    for (int j = 0; j < EDGE; j++) {
      score0 += board[i][j];
      score1 += board[j][i];
    }
    if ( (score0 == win) || (score1 == win) ) 
      return true;
  }
  // Check diagonals:
  score0 = 0;
  score1 = 0;
  for (int i = 0; i < EDGE; i++) {
    score0 += board[i][i];
    score1 += board[i][EDGE-i-1];
  }
  if ( (score0 == win) || (score1 == win) ) 
    return true;
  else 
    return false;
}

int getWinner() {
  if (isWin(X)) return X;
  else if (isWin(O)) return O;
  else return EMPTY;
}

void printBoard() {
  if (system("CLS")) system("clear");
  for (int i = 0; i < EDGE; i++) {
    for (int j = 0; j < EDGE; j++) {
      switch(board[i][j]) {
      case X: cout << "X"; break;
      case O: cout << "O"; break;
      case EMPTY: cout << " "; break;
      }
      if (j < EDGE-1) cout << "|";
    }
    if (i < EDGE-1) {
      cout << "\n-";
      for (int k = 0; k < EDGE-1; k++)
	cout << "+-";
      cout << "\n";
    }
  }
  cout << endl;
}

void play() {
  int row, column;
  int winner;
  clearBoard();
  for (int i = 0, moves = EDGE*EDGE; i < moves; i++){
    printBoard();
    cout << "Please enter the row and column: ";
    cin >> row >> column;
    if (row < 0 || row >= EDGE || column < 0 || column >= EDGE) {
      i--;
      continue;
    }
    putMark(row, column);
    printBoard();
    winner = getWinner();
    if (winner) break;
  }
  
  if (winner != EMPTY)
    cout << "\n\n" << (winner == X ? 'X' : 'O') << " wins" << endl;
  else
  cout << "\n\nTie" << endl;
}

int main() {
  play();
  return EXIT_SUCCESS;
}



