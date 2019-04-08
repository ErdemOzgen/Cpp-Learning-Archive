/*
 * =====================================================================================
 *
 *       Filename:  ex_1315.cpp
 *
 *    Description:  Exercise 13.15 - Package Inheritance Hierarchy
 *
 *        Version:  1.0
 *        Created:  24/08/16 22:44:11
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

#include "OvernightPackage.hpp"
#include "Package.hpp"
#include "TwoDayPackage.hpp"
#include "Utility.hpp"

int main(int argc, const char *argv[]) {
    // two day packages
    TwoDayPackage tdp1(
        Person("Send", "er", "Sender Street", "Send Place", "Snd", "53N-D3R"),
        Person("Reci", "pient", "Receipient Lane", "Recip Town", "Rpt",
               "R3C-3NT"),
        12.0f, 5.0f, 1.0f);
    TwoDayPackage tdp2(Person("Sue", "Sender", "From Street", "From City",
                              "From State", "53N-D3R"),
                       Person("Roger", "Reciever", "To Street", "To City",
                              "To State", "R3C-3NT"),
                       24.5f, 2.5f, 1.0f);

    // overnight packages
    OvernightPackage op1(Person("Bob", "Bobson", "12 Bob Street", "BobVille",
                                "Bobzone", "B0B-50N"),
                         Person("Sue", "Sueson", "12 Sue Street", "SueVille",
                                "Suezona", "5U3-50N"),
                         12.0f, 5.0f, 1.0f);
    OvernightPackage op2(Person("Bob", "Bobson", "12 Bob Street", "BobVille",
                                "Bobzone", "B0B-50N"),
                         Person("Sue", "Sueson", "12 Sue Street", "SueVille",
                                "Suezona", "5U3-50N"),
                         15.0f, 5.6f, 1.0f);

    std::vector<Package *> packages;

    packages.push_back(&tdp1);
    packages.push_back(&op1);
    packages.push_back(&op2);
    packages.push_back(&tdp2);

    double total = 0.0f;

    for (size_t i = 0; i < packages.size(); ++i) {
        std::cout << packages[i]->getPackageType() << "\n===== SENDER =====\n"
                  << packages[i]->getSender() << "\n===== RECIPIENT =====\n"
                  << packages[i]->getRecipient() << "\nPACKAGE COST: $"
                  << packages[i]->calculateCost() << "\n\n";

        total += packages[i]->calculateCost();
    }

    std::cout << "Total Package Cost: $" << total << std::endl;

    return 0;
}
