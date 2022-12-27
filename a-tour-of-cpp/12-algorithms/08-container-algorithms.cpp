#include <iostream>

// We can define our own simple range algorithms for our custom containers.
// For example, we can easily provide the shorthand to say just `sort(v)` instead of `sort(v.begin(), v.end())`
//
// Bjarne Stroustrup puts the container versions of `sort()` (and other algorithms) into their own namespace Estd (“extended std”)
// to avoid interfering with other programmers’ uses of namespace std and also to make it easier to replace this stopgap with Ranges.

namespace Estd {
    using namespace std;
    
    template<typename C>
    void sort(C& c) {
        sort(c.begin(), c.end());
    }
    
    template<typename C, typename Pred>
    void sort(C& c, Pred p) {
        sort(c.begin(), c.end(), p);
    }
    // ...
}


int main() {
    
    return 0;
}