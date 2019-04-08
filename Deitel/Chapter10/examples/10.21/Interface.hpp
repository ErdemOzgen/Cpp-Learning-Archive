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

class Implementation;  // forward class declaration require by private
                       // declaration

class Interface {
 public:
    Interface(int);
    ~Interface();

    void setValue(int);
    int getValue() const;

 private:
    // requires forward declaration
    Implementation *ptr;
};
