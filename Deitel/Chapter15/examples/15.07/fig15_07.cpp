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
 */#include <iostream>

int main(int argc, const char *argv[]) {
    const int SIZE = 80;
    char buffer[SIZE];

    // use function read to input characters into buffer
    std::cout << "Enter a sentence:" << std::endl;
    std::cin.read(buffer, 20);

    // use functions write and gcount to display buffer characters
    std::cout << std::endl << "The sentence entered was:" << std::endl;
    std::cout.write(buffer, std::cin.gcount());
    std::cout << std::endl;

    return 0;
}
