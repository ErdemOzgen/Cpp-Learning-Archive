
#include "Stack.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    Stack<double> doubleStack(5);
    double doubleValue = 1.1f;

    std::cout << "Pushing elements onto doubleStack\n";

    // push 5 doubles onto doubleStack
    while (doubleStack.push(doubleValue)) {
        std::cout << doubleValue << ' ';
        doubleValue += 1.1;
    }

    std::cout << "\nStack is full. Cannot push " << doubleValue
              << "\n\nPopping elements from doubleStack\n";

    // pop elements from doubleStack
    while (doubleStack.pop(doubleValue)) std::cout << doubleValue << ' ';

    std::cout << "\nStack is empty, cannot pop\n";

    Stack<int> intStack;  // default size 10
    int intValue = 1;

    std::cout << "\nPushing elements onto intStack\n";

    // push 10 integers onto intStack
    while (intStack.push(intValue)) {
        std::cout << intValue++ << ' ';
    }

    std::cout << "\nStack is full. Cannot push " << intValue
              << "\n\nPopping elements from intStack\n";

    // pop elements from intStack
    while (intStack.pop(intValue)) std::cout << intValue << ' ';

    std::cout << "\nStack is empty. Cannot pop" << std::endl;

    return 0;
}
