#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::cerr;
using std::string;
using std::vector;
using std::list;


// We can generalize the function find_all()
//
// The typename is needed to inform the compiler that C ’s iterator is supposed to be a
// type and not a value of some type, say, the integer 7
//
// We can hide this implementation detail by introducing a type alias

template<typename T>
using Iterator = typename T::iterator; // T's iterator

template<typename C, typename V>
vector<Iterator<C>> find_all(C& c, V v) {
    vector<Iterator<C>> res;
    
    for (auto p = c.begin(); p != c.end(); ++p) {
        if (*p == v)
            res.push_back(p);
    }
    
    return res;
}


void test() {
    string m {"Mary had a little lamb"};
    for (auto p : find_all(m, 'a')) { // p is a string::iterator
        if (*p!='a')
            cerr << "string bug!\n";
    }
    
    list<double> ld {1.1, 2.2, 3.3, 1.1};
    for (auto p : find_all(ld, 1.1)) { // p is a list<double>::iterator
        if (*p != 1.1)
            cerr << "list bug!\n";
    }
    
    vector<string> vs { "red", "blue", "green", "green", "orange", "green" };
    for (auto p : find_all(vs, "red")) { // p is a vector<string>::iterator
        if (*p != "red")
            cerr << "vector bug!\n";
    }
    
    for (auto p : find_all(vs, "green"))
        *p = "vert";
}



int main() {
    test();
    
    return 0;
}

