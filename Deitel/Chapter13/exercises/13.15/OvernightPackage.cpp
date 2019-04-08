/*
 * =====================================================================================
 *
 *       Filename:  OvernightPackage.cpp
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
#include <stdexcept>

#include "OvernightPackage.hpp"

OvernightPackage::OvernightPackage(const Person& snd, const Person& rcp,
                                   double wgt, double cpo, double fpo)
    : Package(snd, rcp, wgt, cpo) {
    setFee(fpo);

    Package::setPackageType("Overnight Package");
}
// setter
void OvernightPackage::setFee(double fpo) {
    if (fpo >= 0.0f) {
        feePerOunce = fpo;
    } else {
        throw std::invalid_argument("Fee per ounce must be >= 0.0f");
    }
}
// print details
void OvernightPackage::printDetails() {
    Package::printDetails();

    std::cout << "\n\nTotal Cost: " << calculateCost();
}
