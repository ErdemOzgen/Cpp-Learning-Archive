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
#include <stdexcept>

#include "SavingsAccount.hpp"

double SavingsAccount::annualInterestRate = 0.0f;

SavingsAccount::SavingsAccount(double bal, double rte) : savingsBalance(bal) {
    try {
        modifyInterestRate(rte);
    } catch (std::invalid_argument& e) {
        std::cout << "Unable to initialise object: " << e.what() << std::endl;
    }
}
void SavingsAccount::calculateMonthlyInterest() {
    savingsBalance += ((savingsBalance * annualInterestRate) / 12.0f);
}
double SavingsAccount::getInterestRate() { return annualInterestRate; }
void SavingsAccount::modifyInterestRate(double rte) {
    if (rte >= 0.0f) {
        annualInterestRate = rte;
    } else {
        throw std::invalid_argument("Interest rate cannot be negative");
    }
}
std::ostream& SavingsAccount::printBalance(std::ostream& out) const {
    out << savingsBalance;

    return out;
}
