#include <iostream>
#include <vector>

using namespace std;

class FIBO {
private:
  vector<int> fibo_nums;
  int limit;
public:
  FIBO(int limit_) : limit(limit_) {}
  ~FIBO() {}
  void find_fibo() {
    /* ------------- */
    for(int i=0; i<limit; i++)
      if( i==0 || i==1 )
        fibo_nums.push_back(i);
      else
        fibo_nums.push_back( fibo_nums[i-1] + fibo_nums[i-2] );
    }
    void print() {
      vector<int>::iterator itr = fibo_nums.begin();
      while(itr!=fibo_nums.end()) {
        cout << *itr << " ";
        itr++;
      }
      cout << "\n";
    }
  };


main() {

  FIBO Obj(21);
  Obj.find_fibo();
  Obj.print();

  return 0;
}
