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
#include "Poker.hpp"
#include "DeckOfCards.hpp"

#include <iostream>
#include <string>

Poker::Poker() : running(true) { players.push_back(Hand(true)); }
void Poker::go() {
    setPlayers();

    while (running) {
        processTurns();
        showResult();

        running = playAgain();

        // reinitialise and reshuffle deck
        if (running) {
            DeckOfCards::reset();

            for (unsigned int i = 0; i < players.size(); ++i) {
                players[i].reset();
            }

            std::cout << DeckOfCards::cardsRemaining() << std::endl;
        }
    }
}
void Poker::setPlayers() {
    std::string name;

    std::cout << "Enter number of players: ";
    std::cin >> numPlayers;

    if (numPlayers == 0) {
        std::cout << "Exiting..." << std::endl;
        running = !running;
    }

    for (unsigned int i = 0; i < numPlayers; ++i) {
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin >> name;

        players.push_back(Hand(false, name));
    }
}
void Poker::processTurns() {
    for (unsigned int i = 0; i < players.size(); ++i) {
        std::cout << "\n==========\n"
                  << players[i].getName() << " turn"
                  << "\n==========\n\n";

        if (!players[i].isDealer()) {
            players[i].showHand();
            printf("\n");
        }

        players[i].turn();

        if (!players[i].isDealer()) {
            std::cout << "\nFinal Hand\n**********\n";
            players[i].showHand();
            printf("**********\n");
        }
    }
}
void Poker::showResult() {
    std::cout << "\n==========\n"
              << "RESULTS\n"
              << "==========\n";

    int winner = 0;
    int high = 0;

    for (unsigned int i = 0; i < players.size(); ++i) {
        std::cout << players[i].getName() << ": " << players[i].getScore()
                  << "\n";

        printf("\n");
        players[i].showHand();
        printf("\n");

        if (players[i].getNumScore() > high) {
            high = players[i].getNumScore();
            winner = i;
        }
    }
    std::cout << "***** " << players[winner].getName() << " WINS!!! *****\n";
}
bool Poker::playAgain() {
    int choice = 0;
    std::cout << "1. Play again\n2. Exit\n> ";
    std::cin >> choice;

    return (choice == 1);
}
