#include <iostream>
#include <vector>
#include <future>
#include <chrono>
#include <string>

using namespace std;

namespace le {

    struct trivially_nonprime {};

    bool is_prime(long i)
    {
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	if (i % 10 == 5 && i != 5)
	    throw trivially_nonprime{};
	long max_check= i;
	for (long j= 3; j < max_check; j+= 2)
	    if (i % j == 0)
		return false;
	return true;
    }

}


int main (int argc, char* argv[]) 
{
    using namespace le;
 
    int num_threads= 2;
    if (argc > 1)
	num_threads= stoi(argv[1]);

    vector<long>  vi;
    long first_prime= 982451653;
    for (long i= 0, v= first_prime; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

vector<future<bool>> vf;
for (long v : vi)
    vf.emplace_back(async(is_prime, v));
//vf.emplace_back(async(std::launch::async, is_prime, v));

    cout << "Everything launched." << endl;

    // for (long i= 0; i < num_threads; ++i) {
    // 	bool it_is;
    // 	while (vf[i].wait_for(chrono::milliseconds(200)) != future_status::ready)
    // 	    cout << "Still waiting.\n";
    // 	try {
    // 	    it_is= vf[i].get();
    // 	} catch(trivially_nonprime) {
    // 	    it_is= false;
    // 	}
    // 	cout << vi[i] << " is " << (it_is ? "" : "not ") << "a prime number.\n";
    // }
 
    return 0;
}
 
