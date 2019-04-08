/*
 * =====================================================================================
 *
 *       Filename:  OvernightPackage.hpp
 *
 *    Description:  Exercise 12.9: Package Inheritance Hierarchy
 *
 *        Version:  1.0
 *        Created:  19/07/16 18:04:13
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

class OvernightPackage : public Package {
 public:
    OvernightPackage(const Person&, const Person&, double, double, double);

    double calculateCost() {
        return Package::getWeight() *
               (Package::getCostPerOunce() + feePerOunce);
    }

    void printDetails();

 private:
    double feePerOunce;

    void setFee(double);
};
