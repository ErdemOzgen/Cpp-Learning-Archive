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

void addToArray(int[], int);

const int limit = 20;

int main(int argc, const char *argv[]) {
    int n[limit] = {};
    int value;

    for (int i = 0; i < limit; ++i) {
        std::cout << "(" << i + 1 << "/20) Enter value between 10 and 100: ";
        std::cin >> value;

        if (value >= 10 && value <= 100) {
            addToArray(n, value);
        } else {
            i--;
        }
    }

    for (int i = 0; i < limit; ++i) {
        if (n[i] != 0) { std::cout << n[i] << std::endl; }
    }
    return 0;
}
// adds v to array if unique
void addToArray(int arr[], int value) {
    static int size = 0;

    bool duplicate = false;

    // no duplicates already in list so only need to compare to v not each other
    for (int i = 0; i <= size; ++i) {
        if (arr[i] == value) {
            duplicate = true;
            break;
        }
    }

    // no duplicate - add unique value and increase size counter
    if (!duplicate) {
        arr[size] = value;
        ++size;
    }
}
