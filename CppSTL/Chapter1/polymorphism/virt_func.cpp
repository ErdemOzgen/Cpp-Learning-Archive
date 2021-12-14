#include <iostream>

using namespace std;

class Vehicle {
public:
    virtual void start() {
        cout << "Vehicle: Starting ...\n";
    }
    virtual ~Vehicle() {
        cout << "Vehicle: Destructor ...\n";
    } 
};


class Bicycle: public Vehicle {
public:
    void start() {
        cout << "Bicycle: Starting ...\n";
    }
    ~Bicycle() {
        cout << "Bicycle: Destructor ...\n";
    }
};


class Car: public Vehicle {};

int main() 
{
    Vehicle *vh = new Bicycle();
    // Vehicle's start() function is virtual, so when vh pointer
    // start()'s then the derived classe's start() function will
    // be called, i.e. bicycle's start() function
    // 
    // If Base classe's start function was not virtual, then
    // the vehicle's start() function would had been called instead
    //
    vh->start();    

    // Something analogous is ahappening with the virtual destructor
    // If Base classe's destructor was not virtual then only Vehicle's 
    // destructor would had been called
    //
    // Now that Vehicle's destructor is virtual, both base and derived classe's
    // destructors are called just before the object's end of life 

    delete vh;

    return 0;
}