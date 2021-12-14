#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class A {
public:
    A(int ID, int Iters)
        : id(ID), iterations(Iters) 
    {}
    // overloaded operator ()
    void operator() () {
        for(auto i=0; i<iterations; i++)
        {
            // Perform a timed-lock on the mutex before writing to cout
            // Change this to 1 millisecond and run to watch threads get mixed again!
            unique_lock<timed_mutex> lock(t_mutex, chrono::milliseconds(300));   // check with 1 here
            if(lock)
                cout << "Counter " << id << " has value: " << i << endl;
        }
        cout << endl;
    }
private:
    int id;
    int iterations;
    // static, since all instances are to use the same mutex instance
    static timed_mutex t_mutex;
};

timed_mutex A::t_mutex;


int main()
{
    // Uniform initialization syntax
    thread th1{ A{1, 5} };
    // Standard syntax
    A a(2, 3);
    thread th2(a);
    // Temporary
    thread th3( A(3, 4) );

    // Join them
    th1.join();
    th2.join();
    th3.join();

    return 0;
}