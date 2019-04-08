
#include <iostream>

// function template printArray definition
template <typename T>
void printArray(const T *const array, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
int main(int argc, const char *argv[]) {
    const int aCount = 5;
    const int bCount = 7;
    const int cCount = 6;

    int a[aCount] = {1, 2, 3, 4, 5};
    double b[bCount] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    char c[cCount] = "HELLO";

    std::cout << "Array a contains:" << std::endl;

    // call integer function-template specialization
    printArray(a, aCount);

    std::cout << "Array b contains" << std::endl;

    // call double function-template specialization
    printArray(b, bCount);

    std::cout << "Array c contains:" << std::endl;

    // call character function-template specialisation
    printArray(c, cCount);

    return 0;
}
