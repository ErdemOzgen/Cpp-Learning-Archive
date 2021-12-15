// Example program for Discovering Modern C++
//
// File: concept_dispatching.cpp
// Date: 2020-02-24

#include <iostream>
#include <iterator>
#include <list>
#include <forward_list>
#include <vector>

using namespace std;

namespace dmc {
    
    
template <typename Iter>
void advance(Iter& it, unsigned n) 
    requires input_or_output_iterator<Iter>
{ 
    cout << "InputIterator or OutputIterator\n"; 
    while (n-- > 0)
        ++it;
}

template <typename Iter>
void advance(Iter& it, int n)
    requires bidirectional_iterator<Iter>
{ 
    cout << "BidirectionalIterator\n"; 
    if (n >= 0) {
        while (n-- > 0)
            ++it;
    } else {
        while (n++ < 0)
            --it;
    }    
}

#if 0
template <typename Iter>
void advance(Iter& it, int n)
    requires random_access_iterator<Iter>
{ 
    cout << "RandomAccessIterator\n"; 
    it+= n;
}


template <bidirectional_iterator Iter>
void advance(Iter& it, int n)
{ 
    cout << "BidirectionalIterator\n"; 
    if (n >= 0) {
        while (n-- > 0)
            ++it;
    } else {
        while (n++ < 0)
            --it;
    }    
}

template <random_access_iterator Iter>
void advance(Iter& it, int n)
{ 
    cout << "RandomAccessIterator\n"; 
    it+= n;
}
#endif

void advance(random_access_iterator auto& it, int n)
{ 
    cout << "RandomAccessIterator\n"; 
    it+= n;
}
    

} // namespace dmc

int main()
{
    vector<int> v{4, 3, 2};
    list<int>   l{8, 2, 8};
    forward_list f{9, 3, 4};
    
    auto bv= begin(v);
    auto bl= begin(l);
    auto bf= begin(f);
    
    dmc::advance(bv, 2);
    dmc::advance(bl, 2);
    dmc::advance(bf, 2);

    return 0;
}
