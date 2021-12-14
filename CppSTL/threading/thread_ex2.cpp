#include <iostream>
#include <thread>

using namespace std;

class A {
public:
    A(int ID, int Iters)
        : id(ID), iterations(Iters) 
    {}
    // overloaded operator ()
    void operator() () {
        for(auto i=0; i<iterations; i++)
            cout << "Counter " << id << " has value: " << i << endl;
        cout << endl;
    }
    // Just a function to call from a thread
    void echo(int times) {
        for(auto i=0; i<times; i++)
            cout << "echoing ... " << i+1 << " ...\n";
    }
private:
    int id;
    int iterations;
};


int main()
{
    // Uniform initialization syntax
    thread th1{ A{1, 5} };
    // Standard syntax
    A a(2, 3);
    thread th2(a);
    // Temporary
    thread th3( A(3, 4) );

    // Just create a thread and call the echo() member function of class A
    A Obj(1, 5);
    thread th4( &A::echo, &Obj, 5); 

    // Join them
    th1.join();
    th2.join();
    th3.join();
    th4.join();

    return 0;
}