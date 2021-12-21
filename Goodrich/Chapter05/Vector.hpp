#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Stack.hpp"
#include <vector>

template <typename E>
std::ostream& operator<<(std::ostream& os, const std::vector<E>& V) {
  os << '[';
  for (typename std::vector<E>::const_iterator it = V.begin(); it != V.end(); ++it) {
    os << *it;
    if (it+1 != V.end())	// This is the last value
      os << ',';
  }
  os << ']';
  return os;
}

template <typename E>
  void reverse (std::vector<E>& V) {
  // ArrayStack<E> S(V.size());
  LinkedStack<E> S;
  for (int i = 0; i < V.size(); i++) {
    S.push(V.at(i));
  }
  for (int i = 0; i < V.size(); i++) {
    V.at(i) = S.top();
    S.pop();
  }
}



#endif
