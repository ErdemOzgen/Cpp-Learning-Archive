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
#include <cstdlib>
#include <ctime>
#include <iostream>

int rollDice();

int main(int argc, const char *argv[]) {
    enum Status { CONTINUE, WON, LOST };

    int myPoint;
    Status gameStatus;

    // randomize random number generator using current time
    srand(time(0));

    int sumOfDice = rollDice();

    // determine game status and point (if needed) based on first roll
    switch (sumOfDice) {
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            std::cout << "Point is " << myPoint << std::endl;
            break;
    }

    while (gameStatus == CONTINUE) {
        sumOfDice = rollDice();

        if (sumOfDice == myPoint) {
            gameStatus = WON;
        } else {
            if (sumOfDice == 7) {
                gameStatus = LOST;
            }
        }
    }

    if (gameStatus == WON) {
        std::cout << "Player wins" << std::endl;
    } else {
        std::cout << "Player loses" << std::endl;
    }

    return 0;
}
int rollDice() {
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;

    int sum = die1 + die2;

    std::cout << "Player rolled " << die1 << " + " << die2 << " = " << sum
              << std::endl;

    return sum;
}
