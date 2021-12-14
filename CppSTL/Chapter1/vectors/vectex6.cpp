#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

template<class T>
class MyVector{
  template<class U>
    friend std::ostream& operator<<( std::ostream& , const MyVector<U>& );
public:
  explicit MyVector(T N) {
    vect.reserve(2*N);    // Reserve capacity 2N for vect vector  
    for(T i=0;i<N;i++)
      vect.push_back(i+1);
  }
  ~MyVector(){
    vect.clear();
  }
  void removeElem(const T& val){
    typename vector<T>::iterator it;
    it = find(vect.begin(), vect.end(), val);
    it = vect.erase(it);
  }
  void delEven() {
    typename vector<T>::iterator it=vect.begin();
    while(it!=vect.end())
      if(*it%2==0)
        it = vect.erase(it);
      else
        ++it;
  }
  void print() {
    for_each( vect.begin(), vect.end(), [](const auto& elem) { std::cout<<elem<<" ";} );
  }
private:
  vector<T> vect;
};

template<class U>
std::ostream& operator<<(std::ostream& out, const MyVector<U>& v) {
  for(auto& val : v.vect)
    out << val << " ";
  out << "\n";
  return out;
}


int main() {

  MyVector<int> Obj(10);
  std::cout << Obj;
  Obj.removeElem(5);
  std::cout << Obj;
  Obj.delEven();
  Obj.print();
  std::cout << "\n";

  return 0;
}
