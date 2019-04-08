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

#include "OvernightPackage.hpp"
#include "TwoDayPackage.hpp"
#include "Utility.hpp"

int main(int argc, const char *argv[]) {
    OvernightPackage op(Person("Bob", "Bobson", "12 Bob Street", "BobVille",
                               "Bobzone", "B0B-50N"),
                        Person("Sue", "Sueson", "12 Sue Street", "SueVille",
                               "Suezona", "5U3-50N"),
                        12.0f, 5.0f, 1.0f);

    TwoDayPackage tdp(
        Person("Send", "er", "Sender Street", "Send Place", "Snd", "53N-D3R"),
        Person("Reci", "pient", "Receipient Lane", "Recip Town", "Rpt",
               "R3C-3NT"),
        12.0f, 5.0f, 1.0f);

    std::cout << "Overnight Package:\n";
    op.printDetails();

    std::cout << "\n\nTwo day Package:\n";
    tdp.printDetails();

    std::cout << std::endl;

    return 0;
}
