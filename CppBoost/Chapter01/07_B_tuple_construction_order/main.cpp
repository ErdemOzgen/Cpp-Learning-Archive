#include <boost/tuple/tuple.hpp>
#include <iostream>

template <int I>
struct printer {
    printer() { std::cout << I; }
};

template <int I>
class printer2 {
    public:
    printer2() { std::cout << I; }
};

int main() {
    // Outputs 012
    boost::tuple<printer<0>, printer<1>, printer<2> > t;
    boost::tuple<printer2<12>, printer2<123>, printer2<232> > t2;
    (void)t;
}
