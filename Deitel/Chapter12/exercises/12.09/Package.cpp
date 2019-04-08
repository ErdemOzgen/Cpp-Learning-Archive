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
#include <iostream>
#include <stdexcept>

#include "Package.hpp"

Package::Package(const Person& snd, const Person& rcp, double wgt, double cpo)
    : sender(snd), recipient(rcp) {
    setWeight(wgt);
    setCostPerOunce(cpo);
}
// setters
void Package::setWeight(double wgt) {
    if (wgt > 0.0f) {
        weight = wgt;
    } else {
        throw std::invalid_argument("Weight must be a positive value.");
    }
}
void Package::setCostPerOunce(double cpo) {
    if (cpo > 0.0f) {
        costPerOunce = cpo;
    } else {
        throw std::invalid_argument("Cost Per Ounce must be a positive value.");
    }
}
// print package details
void Package::printDetails() const {
    std::cout << "===== SENDER =====\n"
              << sender.firstName << ' ' << sender.lastName << "\n"
              << sender.address << "\n"
              << sender.city << "\n"
              << sender.state << "\n"
              << sender.zipCode << "\n===== RECIPIENT =====\n"
              << recipient.firstName << ' ' << recipient.lastName << "\n"
              << recipient.address << "\n"
              << recipient.city << "\n"
              << recipient.state << "\n"
              << recipient.zipCode;
}
