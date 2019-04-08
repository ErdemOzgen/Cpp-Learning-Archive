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

int boxVolume(int length = 1, int width = 1, int height = 1);

int main(int argc, const char *argv[]) {
    // no arguments--use default values for all dimensions
    std::cout << "The default box volume is: " << boxVolume();

    // specify length; default width and height
    std::cout << "\n\nThe volume of a box with length 10,\n"
              << "width 1 and height 1 is: " << boxVolume(10);

    // specify length and width; default height
    std::cout << "\n\nThe volume of a box with length 10,\n"
              << "width 5 and height 1 is: " << boxVolume(10, 5);

    // specify all arguments
    std::cout << "\n\nThe volume of a box with length 10,\n"
              << "width 5 and height 2 is: " << boxVolume(10, 5, 2)
              << std::endl;

    return 0;
}
// function boxVolume calculates the volume of a box
int boxVolume(int length, int width, int height) {
    return length * width * height;
}
