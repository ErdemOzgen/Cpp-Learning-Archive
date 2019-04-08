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

#include <iostream>

class EncryptionSystem {
 private:
    int plainPassCode = 0;
    int encPassCode = 0;

    // SETTERS
    bool setPlainPass(int);
    void setEncPass(int);

    bool validatePlainPass(int);

    int swapDigits(int);
    void clearPlainPass();
    void clearEncPass();

 public:
    EncryptionSystem();
    ~EncryptionSystem();

    // GETTERS
    int getPlainPass();
    int getEncPass();

    bool encrypt(int);
    int decrypt(int = 0);
};
