#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "print_compiler.hpp"

using namespace std;

int main (int argc, char* argv[]) 
{
    std::list<int> seq= {3, 4, 7, 9, 2, 5, 7, 8};
    auto it= find(begin(seq), end(seq), 7), it2= it; // first 7
    ++it2;
    auto past= find(it2, end(seq), 7);                 // second 7
    ++past;
    for (; it != past; ++it)
	std::cout << *it << ' ';
    std::cout << '\n';

    return 0;
}

