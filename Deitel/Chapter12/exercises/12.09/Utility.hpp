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

#include <string>

struct Person {
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    std::string zipCode;

    Person(const std::string& fn, const std::string& ln, const std::string& add,
           const std::string& ct, const std::string& st, const std::string& zc)
        : firstName(fn),
          lastName(ln),
          address(add),
          city(ct),
          state(st),
          zipCode(zc) {}
};
