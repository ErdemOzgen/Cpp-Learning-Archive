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
#include "Time.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    Time t;

    std::cout << "The initial universal time is ";
    t.printUniversal();

    std::cout << "\nThe initial standard time is ";
    t.printStandard();

    t.setTime(13, 27, 6);

    std::cout << "\n\nUniversal time after setTime is: ";
    t.printUniversal();
    std::cout << "\nStandard time after setTime is: ";
    t.printStandard();

    // set time with invalid values
    try {
        t.setTime(99, 99, 99);
    } catch (std::invalid_argument e) {
        std::cout << "\n\nException: " << e.what() << std::endl << std::endl;
    }

    // output t's values after specifying invalid values
    std::cout << "After attempting invalid settings: "
              << "\nUniversal Time: ";
    t.printUniversal();

    std::cout << "\nStandard Time: ";
    t.printStandard();

    std::cout << std::endl;
    return 0;
}
