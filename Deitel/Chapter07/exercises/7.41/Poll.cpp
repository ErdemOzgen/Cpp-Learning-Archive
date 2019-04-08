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
#include "Poll.hpp"

Poll::Poll() { initialise(); }
// intialise arrays
void Poll::initialise() {
    topics[0] = "Topic 1";
    topics[1] = "Topic 2";
    topics[2] = "Topic 3";
    topics[3] = "Topic 4";
    topics[4] = "Topic 5";

    for (unsigned int t = 0; t < TOPICS; ++t) {
        for (unsigned int r = 0; r < RESPONSES; ++r) {
            responses[t][r] = 0;
        }
    }
}
// entry point
void Poll::go() {
    char choice;

    while (true) {
        askPoll();

        std::cout << "Add participant (y/n)? ";
        std::cin >> choice;

        if (choice == 'n' || choice == 'N') { break; }
    }

    printResults();
}
// asks one person the poll
void Poll::askPoll() {
    std::cout << "\nRate the following topics on a scale of 1(least) to "
                 "10(most) important\n"
              << std::endl;

    for (unsigned int t = 0, r = 0; t < TOPICS; ++t, r = 0) {
        while (true) {
            std::cout << topics[t] << ": ";
            std::cin >> r;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                continue;
            }

            if (r > 0 && r <= RESPONSES) { break; }
        }
        ++responses[t][r - 1];
    }
}
// displays the results
void Poll::printResults() {
    // highest and lowest issue totals/indices
    unsigned int high = 0;
    unsigned int highIndex = 0;
    unsigned int low = 0;
    unsigned int lowIndex = 0;

    std::cout << "\n*** POLL RESULTS ***\n" << std::endl;

    std::cout << "TOPIC\t\t1  2  3  4  5  6  7  8  9  10\tAverage" << std::endl;
    std::cout << "--------------------------------------------------------"
              << std::endl;

    for (unsigned int t = 0, total = 0, counter = 0; t < TOPICS;
         ++t, total = 0, counter = 0) {
        std::cout << topics[t] << "\t\t";

        for (unsigned int r = 0; r < RESPONSES; ++r) {
            std::cout << responses[t][r] << "  ";

            if (responses[t][r] > 0) {
                // calculate total score r+1 * no of votes
                total += responses[t][r] * (r + 1);
                // number of responses for average
                counter += responses[t][r];
            }
        }

        // calculate highest/lowest responses
        if (total > high) {
            high = total;
            highIndex = t;
        }
        // account for first iteration low
        if (t == 0) {
            low = total;
            lowIndex = t;
        } else if (total < low) {
            low = total;
            lowIndex = t;
        }
        // print average
        std::cout << "\t" << (total / counter) << std::endl;
    }

    std::cout << "\nHighest point total: " << topics[highIndex] << " : " << high
              << std::endl;
    std::cout << "Lowest point total : " << topics[lowIndex] << " : " << low
              << std::endl;
}
