#include <iostream>
#include <thread>

using std::cout;
using std::thread;

class A {
public:
    A(int v) : val(v) {};
    explicit A() : val(10) {};
    ~A() { cout << "Destroying A Object...\n"; }

    void func() {
        cout << "func function called ...\n";
    }

    thread func_thread() {
        cout << "\n\nCalling func from a thread ...\n";
        return thread( [this] { this->func(); } );
    }    

private:
    int val;
};


void test(std::string msg) {
    cout << "test called ... " << msg << std::endl;
}

thread test_threaded() {
    cout << "Creating the thread: " << std::endl;
    thread t1(test, " OOK !!!");
    return t1;
}

int main() 
{
    /* Scenario I :: OK
    A *a_ptr = new A();
    cout << "Creating a thread to call func member function ...\n";
    thread th( &A::func, a_ptr );
    th.join();

    delete a_ptr;
    */

    /* Scenario II: OK */
    thread my_thread = test_threaded();
    my_thread.join();

    return 0;
}