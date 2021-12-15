#include <iostream>
#include "interoperable.h"

using namespace std;

class c
{
  public:
    float times(int i, float f) { cout << "multiply " << i << " with " << f << "\n"; return i * f; }
};

template <typename Value> 
class adder
{
  public:
    static Value eval(Value x, Value y) { return x + y; }
};

float ctimes(int i, float f) { c co; return co.times(i, f); }

int iadder(int x, int y) { return adder<int>::eval(x, y); }
float fadder(float x, float y) { return adder<float>::eval(x, y); }
double dadder(double x, double y) { return adder<double>::eval(x, y); }
 
