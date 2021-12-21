#include <iostream>
#include <vector>

#include "./exceptions.hpp"
#include "./projects.hpp"

using namespace std;


int main() {
  cout << "************P-6.1*******************\n";
  ArrayVector<int> A(3);
  cout << A << endl;
  A.insertFront(20);
  A.debug();
  cout << A << endl;
  A.insertFront(10);
  A.debug();
  cout << A << endl;
  A.insertFront(1);
  A.debug();
  cout << A << endl;
  A.insertFront(-10);
  A.debug();
  cout << A << endl;
  A.insertFront(-20);
  A.debug();
  cout << A << endl;
  A.insertFront(-30);
  A.debug();
  cout << A << endl;
  A.insertFront(-40);
  A.debug();
  cout << A << endl;

  A.insertBack(30);
  A.debug();
  cout << A << endl;
  
  A.insertFront(-50);
  A.debug();
  cout << A << endl;
  
  cout << "************P-6.2*******************\n";
  DLL <int> B;
  cout << B << endl;
  B.insertAfter(B.head, 1);
  cout << B << endl;
  try{
    B.insertAfter(B.head, 2);
  } catch (RuntimeException e) {
    cout << e.getMessage() << endl;
  }
  
  cout << B << endl;
  B[1] = 3;
  cout << B << endl;
  cout << B[1] << endl;
  cout << B.at(1) << endl;
  B.at(1) = 2;
  cout << B << endl;

}
