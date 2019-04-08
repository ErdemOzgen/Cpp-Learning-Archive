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
#include <algorithm>
#include <iomanip>

#include "PhoneNumber.hpp"

// overloaded stream insertion operator; cannot be
// a member function if we would like to invoke it with
// std::cout << somePhoneNumber;
std::ostream& operator<<(std::ostream& out, const PhoneNumber& number) {
    out << "(" << number.areaCode << ") " << number.exchange << "-"
        << number.line;

    return out;
}
// overloaded stream extraction operator; cannot be
// a member function if we would like to invoke it with
// std::cin >> somePhoneNumber;
std::istream& operator>>(std::istream& in, PhoneNumber& number) {
    in.read(&number.pNumber[0], 14);

    // validate pNumber
    // length of 14
    // area code and exchange do not begin with 0 or 1
    // middle digit of area code == 0 or 1
    if (in.gcount() != 14 ||
        (number.pNumber[1] == '0' || number.pNumber[1] == '1') ||
        (number.pNumber[2] != '0' && number.pNumber[2] != '1') ||
        (number.pNumber[6] == '0' || number.pNumber[6] == '1')) {
        // set failbit
        in.setstate(std::ios::failbit);
    } else {
        char* ptrNumber = &number.pNumber[0];

        // area code
        while (*++ptrNumber != ')') {
            number.areaCode += *ptrNumber;
        }

        // increment to remove space
        ++ptrNumber;

        // exchange
        while (*++ptrNumber != '-') {
            number.exchange += *ptrNumber;
        }

        // line
        while (*ptrNumber++ != '\0') {
            number.line += *ptrNumber;
        }

        ptrNumber = nullptr;
    }

    return in;
}
