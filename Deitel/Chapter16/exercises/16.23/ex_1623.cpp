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
#include <stdexcept>

int main(int argc, const char *argv[]) {
    try {
        int i = 6;
        double d = 6.5;

        false ? throw i : throw d;  // double should throw
    } catch (int &i) {
        std::cout << "i was thrown" << std::endl;
    } catch (double &d) {
        std::cout << "d was thrown" << std::endl;
    }
    return 0;
}
