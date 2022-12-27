#include <iostream>

#include "vector.h"


// if we need to use pointers for our classes, we have two solutions:

void resourceLeaks(long size) {
    std::cout << "resourceLeaks: size " << size << std::endl;
    
    Vector *v = new Vector(size);
    
    // potential leaks
    // in both conditions, the function returns without deallocating the vector
    // one solution is to add a `delete v` before the corresponding returns,
    // but this kind of responsability is too dangerous for the user
    // a “plain old pointer” or "naked pointer" should not be used to represent ownership.
    if (size == 0) {
        std::cout << "Vector is empty... memory leak\n";
        return;
    }
    else if (size < 5) {
        std::cout << "size < 5... memory leak\n";
        return;
    }
    
    delete v; // deallocate the vector
}


void noResourceLeaks(long size) {
    std::cout << "noResourceLeaks: size " << size << std::endl;
    
    std::unique_ptr<Vector> v{new Vector(size)}; // ugly, but effective
    
    if (size == 0) {
        std::cout << "Vector is empty... no more memory leak\n";
        return;
    }
    else if (size < 5) {
        std::cout << "size < 5... no more memory leak\n";
        return;
    }
    // no deletes here
}


int main() {
    resourceLeaks(10);
    std::cout << "\n";
    resourceLeaks(3);
    std::cout << "\n";
    noResourceLeaks(10);
    std::cout << "\n";
    noResourceLeaks(3);
    
    
    return 0;
}