#include <iostream>

#include "vector.h"

using std::cout;
using std::endl;


template <typename T>
void rangeForConstObjects(const Vector<T> &v) {
    cout << "rangeForConstObjects()" << endl;
    cout << "size = " << v.size() << endl;
    
    // Range-for looping... it only works because Vector has implemented the functions begin() and end().
    // Since v is already const, the range-for looping calls its begin() and end() for const objects.
    // These functions return const T*.
    // Therefore, the const below is unnecessary (optional).
    // But, for the sake of clarity, we left the const.
    //
    // This range-for calls: "const T* begin() const" and "const T* end() const" from Vector
    for (const auto& x : v) {
        cout << x << endl;
         // x = 10; // it is not allowed... x is const (this is true due to const versions of begin() and end() from Vector
    }
    cout << "\n";
}



int main() {
    cout << "### vi initialization\n";
    Vector<int> vi{1, 2, 3};
    vi.print();
    cout << endl;
    rangeForConstObjects(vi);
    cout << endl;
    vi.print();
    cout << "--------------\n\n";
    
    // This range-for calls from Vector: "T* begin()" that calls "const T* begin() const"; and
    // "T* end()" that calls "const T* end() const" from Vector
    cout << "rangeFor Non-Const Objects but Const Elements in For\n";
    for (const auto& x : vi) {
        cout << x << endl;
        // x = 10; // it is not allowed... x is const (this is true due to const versions of begin() and end() from Vector
    }
    cout << "\n";
    cout << "--------------\n\n";
    
    cout << "rangeFor Non-Const Objects and Elements in For\n";
    for (auto& x : vi) {
         x = 10;
    }
    vi.print();
    cout << "\n";
    cout << "--------------\n\n";

    
    return 0;
}