#include <iostream>
#include <fstream>
#include "../c++11/print_compiler.hpp"

using namespace std;

// int read_matrix_file(const char* fname, int& i) __attribute__((warn_unused_result));

[[nodiscard]] int read_matrix_file(const char* fname, int& i) 
{
    fstream f(fname); 
    if (!f.is_open())
        return 1;
    f >> i;
    return 0;
} 


int main (int argc, char* argv[]) 
{
    print_compiler();

    int i= 7;
    // Without conversion warning: ignoring return value of function declared with 'nodiscard'
    (void) read_matrix_file("nonexisting.file", i); 

    if (i == 7)
	cout << "i is still 7.\n";
 
    return 0; 
}
 
 
