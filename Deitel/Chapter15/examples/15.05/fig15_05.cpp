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
    // create two char arrays, each with 80 elements
    const int SIZE = 80;
    char buffer1[SIZE];
    char buffer2[SIZE];

    // use cin to input characters into buffer1
    std::cout << "Enter a sentence:" << std::endl;
    std::cin >> buffer1;

    // display buffer1 contents
    std::cout << "\nThe string read with cin was:" << std::endl
              << buffer1 << std::endl
              << std::endl;

    // use cin.get to input character into buffer2
    std::cin.get(buffer2, SIZE);

    // display buffer2 contents
    std::cout << "The string read with cin.get was:" << std::endl
              << buffer2 << std::endl;

    return 0;
}
