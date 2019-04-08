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

void printArray(const int[][3]);

const int rows = 2;
const int cols = 3;

int main(int argc, const char *argv[]) {
    int array1[rows][cols] = {{1, 2, 3}, {4, 5, 6}};
    int array2[rows][cols] = {1, 2, 3, 4, 5};
    int array3[rows][cols] = {{1, 2}, {4}};

    std::cout << "Values in array1 by row are:" << std::endl;
    printArray(array1);

    std::cout << "Values in array2 by row are:" << std::endl;
    printArray(array2);

    std::cout << "Values in array3 by row are:" << std::endl;
    printArray(array3);

    return 0;
}
// output array with two rows and three columns
void printArray(const int a[][cols]) {
    // loop through array's rows
    for (int i = 0; i < rows; ++i) {
        // loop through array's cols
        for (int j = 0; j < cols; ++j) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
