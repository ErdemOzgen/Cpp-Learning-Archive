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
#include "HeartRates.hpp"

int main(int argc, const char *argv[]) {
    HeartRates heartRates1("Billy", "Bunson", 11, 23, 1956);
    heartRates1.displayInformation();

    HeartRates heartRates2("Sue", "Sueson", 5, 13, 1983);
    heartRates2.displayInformation();
    return 0;
}
