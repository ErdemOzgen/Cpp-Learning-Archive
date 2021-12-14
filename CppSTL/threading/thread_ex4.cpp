#include <iostream>
#include <thread>
#include <vector>

#include <atomic>

using namespace std;

void echo(atomic<int>& num) {
    for(int i=0; i<100; i++)
    {
        ++num;
        this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}


int main() 
{
    int i=0;
    while(i<20)
    {
        atomic<int> counter(0);
        // Create a vector of threads instead of a simple array of threads | safer
        vector<thread> threads;
        // Call the echo function with the counter parameter by reference using ref()
        for(auto i=0; i<10; i++)
            threads.push_back(thread(echo, ref(counter)));
        // Join, if joinable()
        for(auto& th : threads)
            if(th.joinable())
                th.join();

        // Print-out the counter
        cout << "Counter = " << counter << endl;

        i++;
    }
    return 0;
}

/* OUTPUT   ||  Thread-Safe using atomic  || atomic variable 'counter' cannot be interrupted by every thread

It is loaded, incremented and stored back   ||  pitfall --> atomic introduces low performance, like it is not threaded at all!

Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000
Counter = 1000

*/