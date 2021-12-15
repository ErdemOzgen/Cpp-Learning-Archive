#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

atomic<int> cnt(0);

void f()
{
    for (int i= 0; i < 1000000; ++i)
	++cnt;
    	// cnt.fetch_add(1, memory_order_seq_cst);
        // cnt.fetch_add(1, memory_order_acq_rel);
	// cnt.fetch_add(1, memory_order_relaxed);
}

int main(int argc, char** argv) 
{
    vector<thread> v;
    auto t1= high_resolution_clock::now();
    for (int i= 0; i < 10; ++i)
	v.emplace_back(thread(f));

    for (auto& t : v)
	t.join();
    auto t2= high_resolution_clock::now();
    cout << "cnt = " << cnt << endl;
    std::cout << "microseconds: " << duration_cast<microseconds>(t2-t1).count() << endl;

    return 0;
}
