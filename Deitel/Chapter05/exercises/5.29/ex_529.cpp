/*
 * =====================================================================================
 *
 *       Filename:  ex_529.cpp
 *
 *    Description:  Exercise 5.29 - Peter Minuit Problem
 *                  NOTE: Not my solution. I couldn't be doing with figuring
 *                  this out.
 *                  http://kmishra.net/log/0808/PeterMinuit.C
 *
 *        Version:  1.1
 *        Created:  04/04/16 16:44:33
 *       Revision:  08/04/16 14:36:20
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, const char *argv[]) {
    double amount;
    double principal = 24.0f;

    std::cout << std::fixed << std::setprecision(2);

    // outer loop interest rate .05 to .10
    for (float rate = 0.05; rate <= 0.10; rate += 0.01) {
        // display headers
        std::cout << "\nInterest rate: " << rate * 100 << "%\n"
                  << "Year" << std::setw(30) << "Amount on deposit"
                  << std::endl;

        // calculate amount on deposit for each of 10 years
        for (int year = 1626; year < 2020; year++) {
            // calculate new amount for specified year
            amount = principal * pow(1.0 + rate, year - 1626);

            // display year and amount
            if (year == 1626 || year == 2008 || year == 2010 || year == 2020 ||
                year % 50 == 0) {
                std::cout << std::setw(4) << year << std::setw(30) << amount
                          << std::endl;
            }
        }
    }
    return 0;
}
