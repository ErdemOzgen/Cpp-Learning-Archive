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

class C1 {
 public:
    C1() { throw 99; }
};

int main(int argc, const char *argv[]) {
    try {
        C1 c;
    } catch (int &e) {
        std::cerr << "Exception: " << e << std::endl;
    }
    return 0;
}
