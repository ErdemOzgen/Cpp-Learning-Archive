/*
 * =====================================================================================
 *
 *       Filename:  Utility.hpp
 *
 *    Description:  Exercise 12.9: Package Inheritance Hierarchy
 *                  Utility struct - avoids passing 12 strings to package
 *                  constructor.
 *
 *        Version:  1.0
 *        Created:  19/07/16 18:22:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
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
