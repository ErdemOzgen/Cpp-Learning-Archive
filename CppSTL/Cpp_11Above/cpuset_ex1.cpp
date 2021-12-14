// Use this class to call a function or two
#include "header_one.h"
//https://www.geeksforgeeks.org/multithreading-in-cpp/
#include <vector>
#include <sched.h>      // All MACROs regarding cpu_set_t exist in this header 
// man cpu_set ( Linux terminal )
// The  cpu_set_t  data  structure  represents  a set of CPUs.  
// CPU sets are used by sched_setaffinity(2) and similar interfaces.


using namespace std;

int main()
{
    ThreadingClass one;

    // Create a threads vector
    vector<thread> threads_vector(10);
    for(int i=1; i<11; i++)
    {
        threads_vector[i-1] = thread( &ThreadingClass::fact, &one, i );
        // Without a sleep for 0.2 secs things/threads are mixed a bit ! | Uncomment n' check it out | mutex needed
        this_thread::sleep_for(std::chrono::milliseconds(200));
        threads_vector.push_back(move(threads_vector[i-1]));
    }

    // The Core ID : 0-3 (4-core PC)
    // Check cores from Linux terminal
    // cat /proc/cpuinfo | grep 'core id'
    const int core_id = 2;

    // Create a cpuset
    cpu_set_t my_cpu_set;
    // Clears set, so that it contains no CPUs. (man page)
    // No CPUs selected
    CPU_ZERO(&my_cpu_set);
    // Add CPU cpu to set |  set the bit that represents core '2'
    CPU_SET(core_id, &my_cpu_set);
    // Run this process on Core '2'
    if( sched_setaffinity(0, sizeof(cpu_set_t), &my_cpu_set) == -1 ) // returns '0' upon success
        perror("sched_setaffinity error ..\n"); 

    cout << "Running on " << sched_getcpu() + 1 << "rd core ...\n";

    // Join ( if joinable )
    for(auto& thread : threads_vector)
        if(thread.joinable())
            thread.join();

    return 0;
}

/* OUTPUT SAMPLE ::

From Thread ID : 139834404116224
1! = 1
From Thread ID : 139834395723520
2! = 2
From Thread ID : 139834387330816
3! = 6
From Thread ID : 139834378938112
4! = 24
From Thread ID : 139834370545408
5! = 120
From Thread ID : 139834362152704
6! = 720
From Thread ID : 139834353760000
7! = 5040
From Thread ID : 139834270152448
8! = 40320
From Thread ID : 139834261759744
9! = 362880
From Thread ID : 139834253367040
10! = 3628800
Running on 3rd core ...

*/