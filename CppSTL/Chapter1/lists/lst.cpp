#include <iostream>
#include <list>
#include <algorithm>  // copy
#include <iterator> // ostream_iterator

using namespace std;

template<class T>
class LIST {
  template<typename TT>
  friend ostream& operator<<( ostream& , LIST<TT>& );
private:
  list<T> lst;
  T limit;
public:
  LIST(T lm) : limit(lm) {}
  ~LIST() {
    cout << "Poping elements...\n";
    while( !lst.empty() ) {
      cout << lst.back() << " ";
      lst.pop_back();
    }
    cout << "\n";
  }
  void push() {
    cout << "Pushing elements...\n";
    for(T i=0; i<limit; i++)
      lst.push_back(i);
  }
};

template<typename TT>
ostream& operator<<( ostream& out, LIST<TT> &listRef ) {
  ostream_iterator<TT> output( out, " " );
  copy( listRef.lst.begin(), listRef.lst.end(), output );
  out << "\n";
  return out;
}

main() {

  LIST<int> LI(21);
  LI.push();
  cout << LI;

  return 0;
}
