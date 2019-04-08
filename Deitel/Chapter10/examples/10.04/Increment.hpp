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
#pragma once

class Increment {
 public:
    Increment(int c = 0, int i = 1);

    // function addIncrement definition
    void addIncrement() { count += increment; }
    void print() const;

 private:
    int count;

    const int increment;
};
