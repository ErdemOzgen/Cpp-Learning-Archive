#include <iostream>

// function template printArray definition
template <typename T>
void printArray(const T *const array, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
// overloaded printArray
template <typename T>
int printArray(const T *const array, int count, int lowSubscript,
               int highSubscript) {
    if (lowSubscript < 0 || highSubscript >= count ||
            lowSubscript > highSubscript) {
        return 0;
    }

    int total = 0;

    for (int i = lowSubscript; i <= highSubscript; ++i, ++total) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return total;
}

int main(int argc, const char *argv[]) {
    const int aCount = 5;
    const int bCount = 7;
    const int cCount = 6;

    int a[aCount] = {1, 2, 3, 4, 5};
    double b[bCount] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    char c[cCount] = "HELLO";

    printArray(a, aCount);
    int count = printArray(a, aCount, 0, 5);
    std::cout << "elements printed: " << count << "\n\n";

    printArray(b, bCount);
    count = printArray(b, bCount, 2, 6);
    std::cout << "elements printed: " << count << "\n\n";

    printArray(c, cCount);
    count = printArray(c, cCount, 0, 4);
    std::cout << "elements printed: " << count << std::endl;

    return 0;
}
