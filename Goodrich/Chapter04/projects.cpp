#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

typedef vector< pair<size_t, double> > Points;

template <typename T>
void print (T A) {		// Works with vector based STL
  for (typename T::iterator it = A.begin(); it != A.end(); ++it) {
    cout << *it << '\t';
  }
  cout << endl;
}

////////////////////////////////////////////////
// P-4.1
vector<float> prefixAverages1(vector<int> X, size_t n) {
  // size_t n = X.size();
  vector<float> A;// = vector<float>(n);
  int a;
  for (size_t i = 0; i < n; i++) {
    a = 0;
    for (size_t j = 0; j <= i; j++) {
      a += X[j];
    }
    A.push_back(a / (i + 1.0));
  }
  return A;
}

vector<float> prefixAverages2(vector<int> X, size_t n) {
  vector<float> A;
  int s = 0;
  for (size_t i = 0; i < n; i++) {
    s += X[i];
    A.push_back(s/(i+1));
  }
  return A;
}

void plot(Points ar) {
  cout << "Pnts\t" << "Time\t" << "Plot\n";
  for (Points::iterator it = ar.begin(); it != ar.end(); ++it) {
    cout << it->first << "\t" << it->second << "\t|";
    for (size_t i = 0; i <= it->second; i++) {
      cout << '*';
    }
    cout << endl;
  }
}


Points test1(const vector<int>& X) {
  Points elapsed;
  for (size_t n = 1; n <= X.size(); n = round(n*1.78)) {
    clock_t begin = clock();
    prefixAverages1(X, n);
    clock_t end = clock();
    elapsed.push_back(make_pair(n, double(end-begin)/CLOCKS_PER_SEC));
  }
  plot (elapsed);
  return elapsed;
}

Points test2(const vector<int>& X) {
  Points elapsed;
  for (size_t n = 1; n <= X.size(); n = round(n*1.78)) {
    clock_t begin = clock();
    prefixAverages2(X, n);
    clock_t end = clock();
    elapsed.push_back(make_pair(n, double(end-begin)/CLOCKS_PER_SEC));
  }
  plot (elapsed);
  return elapsed;
}


void P_4_1 () {
  vector<int> X;
  for (size_t i = 0; i < 100000; i++){
    X.push_back(i);
  }
  test1(X);
  cout << endl;
  test2(X);
}

////////////////////////////////////////////////
// P-4.3
#define MAX 10000000
void P_4_3() {
  Points elapsed;
  vector<int> X, Y;
  for (size_t i = 0; i < MAX; i++) {
    X.push_back(rand()%256);
  }
  
  int n = 1;
  while (n <= MAX) {
    Y = X;
    clock_t begin = clock();
    sort(Y.begin(), Y.begin()+n);
    clock_t end = clock();
    n *= 10;
    elapsed.push_back(make_pair(log10(n), double(end-begin)/CLOCKS_PER_SEC));
  }
  plot(elapsed);
}


////////////////////////////////////////////////
int main() {
  srand(time(NULL));
  cout << "********************P-4.1********************\n";
  P_4_1();
  cout << "********************P-4.3********************\n";
  cout << "10^";
  P_4_3();

  return 0;
}
