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

class TwoDayPackage : public Package {
 public:
    TwoDayPackage(const Person&, const Person&, double, double, double);

    double calculateCost() { return Package::calculateCost() + flatFee; }

    void printDetails();

 private:
    double flatFee;

    void setFee(double);
};
