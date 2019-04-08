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
#include "Increment.hpp"

#include <iostream>

Increment::Increment(int c, int i) : count(c), increment(i) {}
// print count and increment values
void Increment::print() const {
    std::cout << "count = " << count << ", increment = " << increment
              << std::endl;
}
