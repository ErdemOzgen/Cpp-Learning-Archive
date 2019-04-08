/*
 * =====================================================================================
 *
 *       Filename:  Bicycle.hpp
 *
 *    Description:  Exercise 13.18 - CarbonFootprint Abstract Class:
 *                  Polymorphism
 *
 *        Version:  1.0
 *        Created:  02/09/16 17:18:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "CarbonFootprint.hpp"

class Bicycle : public CarbonFootprint {
 public:
    Bicycle();

    virtual double getCarbonFootprint() const;

 private:
};
