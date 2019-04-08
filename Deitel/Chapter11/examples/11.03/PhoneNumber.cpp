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
#include "PhoneNumber.hpp"

#include <iomanip>

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
    in.ignore();  // skip (
    in >> std::setw(3) >> number.areaCode;
    in.ignore(2);  // skip ) and space
    in >> std::setw(3) >> number.exchange;
    in.ignore();  // skip dash (-)
    in >> std::setw(4) >> number.line;

    return in;
}
