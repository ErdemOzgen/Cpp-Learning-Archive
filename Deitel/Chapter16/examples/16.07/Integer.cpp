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
#include "Integer.hpp"

#include <iostream>

Integer::Integer(int i) : value(i) {
    std::cout << "Constructor for Integer " << value << std::endl;
}
Integer::~Integer() {
    std::cout << "Destructor for Integer " << value << std::endl;
}
// set Integer value
void Integer::setInteger(int i) { value = i; }
// get Integer value
int Integer::getInteger() const { return value; }
