/*
 * =====================================================================================
 *
 *       Filename:  TwoDayPackage.hpp
 *
 *    Description:  Exercise 12.9: Package Inheritance Hierarchy
 *
 *        Version:  1.0
 *        Created:  19/07/16 17:59:57
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "Package.hpp"

class TwoDayPackage : public Package {
 public:
    TwoDayPackage(const Person&, const Person&, double, double, double);

    double calculateCost() { return Package::calculateCost() + flatFee; }

    void printDetails();

 private:
    double flatFee;

    void setFee(double);
};
