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

#include "TwoDayPackage.hpp"

TwoDayPackage::TwoDayPackage(const Person& snd, const Person& rcp, double wgt,
                             double cpo, double fee)
    : Package(snd, rcp, wgt, cpo) {
    setFee(fee);
}
// setters
void TwoDayPackage::setFee(double fee) {
    if (fee >= 0.0f) {
        flatFee = fee;
    } else {
        throw std::invalid_argument("Flat fee must be >= 0.0f");
    }
}
// print details
void TwoDayPackage::printDetails() {
    Package::printDetails();

    std::cout << "\n\nTotal Cost: " << calculateCost();
}
