#include <iostream>

#include "Array.hpp"

int main(int argc, const char *argv[]) {
    Array<int> integers(12);
    Array<double> doubles(50);
    Array<double> doublesTwo;

    std::cout << "intergers.size() = " << integers.getSize();
    std::cout << "\ndoubles.size() = " << doubles.getSize();

    doublesTwo = doubles;

    std::cout << "\ndoublesTwo.size() = " << doublesTwo.getSize() << std::endl;

    std::cout << "doubles == doublesTwo : "
              << ((doubles == doublesTwo) ? "true" : "false") << std::endl;

    doubles[5] = 100.5;
    std::cout << "doubles[5] = " << doubles[5] << std::endl;

    doublesTwo[5] = doubles[5];
    std::cout << "doublesTwo[5] = " << doublesTwo[5] << std::endl;

    std::cout << "inegers before input: \n" << integers;

    std::cout << "\nInput " << integers.getSize() << " integer values:\n";
    std::cin >> integers;

    std::cout << "\nintegers after input:\n" << integers;

    return 0;
}
