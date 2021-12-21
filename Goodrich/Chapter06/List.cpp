// Code Fragment: Main

#include <iostream>					// I/O definitions
#include "List.hpp"

using namespace std;					// make std:: accessible

int main () {
  NodeList NL;
  NL.insertFront(12);
  cout << NL;
  int a[] = {17, 12, 33, 15, 62, 45};
  NL.insert(a, 6);
  cout << NL;
  return EXIT_SUCCESS;
}
