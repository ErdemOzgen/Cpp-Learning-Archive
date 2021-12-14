#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
struct Print {
  void operator()(T value) const {
    cout << value << endl;
  }
};

template<typename T>
class Vector {
private:
  vector<T> myVector;
  Print<T> PrintObj;
public:
  vector<T> getVector() const { return myVector; }
  Vector(const vector<T> &vect) {
    myVector.assign(vect.begin(), vect.end());
  }
  ~Vector() {
    while(!myVector.empty()){
      myVector.pop_back();
    }
  }
  void print() {
    for_each(myVector.begin(), myVector.end(), PrintObj);
  }
};


int main() {
  vector<double> numbers{10.11, 20.22, 30.33};
  Vector<double> diman(numbers);
  diman.print();

  return 0;
}
