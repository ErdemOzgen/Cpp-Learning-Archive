/*
 * =====================================================================================
 *
 *       Filename:  Bicycle.cpp
 *
 *    Description:  Exercise 13.18 - CarbonFootprint Abstract Class:
 *                  Polymorphism
 *
 *        Version:  1.0
 *        Created:  02/09/16 17:19:04
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "Bicycle.hpp"

Bicycle::Bicycle() {}
// get carbon footprint
double Bicycle::getCarbonFootprint() const { return 3; }
