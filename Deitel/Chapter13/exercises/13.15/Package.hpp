/*
 * =====================================================================================
 *
 *       Filename:  Package.hpp
 *
 *    Description:  Exercise 12.9: Package Inheritance Hierarchy
 *
 *        Version:  1.0
 *        Created:  19/07/16 17:59:31
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "Utility.hpp"

class Package {
 public:
    Package(const Person&, const Person&, double, double);

    double calculateCost() { return getWeight() * getCostPerOunce(); }

    double getWeight() const { return weight; }
    double getCostPerOunce() const { return costPerOunce; }

    std::string getSender() const;
    std::string getRecipient() const;

    void setPackageType(std::string);
    std::string getPackageType() const;

    void printDetails() const;

 private:
    Person sender;
    Person recipient;

    std::string packageType;

    double weight;
    double costPerOunce;

    void setWeight(double);
    void setCostPerOunce(double);
};
