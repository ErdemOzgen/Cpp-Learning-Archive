#include <iostream>
#include "Stack.hpp"
#include "exceptions.hpp"

using namespace std;

int main() {
  ArrayStack<int> A;
  A.push(7);
  A.push(13);
  cout << A.top() << endl; 
  A.pop();
  A.push(9);
  cout << A.top() << endl;
  cout << A.top() << endl; 
  A.pop();

  ArrayStack<string> B(10);
  B.push("Bob");
  B.push("Alice");
  cout << B.top() << endl;
  B.pop();
  B.push("Eve");

  A.push(11);
  cout << "A = " << A << endl;

  cout << "B = " << B << endl;
}
