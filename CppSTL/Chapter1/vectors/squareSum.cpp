#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Exercise1 {
private:
  vector<int> vect{};
  int sum_;
public:
  Exercise1() {}
  ~Exercise1() {}
  void setVector(const vector<int>& v) {
    vect.assign( v.begin(), v.end() );
  }
  void squareSum() {
    vector<int>::iterator itr = vect.begin();
    sum_ = 0;
    while( itr != vect.end() ) {
      sum_ += pow(*itr, 2);
      itr++;
    }
    cout << "Square Sum = " << getSum() << endl;
  }
  int getSum() const { return sum_; }
};

int main() {
  vector<int> array{0, 3, 4, 5};
  Exercise1 Obj;
  // Copy array to Object's vect vector
  Obj.setVector(array);
  Obj.squareSum();

  return 0;
}
