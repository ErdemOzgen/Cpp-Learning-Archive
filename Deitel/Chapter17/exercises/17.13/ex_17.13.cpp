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
#include <fstream>
#include <iomanip>
#include <iostream>

int main(int argc, const char* argv[]) {
    std::fstream inOutFile("data-size.dat", std::ios::out);

    inOutFile << std::setw(20) << std::left << "char" << std::right
              << sizeof(char) << std::endl
              << std::setw(20) << std::left << "unsigned char" << std::right
              << sizeof(unsigned char) << std::endl
              << std::setw(20) << std::left << "short int" << sizeof(short int)
              << std::endl
              << std::setw(20) << std::left << "unsigned short int"
              << sizeof(unsigned short int) << std::endl
              << std::setw(20) << std::left << "int" << sizeof(int) << std::endl
              << std::setw(20) << std::left << "unsigned int"
              << sizeof(unsigned int) << std::endl
              << std::setw(20) << std::left << "long int" << sizeof(long int)
              << std::endl
              << std::setw(20) << std::left << "unsigned long int"
              << sizeof(unsigned long int) << std::endl
              << std::setw(20) << std::left << "float" << sizeof(float)
              << std::endl
              << std::setw(20) << std::left << "double" << sizeof(double)
              << std::endl
              << std::setw(20) << std::left << "long double"
              << sizeof(long double) << std::endl;

    return 0;
}
