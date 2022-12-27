#include <iostream>
#include <vector>

using std::cout;
using std::vector;



void printIntVector(const vector<int>& v) {
    for (auto x : v)
        cout << " " << x;
    cout << "\n";
}


int main() {
    vector<int> vi = {3, 5, 1, 4, 2};
    cout << "int vector       = ";
    printIntVector(vi);
    
    cout << "ascending order  = ";
    sort(vi.begin(), vi.end()); // in-place sorting
    printIntVector(vi);
    
    cout << "descending order = ";
    sort(vi.begin(), vi.end(), std::greater<>()); // in-place sorting
    printIntVector(vi);
    
    
    return 0;
}