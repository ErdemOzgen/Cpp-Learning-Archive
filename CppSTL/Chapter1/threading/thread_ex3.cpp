#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void echo(int& num) {
    for(int i=0; i<100; i++)
    {
        ++num;
        this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}


int main() 
{
    // Print all this 20 times to watch that the counter is most-likely different each time, since a few threads 
    // are faster completed than others
    int i=0;
    while(i<20)
    {
        int counter=0;
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

/* SAMPLE OUTPUT 

Counter = 925
Counter = 964
Counter = 920
Counter = 933
Counter = 926
Counter = 912
Counter = 899
Counter = 942
Counter = 916
Counter = 964
Counter = 939
Counter = 930
Counter = 929
Counter = 969
Counter = 910
Counter = 933
Counter = 913
Counter = 937
Counter = 929
Counter = 941

*/