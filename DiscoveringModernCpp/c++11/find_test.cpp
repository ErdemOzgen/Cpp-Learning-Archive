#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "print_compiler.hpp"

using namespace std;

struct no_seven {};
struct one_seven {};

int main (int argc, char* argv[]) 
{
    print_compiler();
    vector<int> seq= {3, 4, 7, 9, 2, 5, 7, 8};
    auto it= find(begin(seq), end(seq), 7); // first 7
    if (it == end(seq)) 
	throw no_seven{};
    auto last= find(it+1, end(seq), 7); // second 7
    if (last == end(seq)) 
	throw one_seven{};
    for (; it != last+1; ++it)
	cout << *it << ' ';
    cout << '\n';

    return 0;
}

