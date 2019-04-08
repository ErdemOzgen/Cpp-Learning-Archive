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

void staticArrayInit(void);
void automaticArrayInit(void);

const int arraySize = 3;

int main(int argc, const char *argv[]) {
    std::cout << "First call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    std::cout << "\n\nSecond call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    std::cout << std::endl;
    return 0;
}
// function to demonstrate a static local array
void staticArrayInit(void) {
    // initialises elements from 0 first time function is called
    static int array1[arraySize];

    std::cout << "\nValues on entering staticArrayInit:\n";

    // output contents of array1
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "array1[" << i << "] = " << array1[i] << " ";
    }

    std::cout << "\nValues on exiting staticArrayInit:\n";

    // modify and ouput contents of array1
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "array1[" << i << "] = " << (array1[i] += 5) << " ";
    }
}
// function to demonstrate an automatic local array
void automaticArrayInit(void) {
    // initialises elements each time function is called
    int array2[arraySize] = {1, 2, 3};

    std::cout << "\n\nValues on entering automaticArrayInit:\n";

    // output contents of array2
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "array2[" << i << "] = " << array2[i] << " ";
    }

    std::cout << "\nValues on exiting automaticArrayInit:\n";

    // modify and output contents of array2
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "array2[" << i << "] = " << (array2[i] += 5) << " ";
    }
}
