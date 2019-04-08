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
#include "CreditLimits.hpp"

const static int QUIT = -1;

int main(int argc, const char *argv[]) {
    CreditLimits cl;

    while (cl.getAccountNumber() != QUIT) {
        cl.run();
    }
    return 0;
}
