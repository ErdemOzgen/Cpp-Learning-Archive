#include <iostream>

using namespace std;

class Vehicle {
public:
    void start() {
        cout << "Vehicle: Starting ...\n";
    }
};


class Bicycle: public Vehicle {
public:
    void start() {
        cout << "Bicycle: Starting ...\n";
    }
};

class Car: public Vehicle {};

int main() {

    Vehicle vh;
    vh.start();

    Bicycle bc;
    bc.start();

    Car car;
    car.start();

    return 0;
}

/* Output Sample ::
    $ ./main.exe
    Vehicle: Starting ...
    Bicycle: Starting ...
    Vehicle: Starting ...
*/
