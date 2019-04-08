
#include <iomanip>
#include <iostream>

template <typename T>
void printArray(T* const, const int);
template <typename T>
void selectionSort(T* const, const int);
template <typename T>
void swap(T* const, T* const);

int main(int argc, const char* argv[]) {
    const int arraySize = 10;

    int intArr[arraySize] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    double doubleArr[arraySize] = {1.1, 2.5, 0.5, 1.0, 2.2,
                                   6.8, 3.7, 2.6, 2.5, 1.6};

    std::cout << "intArr:\noriginal order:\n";
    printArray(intArr, arraySize);
    std::cout << "\nsorted:\n";
    selectionSort(intArr, arraySize);
    printArray(intArr, arraySize);

    std::cout << "\n\ndoubleArr:\noriginal order:\n";
    printArray(doubleArr, arraySize);
    std::cout << "\nsorted:\n";
    selectionSort(doubleArr, arraySize);
    printArray(doubleArr, arraySize);

    std::cout << std::endl;
    return 0;
}
// print array
template <typename T>
void printArray(T* const a, const unsigned int size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << a[i] << ' ';
    }
}
// function to sort an array
template <typename T>
void selectionSort(T* const array, const unsigned int size) {
    for (std::size_t i = 0; i < size - 1; ++i) {
        int smallest = i;  // first index of remaining array

        // loop to find index of smallest element
        for (int index = i + 1; index < size; ++index) {
            if (array[index] < array[smallest]) { smallest = index; }
        }

        swap(&array[i], &array[smallest]);
    }
}
// swap values at memory locations to which element1Ptr and element2Ptr point
template <typename T>
void swap(T* const element1Ptr, T* const element2Ptr) {
    T hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}
