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
