#include <iostream>
#include <iterator>
#include <cassert>
#include <vector>
#include <list>
#include <forward_list>

#include "../c++11/print_compiler.hpp"

using namespace std;

template <typename Iterator, typename Distance>
inline void advance_aux(Iterator& i, Distance n, input_iterator_tag tag [[maybe_unused]])
{
    cout << "advance with input iterator.\n"; 
    assert(n >= 0);
    for (; n > 0; --n)
        ++i;
}

template <typename Iterator, typename Distance>
inline void advance_aux(Iterator& i, Distance n,
                        bidirectional_iterator_tag tag [[maybe_unused]])
{
    cout << "advance with bidirectional iterator.\n";
    if (n >= 0)
        for (; n > 0; --n) ++i; 
    else
        for (; n < 0; ++n) --i;
} 

template <typename Iterator, typename Distance>
inline void advance_aux(Iterator& i, Distance n,
                        random_access_iterator_tag tag [[maybe_unused]])
{
    cout << "advance with random_access iterator.\n"; 
    i+= n;
}

template <typename Iterator, typename Distance>
inline void advance(Iterator& i, Distance n)
{
    
    advance_aux(i, n, typename std::iterator_traits<Iterator>::iterator_category{});
}

template <typename C>
void third_entry(const C& c)
{
    auto it= begin(c);
    ::advance(it, 2);
    if (it == end(c))
	cout << "There are no 3 entries.\n";
    else
	cout << "The third entry is " << *it << '\n';
}


int main () 
{
    print_compiler();

    third_entry(vector<int>{3, 4, 5, 6});
    third_entry(list<int>{3, 4, 5, 6});
    third_entry(forward_list<int>{3, 4, 5, 6});
     
    return 0; 
}
 
 
