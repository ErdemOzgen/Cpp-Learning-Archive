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

class Integer {
 public:
    Integer(int i = 0);
    ~Integer();

    void setInteger(int i);
    int getInteger() const;

 private:
    int value;
};
