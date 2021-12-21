
#include <iostream>

#include "ListTemplated.hpp" // Provides the doubly linked list

using namespace std;

void updateScreen(NodeList<char> NL) {
  for (NodeList<char>::Iterator it = NL.begin(); it != NL.end(); ++it) {
    std::cout << *it;
  }
}

void getKey(NodeList<char> NL) {
  char c;
  std::cin >> c;
  if (c == char("\u2192")) {
    std::cout << "TEST";
  }
  NL.insert(NL.position(), c);
}

int main() {
  NodeList<char> text;
  while (true) {
    updateScreen(text);
    getKey(text);
  }
}
