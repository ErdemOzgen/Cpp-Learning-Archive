/*
 * =====================================================================================
 *
 *       Filename:  Building.hpp
 *
 *    Description:  Exercise 13.18 - CarbonFootprint Abstract Class:
 *                  Polymorphism
 *
 *        Version:  1.0
 *        Created:  02/09/16 17:18:29
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

class Building : public CarbonFootprint {
 public:
    Building();

    virtual double getCarbonFootprint() const;

 private:
};
