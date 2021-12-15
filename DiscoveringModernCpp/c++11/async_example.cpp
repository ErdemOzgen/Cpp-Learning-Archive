#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <string>

namespace dmc {

    struct trivial_nonprime {};

    bool is_prime(long i)
    {
	if (i % 10 == 5 && i != 5)
	    throw trivial_nonprime{};
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	// sqrt(i) would be enough to check
	for (long j= 3; j < i; j+= 2)
	    if (i % j == 0)
		return false;
	return true;
    }
}


int main (int argc, char* argv[]) 
{
    using namespace std;
    using namespace dmc;

    int num_threads= 2;
    if (argc > 1)
	num_threads= stoi(argv[1]);

    vector<long> vi;
    long first_prime= 982451653;
    // long first_prime= 15;
    for (long v= first_prime, i= 0; i < num_threads; ++i, v+= 2)
	vi.emplace_back(v);

    vector<future<bool>> vf;
    for (long v : vi)
	vf.emplace_back(async(is_prime, v));
    
    for (long i= 0; i < num_threads; ++i) 
	try {
	    // while (vf[i].wait_for(200ms) != future_status::ready) // in C++14
	    while (vf[i].wait_for(chrono::milliseconds(200)) != future_status::ready)
		cout << "Still waiting." << endl;
	    cout << vi[i] << (vf[i].get() ? " is " : " is not ") 
		 << "a prime number.\n";
	} catch (trivial_nonprime) {
	    cout << " is obviously not a prime number, moron.\n";
	}

    // better 200ms in C++14
    return 0;
}

