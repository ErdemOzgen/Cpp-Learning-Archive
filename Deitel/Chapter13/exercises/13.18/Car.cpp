/*
 * =====================================================================================
 *
 *       Filename:  Car.cpp
 *
 *    Description:  Exercise 13.18 - CarbonFootprint Abstract Class:
 *                  Polymorphism
 *
 *        Version:  1.0
 *        Created:  02/09/16 17:18:52
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "Car.hpp"

Car::Car() {}
// get carbon footprint
double Car::getCarbonFootprint() const { return 2; }
