/*
 * =====================================================================================
 *
 *       Filename:  ex_1318.cpp
 *
 *    Description:  Exercise 13.18 - CarbonFootprint Abstract Class:
 *                  Polymorphism
 *
 *        Version:  1.0
 *        Created:  02/09/16 17:17:24
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

#include "Bicycle.hpp"
#include "Building.hpp"
#include "Car.hpp"
#include "CarbonFootprint.hpp"

int main(int argc, const char *argv[]) {
    std::vector<CarbonFootprint *> carbonFootprints;

    carbonFootprints.push_back(new Building());
    carbonFootprints.push_back(new Car());
    carbonFootprints.push_back(new Bicycle());

    for (std::size_t i = 0; i < carbonFootprints.size(); ++i) {
        std::cout << carbonFootprints[i]->getCarbonFootprint() << std::endl;
    }
    return 0;
}
