/*
 * Example I: Creating threads using function pointers
 */
#include <iostream>
#include <thread>
#include <typeinfo>

using namespace std;

auto print(string name) -> decltype(auto) {
    cout << "Hello " << name << endl;
    // Uncomment to see the output please ::
    //exit(1);
}

int main()
{
    /* g++ thread1.cpp -lpthread -o thread1 */
    //g++ -std=c++14 thread1.cpp -lpthread -o thread1
    const char* name = "Dimos";
    thread mythread(print, name);
    for(auto c=0; c<5; c++)
        cout << "Threading ... " << endl;
    mythread.join();
    cout << "Main is conituing ... \n";

    return 0;
}