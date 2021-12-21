
#include <iostream>

using namespace std;

int const BOARD_SIZE = 3;
int board[BOARD_SIZE*BOARD_SIZE] = {0};		// 0 for empty, +1 for first player, -1 for the second player

char boardChar(int i, int j) {
  int index = i*BOARD_SIZE + j;
  switch (board[index]) {
  case 1: return 'X';
  case 2: return 'O';
  default: return ' ';
  }
}

void drawBoard() {
  /*
   * +---+---+---+
   * | X | O |   |
   * +---+---+---+
   * |   | X |   |
   * +---+---+---+
   * | O |   | X |
   * +---+---+---+
   */
  for (int i = 0; i < BOARD_SIZE; i++) { // Rows
    for (int j = 0; j < BOARD_SIZE; j++) { // Columns
      cout << "+---";
    }
    cout << "+\n";
    for (int j = 0; j < BOARD_SIZE; j++) {
      cout << "| " << boardChar(i, j) << ' ';
    }
    cout << "|\n";
  }
  for (int i = 0; i < BOARD_SIZE; i++) {
    cout << "+---";
  }
  cout << "+\n";
}

void userMove() {
  cout << "Please, give the move coordinates: ";
  cin >> x >> y;
}

void move (bool turn) {
  if (turn) {
    userMove();
  } else {
    computerMove();
  }
}

int main() {
  int ans = 'z';
  int user, comp;
  bool turn;
  
  do {
    cout "Would you like to go first (Y/n)? ";
    cin >> ans;
  } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
  if (ans == 'y' || ans == 'Y') {
    turn = true;
    user = 1;
    comp = -1;
  } else {
    turn = false;
    user = -1;
    comp = 1;
  }

  move(turn);  
  drawBoard();
}
