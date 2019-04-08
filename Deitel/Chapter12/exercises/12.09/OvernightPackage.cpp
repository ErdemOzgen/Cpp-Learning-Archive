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
#include <stdexcept>

#include "OvernightPackage.hpp"

OvernightPackage::OvernightPackage(const Person& snd, const Person& rcp,
                                   double wgt, double cpo, double fpo)
    : Package(snd, rcp, wgt, cpo) {
    setFee(fpo);
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
