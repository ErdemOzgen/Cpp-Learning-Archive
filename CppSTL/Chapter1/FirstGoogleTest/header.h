#ifndef HEADER_H
#define HEADER_H

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
    int sum = 0;
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
    int get_fibo_nums(int idx) {
      return fibo_nums[idx];
    }
};

int fact(int num) {
	if(num<=0) { return 0; }
	int f=1;
	for(int i=1; i<num+1; i++)
		f*=i;
	return f;
}
#endif /* header.h */
