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

int main(int argc, const char *argv[]) {
    int widthValue = 4;
    char sentence[10];

    std::cout << "Enter a sentence:" << std::endl;
    std::cin.width(5);  // input only 5 characters from sentence

    // set field width, then display characters based on that width
    while (std::cin >> sentence) {
        std::cout.width(widthValue++);
        std::cout << sentence << std::endl;
        std::cin.width(5);  // input 5 more characters from sentence
    }

    return 0;
}
