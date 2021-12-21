#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <memory>
#include "exceptions.hpp"
#include "DLinkedList.hpp"

/***********************************************
 * Double ended queue  data structures
 * 
 ***********************************************/

/*************
 * Prototypes
 *************/
template <typename E> class LinkedDeque;
template <typename E> class ArrayDeque;
template <typename E> std::ostream& operator<<(std::ostream&, const LinkedDeque<E>);
template <typename E> std::ostream& operator<<(std::ostream&, const ArrayDeque<E>&);


/*********************
 * Array based deque
 ********************/
template <typename E>
class ArrayDeque {
  enum { DEF_CAPACITY = 100 };
public:
  ArrayDeque(int cap = DEF_CAPACITY);
  ~ArrayDeque();
  unsigned int size() const;
  bool empty() const;
  bool full() const;
  const E& front() const throw (DequeEmpty);
  const E& back() const throw (DequeEmpty);
  void insertFront(const E& e) throw (DequeFull);
  void insertBack(const E& e) throw (DequeFull);
  void removeFront() throw (DequeEmpty);
  void removeBack() throw (DequeEmpty);
public:
  friend std::ostream& operator<< <E> (std::ostream&, const ArrayDeque<E>&);
private:
  unsigned int capacity;
  // E *D;
  std::unique_ptr<E[]> D = std::unique_ptr<E[]>(new E[capacity]);
  // std::unique_ptr<E[]> S = std::unique_ptr<E[]>(new E[capacity]);
  unsigned int n;
  // These point to "where to write":
  unsigned int f;
  unsigned int b;
};

template <typename E>
ArrayDeque<E>::ArrayDeque(int cap)
  : capacity(cap), D(new E[cap]), n(0), f(0), b(0) {}

template <typename E>
ArrayDeque<E>::~ArrayDeque() {
  // delete [] D;
}

template <typename E>
unsigned int ArrayDeque<E>::size() const {
  return n;
}

template <typename E>
bool ArrayDeque<E>::empty() const {
  return n == 0;
}

template <typename E>
bool ArrayDeque<E>::full() const {
  return n == capacity;
}

template <typename E>
void ArrayDeque<E>::insertFront(const E& e) throw (DequeFull) {
  if (full())
    throw DequeFull("Insert to the front of full deque!");
  f = (f == 0) ? (capacity - 1) : f - 1;
  D[f] = e;
  n++;    
}

template <typename E>
void ArrayDeque<E>::insertBack(const E& e)throw (DequeFull) {
  if (full())
    throw DequeFull("Insert to the end of full deque!");
  D[b] = e;
  b = (b + 1) % capacity;
  n++;
}

template <typename E>
void ArrayDeque<E>::removeFront() throw (DequeEmpty) {
  if (empty())
    throw DequeEmpty("Remove front of empty deque!");
  f = (f + 1) % capacity;
  n--;
}

template <typename E>
void ArrayDeque<E>::removeBack() throw (DequeEmpty) {
  if (empty())
    throw DequeEmpty("Remove back of empty deque!");
  b = (b == 0) ? (capacity - 1) : b - 1;
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayDeque<E>& ar) {
  unsigned int stop = (ar.full()) ? (ar.b - 1) : ar.b;
  os << "[f: ";
  for (unsigned i = ar.f; i != stop; i = (i + 1) % ar.capacity) {
    os << ar.D[i] << ' ';
  }
  os << ":b]";
  return os;
}

/********************************
 * Doubly Linked List based deque
 *******************************/
template <typename E>
class LinkedDeque {
public:
  LinkedDeque();
  ~LinkedDeque() {};
  unsigned int size() const;
  bool empty() const;
  const E& front() const throw (DequeEmpty);
  const E& back() const throw (DequeEmpty);
  void insertFront(const E& e);
  void insertBack(const E& e);
  void removeFront() throw (DequeEmpty);
  void removeBack() throw (DequeEmpty);
public:
  friend std::ostream& operator<< <E> (std::ostream& os, const LinkedDeque<E> LD);
private:
  DLinkedList <E> D;
  int n;
};

template <typename E>
LinkedDeque<E>::LinkedDeque() : D(DLinkedList<E>()), n(0) {};

template <typename E>
unsigned int LinkedDeque<E>::size() const { return n; }

template <typename E>
bool LinkedDeque<E>::empty() const { return n==0; }

template <typename E>
const E& LinkedDeque<E>::front() const throw (DequeEmpty) {
  if (empty()) 
    throw DequeEmpty("Front of empty deque!");
  return D.front();
}

template <typename E>
const E& LinkedDeque<E>::back() const throw (DequeEmpty) {
  if (empty()) 
    throw DequeEmpty("Back of empty deque!");
  return D.back();
}

template <typename E>
void LinkedDeque<E>::insertFront(const E& e) {
  D.addFront(e);
  n++;
}

template <typename E>
void LinkedDeque<E>::insertBack(const E& e) {
  D.addBack(e);
  n++;
}

template <typename E>
void LinkedDeque<E>::removeFront() throw (DequeEmpty) {
  if (empty())
    throw DequeEmpty("Remove from front of empty deque!");
  D.removeFront();
  n--;
}

template <typename E>
void LinkedDeque<E>::removeBack() throw (DequeEmpty) {
  if (empty())
    throw DequeEmpty("Remove from back of empty deque!");
  D.removeBack();
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedDeque<E> LD) {
  if (LD.empty()) {
    os << "[EMPTY]";
  } else {
    os << LD.D;
  }
  return os;
}

#endif
