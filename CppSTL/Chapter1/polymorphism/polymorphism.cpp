#include <iostream>

using namespace std;

// This class cannot be instantiated
// This is the Abstract class that has to be implemented by others --> interface
//
class Vehicle {
public:
    // 2 pure virtual functions
    virtual void start() = 0;
    virtual ~Vehicle() {
        cout << "Vehicle: Destructor ..\n";
    };
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


class Car: public Vehicle {
public:
    void start() {
        cout << "Car: Starting ...\n";
    }
    virtual ~Car() {
        cout << "Car: Destructor ...\n";
    }
};


int main()
{
    Vehicle *car = new Car();
    car->start();
    delete car;

    cout << endl;

    Vehicle *bike = new Bicycle();
    bike->start();
    delete bike;

    return 0;
}

/* Output Sample ::
    $ ./main.exe
    Car: Starting ...
    Car: Destructor ...
    Vehicle: Destructor ..

    Bicycle: Starting ...
    Bicycle: Destructor ...
    Vehicle: Destructor ..
*/
