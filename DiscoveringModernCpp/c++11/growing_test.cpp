#include <iostream>
#include <exception>
#include <tuple>
#include <typeinfo>

using namespace std;

template <typename Fun>
void foreach_type(tuple<>, Fun) {}

template <typename First, typename ...Others, typename Fun>
void foreach_type(tuple<First, Others...>, Fun f)
{
    Fun::template eval<First>();
    foreach_type(tuple<Others...>{}, f);
}


template <typename ...Tuples>
using tuple_cat_type = decltype(tuple_cat(declval<Tuples>()...));

using small_set = tuple<int, float>;

using compact_set = tuple_cat_type<small_set, 
				   tuple<short, double> >;                               

struct identity_test
{
    template <typename T>
    static void eval()
    {
	T zero{0}, one{1}, nine{9};
	if (zero + nine != nine)
	    throw logic_error{"Addition wrong"};
	if (one * nine != nine)
	    throw logic_error{"Multiplication wrong"};
	cout << "Test passed for " << typeid(T).name() << endl;
    }
};


int main (int argc, char* argv[]) 
{
    foreach_type(compact_set{}, identity_test{});

    return 0;
}

