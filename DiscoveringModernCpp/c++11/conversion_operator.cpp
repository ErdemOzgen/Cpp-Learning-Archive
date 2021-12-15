#include <iostream>
#include "print_compiler.hpp"

using namespace std;

struct compressed_matrix;

struct dense_matrix
{
    dense_matrix() = default;
    explicit dense_matrix(const compressed_matrix&) { cout << "Constructor\n"; }

};

struct compressed_matrix
{
    operator dense_matrix() { cout << "Conversion\n"; return dense_matrix(); }

};

void f(const dense_matrix&) {}

int main () 
{
    print_compiler();

    compressed_matrix A;
    dense_matrix      B{A};           // Constructor
    f(dense_matrix(A));               // Constructor
    f(static_cast<dense_matrix>(A));  // Constructor
    f(A);                             // Conversion

    return 0;
}

