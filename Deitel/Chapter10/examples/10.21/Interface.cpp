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
#include "Interface.hpp"
#include "Implementation.hpp"

Interface::Interface(int v) : ptr(new Implementation(v)) {}
Interface::~Interface() { delete ptr; }

void Interface::setValue(int v) { ptr->setValue(v); }
int Interface::getValue() const { return ptr->getValue(); }
