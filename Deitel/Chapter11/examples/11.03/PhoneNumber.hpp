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
#include <string>

class PhoneNumber {
 public:
    friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);
    friend std::istream& operator>>(std::istream&, PhoneNumber&);

 private:
    std::string areaCode;
    std::string exchange;
    std::string line;
};
