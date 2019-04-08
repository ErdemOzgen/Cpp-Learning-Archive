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

#include <iostream>
#include <string>

#include "Utility.hpp"

class Package {
 public:
    Package(const Person&, const Person&, double, double);

    double calculateCost() { return getWeight() * getCostPerOunce(); }

    double getWeight() const { return weight; }
    double getCostPerOunce() const { return costPerOunce; }

    void printDetails() const;

 private:
    Person sender;
    Person recipient;

    double weight;
    double costPerOunce;

    void setWeight(double);
    void setCostPerOunce(double);
};
