#include <iostream>
#include <tuple>
#include <string>
#include <typeinfo>
#include <chrono>

using namespace std;

template <typename Number>
struct name_number
{
    name_number(string name, Number num) : name(name), num(num) {}
    // name_number(string name, double num) : name(name), num(num) {}

    string name;
    Number num;
};

int main(int argc, char** argv) 
{
	// Didn't compile with Visual Studio 2017
   name_number horst("Horst", 3.7);

    return 0;
}
