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
#include <iostream>

#include "Account.hpp"

int main(int argc, const char *argv[]) {
    Account acc1(500);
    Account acc2(1500);

    std::cout << "acc1 initial balance: " << acc1.getBalance() << std::endl;
    std::cout << "acc2 initial balance: " << acc2.getBalance() << std::endl;

    acc1.credit(150);
    acc1.debit(50);

    acc2.credit(500);
    acc2.debit(2000);

    std::cout << "acc1 new balance: " << acc1.getBalance() << std::endl;
    std::cout << "acc2 new balance: " << acc2.getBalance() << std::endl;
    return 0;
}
