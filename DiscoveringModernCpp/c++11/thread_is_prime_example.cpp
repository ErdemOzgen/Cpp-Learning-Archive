#include <iostream>
#include <vector>
#include <thread>
#include <string>

using namespace std;

namespace dmc {

    bool is_prime(long i)
    {
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	long max_check= i; // sqrt(i) + 1 would be enough
	for (long j= 3; j < max_check; j+= 2)
	    if (i % j == 0)
		return false;
	return true;
    }
}


int main (int argc, char* argv[]) 
{
    using namespace dmc;

    cout << thread::hardware_concurrency() << " threads available.\n";
    
    int num_threads= 2;
    if (argc > 1)
	num_threads= stoi(argv[1]);

    vector<long>  vi;
    long first_prime= 982451653;
    for (long i= 0, v= first_prime; i < num_threads; ++i, v+= 2)
	vi.push_back(v);

    vector<char> results(num_threads);
 
    vector<thread>   threads;
    for (int i= 0; i < num_threads; ++i)
	//threads.push_back(std::thread( [&vi, &results, i](){ results[i]= is_prime(vi[i]); }  ));
	threads.emplace_back( [&vi, &results, i](){ results[i]= is_prime(vi[i]); } );

    cout << "Launched everything." << endl;

    for (int i= 0; i < num_threads; ++i) {
	threads[i].join();
	cout << vi[i] << " is " << (results[i] ? "" : "not ") << "a prime number.\n";
    }
 
    return 0;
}
 
