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
#include <random>
#include <vector>

std::random_device rd;
std::mt19937 gen(rd());

int getRandomNumber(const int&, const int&);

int main(int argc, const char *argv[]) {
    // offsets            v   set 1   v   v   set 2   v   v    set 3     v
    std::vector<int> set {2, 4, 6, 8, 10, 2, 5, 7, 9, 11, 6, 10, 14, 18, 22};

    std::cout << "Random number from each of the following sets: " << std::endl;
    std::cout << "\n2 4 6 8 10: " << set[getRandomNumber(0, 4)];
    std::cout << "\n2 5 7 9 11: " << set[getRandomNumber(5, 9)];
    std::cout << "\n6 10 14 18 22: " << set[getRandomNumber(10, set.size() - 1)] << std::endl;

    return 0;
}

/**
 * Creates a random distribution and returns a value in the range min max.
 * @param int
 * @param int
 * @return int
 */
int getRandomNumber(const int& min, const int& max) {
    return std::uniform_int_distribution<int>{min, max}(gen);
}  // end method getRandomNumber
