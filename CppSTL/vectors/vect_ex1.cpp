#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

#define newline { cout << "\n"; }

template<class myType>
void print(  vector<myType> & );

template<class myType>
void print_even( vector<myType> & );

int main() {
  const int N = 5;
  int hold;
  typename std::vector<int> numbers{};
  for(size_t i = 0; i < N; ++i) {
    cout << "Enter value #" << i+1 << ": ";
    cin >> hold;
    numbers.push_back(hold);
  }
  print<int>( numbers );
  print_even<int> ( numbers );

  return 0;
}


template<class myType>
void print( vector<myType> &vect ) {
  typename std::vector<myType>::iterator itr = vect.begin();
  while( itr != vect.end() ) {
    cout << *itr << " ";
    itr++;
  }
  newline;
}


template<class myType>
void print_even( vector<myType> &vect ) {
  typename std::vector<myType>:: iterator itr = vect.begin();
  for( auto num : vect ) {
    if( !(num%2) )
      cout << *itr << "\n";
    ++itr;
  }

}
