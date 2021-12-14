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
            // Perform a lock on the mutex before writing to cout
            lock_guard<mutex> lock(_mutex);
            cout << "Counter " << id << " has value: " << i << endl;
        }
        cout << endl;
    }
private:
    int id;
    int iterations;
    // static, since all instances are to use the same mutex instance
    static mutex _mutex;
};

mutex A::_mutex;


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