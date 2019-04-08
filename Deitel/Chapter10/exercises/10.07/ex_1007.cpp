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
#include "SavingsAccount.hpp"

int main(int argc, const char* argv[]) {
    SavingsAccount saver1(2000.00f);
    SavingsAccount saver2(3000.00f, 0.03f);
    SavingsAccount saver3(5000.00f, -0.12f);

    std::cout << "Interest rate at 3%" << std::endl;

    std::cout << "saver1 initial balance: " << saver1 << std::endl;
    saver1.calculateMonthlyInterest();
    std::cout << "after calculateInterestRate " << saver1 << std::endl;
    std::cout << "saver2 initial balance: " << saver2 << std::endl;
    saver2.calculateMonthlyInterest();
    std::cout << "after calculateInterestRate " << saver2 << std::endl;

    SavingsAccount::modifyInterestRate(0.04f);

    std::cout << "\nInterest rate at 4%" << std::endl;

    std::cout << "saver1 initial balance: " << saver1 << std::endl;
    saver1.calculateMonthlyInterest();
    std::cout << "after calculateInterestRate " << saver1 << std::endl;
    std::cout << "saver2 initial balance: " << saver2 << std::endl;
    saver2.calculateMonthlyInterest();
    std::cout << "after calculateInterestRate " << saver2 << std::endl;

    try {
        SavingsAccount::modifyInterestRate(-0.12f);
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
