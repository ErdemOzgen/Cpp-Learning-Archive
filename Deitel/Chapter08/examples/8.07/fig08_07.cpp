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

void cubeByReference(int *);
void cubeByReference2(int &num);
int main(int argc, const char *argv[]) {
    int number = 5;

    std::cout << "The original value of number is " << number;

   // cubeByReference(&number);
    cubeByReference2(number);

    std::cout << "\nThe new value of number is " << number << std::endl;
    return 0;
}
// calculate the cube of *nPtr; modifies variable number in main
void cubeByReference(int *nPtr) { *nPtr = *nPtr * *nPtr * *nPtr; }
void cubeByReference2(int &num){num=num*num*num;}