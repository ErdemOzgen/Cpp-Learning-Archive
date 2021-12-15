#include <iostream>
#include <vector>
#include <functional>

#define USE_STD_ANY

# ifdef USE_STD_ANY
#   include <any>
    using any_type= std::any;
    using namespace std;
# else
#   include <boost/any.hpp>
    using any_type= boost::any;
    using namespace boost;
# endif

template<typename T>
T copy(const T& to_copy)
{
    return T{ to_copy };
} 

int main (int argc, char* argv[]) 
{ 
    std::vector<any_type> v; 
    v.push_back(3);
    v.push_back(3.3); 
    std::cout << "size of v is " << v.size() << '\n';

    std::vector<any_type> w= copy(v);
    // size = 1 for g++ and clang++ <= 3.6, size = 2 for clang++ >= 3.7
    std::cout << "size of w is " << w.size() << '\n';

    try {
	if (size(w) == 2) {
	    std::cout << "w[0] = " << any_cast<int>(w[0]) << '\n';
	    std::cout << "w[1] = " << any_cast<double>(w[1]) << '\n';
	}
    } catch(std::exception& e) {
	std::cout << "Exception: " << e.what() << '\n';
    }
     
    return 0;
}

 
