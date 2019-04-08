/*
 * =====================================================================================
 *
 *       Filename:  Package.cpp
 *
 *    Description:  Exercise 12.9: Package Inheritance Hierarchy
 *
 *        Version:  1.0
 *        Created:  19/07/16 17:59:52
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdexcept>
#include <string>

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
// get sender as string
std::string Package::getSender() const {
    std::stringstream ss;

    ss << sender.firstName << ' ' << sender.lastName << "\n"
       << sender.address << "\n"
       << sender.city << "\n"
       << sender.state << "\n"
       << sender.zipCode << "\n";

    return ss.str();
}
// get recipient as string
std::string Package::getRecipient() const {
    std::stringstream ss;

    ss << recipient.firstName << ' ' << recipient.lastName << "\n"
       << recipient.address << "\n"
       << recipient.city << "\n"
       << recipient.state << "\n"
       << recipient.zipCode << "\n";

    return ss.str();
}
// set package type
void Package::setPackageType(std::string type) { packageType = type; }
// get package type as string
std::string Package::getPackageType() const { return packageType; }
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
