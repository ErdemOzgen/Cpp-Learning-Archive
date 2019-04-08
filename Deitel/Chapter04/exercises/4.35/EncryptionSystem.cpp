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
#include "EncryptionSystem.hpp"

EncryptionSystem::EncryptionSystem() {}
EncryptionSystem::~EncryptionSystem() {
    clearPlainPass();
    clearEncPass();
}

// SETTERS
bool EncryptionSystem::setPlainPass(int plain) {
    if (validatePlainPass(plain)) {
        plainPassCode = plain;

        return true;
    }

    return false;
}
void EncryptionSystem::setEncPass(int enc) { encPassCode = enc; }

// GETTERS
int EncryptionSystem::getPlainPass() { return plainPassCode; }
int EncryptionSystem::getEncPass() { return encPassCode; }

// validate plain pass code is 4 digits in length
bool EncryptionSystem::validatePlainPass(int plain) {
    int counter = 0;

    while (plain > 0) {
        plain /= 10;
        counter++;
    }

    return (counter == 4) ? true : false;
}
// 1 - Replace each digit with the result of adding 7 and getting the remainder
// when divided by 10
// 2 - Swap 1st & 3rd and 2nd & 4th digits.
bool EncryptionSystem::encrypt(int plain) {
    if (setPlainPass(plain)) {
        // individual digits
        int digits = 0;

        for (int i = 3; i >= 0; i--) {
            digits = (digits * 10) + ((plain % 10) + 7) % 10;
            plain /= 10;
        }

        swapDigits(digits);
        setEncPass(digits);
        clearPlainPass();

        return true;
    }
    std::cout << "ERROR: Invalid length. A 4 digit pass code is required"
              << std::endl;
    return false;
}
int EncryptionSystem::decrypt(int enc) {
    int digits = 0;

    if (enc == 0) {
        enc = getEncPass();
    }

    swapDigits(enc);

    for (int i = 3; i >= 0; i--) {
        digits = (digits * 10) + (((enc % 10) + 10) - 7) % 10;
        enc /= 10;
    }

    clearEncPass();
    setPlainPass(digits);

    return digits;
}
int EncryptionSystem::swapDigits(int digits) {
    int a, b, c, d, tmp, swapped = 0;

    d = digits % 10;
    digits /= 10;

    c = digits % 10;
    digits /= 10;

    b = digits % 10;
    digits /= 10;

    tmp = digits;
    a = c;

    c = tmp;

    tmp = b;
    b = d;
    d = tmp;

    swapped = (swapped * 10) + a;
    swapped = (swapped * 10) + b;
    swapped = (swapped * 10) + c;
    swapped = (swapped * 10) + d;

    return swapped;
}
void EncryptionSystem::clearPlainPass() { plainPassCode = 0; }
void EncryptionSystem::clearEncPass() { encPassCode = 0; }
