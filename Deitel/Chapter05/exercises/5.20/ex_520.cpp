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
#include <math.h>
#include <iostream>
#include <algorithm>

bool isRightTriangle(int, int, int);

int main(int argc, const char *argv[]) {
    std::cout << "All Pythagorean Triples up to sides of 500" << std::endl;

    // inner loops start at 1+ previous loop to avoid duplication
    for (int i = 1; i <= 500; i++) {
        for (int j = i + 1; j <= 500; j++) {
            for (int k = j + 1; k <= 500; k++) {
                if (isRightTriangle(i, j, k)) {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }

    return 0;
}
bool isRightTriangle(int a, int b, int c) {
    // get hypotenuse (always the longest side)
    int hypotenuse = std::max(a, std::max(b, c));

    if (hypotenuse == a) {
        return pow(b, 2) + pow(c, 2) == pow(hypotenuse, 2);
    } else if (hypotenuse == b) {
        return pow(a, 2) + pow(c, 2) == pow(hypotenuse, 2);
    } else {
        return pow(a, 2) + pow(b, 2) == pow(hypotenuse, 2);
    }
}
