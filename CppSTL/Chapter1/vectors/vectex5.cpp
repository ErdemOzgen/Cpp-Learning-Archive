#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

template<class T>
class MyVector {
public:
  /* Make this constructor the default one */
  explicit MyVector() {
    for(size_t i=0;i<5;i++)
      vect.push_back(i+1);
  }
  MyVector(const vector<T>& vect_) {
    vect.assign(vect_.begin(), vect_.end());
  }
  ~MyVector() {}
  void pushElem(T val, int choice) {
    /* choice = 0 | 1 for front | back */
      switch(choice)
      {
        case 0:
          //vect.at(0) = val;              /* wrong | it replaces first elem of vect vector */
          vect.insert(vect.begin(), val);
          break;
        case 1:
          vect.push_back(val);
          break;
        default:
          int newChoice;
          std::cout << "Please enter 0 | 1 --> PUSH_FRONT | PUSH_BACK:\n";
          std::cin >> newChoice;
          pushElem(val, newChoice);   // replace while with recursion 
          break;
        }
  }
  /* PRINT MyVector's vect */
  void print() const {
    for(auto const& v : vect)
      std::cout << v << " ";
    std::cout << "\n";
  }
private:
  vector<T> vect{};
};

int main() {

  MyVector<int> v1;
  v1.print();
  v1.pushElem(10,2);
  v1.print();

  return 0;
}
