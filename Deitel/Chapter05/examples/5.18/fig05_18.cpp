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

int main(int argc, const char *argv[]) {
    // create truth table for && (logical AND) operator
    std::cout << std::boolalpha << "Logical AND (&&)"
              << "\nfalse && false : " << (false && false)
              << "\nfalse && true  : " << (false && true)
              << "\ntrue  && false : " << (true && false)
              << "\ntrue  && true  : " << (true && true) << "\n\n";

    // create truth table for || (logical OR) operator
    std::cout << "Logical OR (||)"
              << "\nfalse || false : " << (false || false)
              << "\nfalse || true  : " << (false || true)
              << "\ntrue  || false : " << (true || false)
              << "\ntrue  || true  : " << (true || true) << "\n\n";

    // create truth table for ! (logical negation) operator
    std::cout << "Logical NOT (!)"
              << "\n!false : " << (!false) << "\n!true  : " << (!true)
              << std::endl;
    return 0;
}
