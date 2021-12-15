#include <iostream>
#include <vector>

#if __has_include(<execution>)
    #define PARSTL 2
    #include <execution>
    #include <algorithm>
#elif __has_include(<experimental/execution>)
    #define PARSTL 1
    #include <experimental/execution>
    #include <experimental/algorithm>
#else
   #include <algorithm>
#endif


using namespace std;

int main (int argc, char* argv[]) 
{
    vector<int> v{1, 3, 9, 2, 4, 7, 8, 5};
    
    sort(begin(v), end(v));

#ifdef PARSTL
    sort(std::execution::seq, begin(v), end(v));

#else
    std::cerr << "Parallel STL not supported yet by this compiler.\n";
#endif
}

