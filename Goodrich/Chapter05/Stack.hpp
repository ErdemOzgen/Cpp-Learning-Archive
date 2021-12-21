#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include "exceptions.hpp"
#include "SLinkedList.hpp"

/***********************************************
 * Stack data structures
 * 
 ***********************************************/
// template <typename T>
// class Stack {
// public:
//   int size() const;		// Number of items
//   bool empty() const;		// Empty?
//   const T& top() const
//     throw (StackEmpty);		// Top element
//   void push (const T& e);	// push e into stack
//   void pop ()
//     throw (StackEmpty);		// remove the top
// };

/***************
 * Prototypes:
 ***************/
template <typename T> class ArrayStack;
template <typename T> class LinkedStack;
template <typename T> std::ostream&operator<<(std::ostream&, const ArrayStack<T>&);
template <typename T> std::ostream&operator<<(std::ostream&, const LinkedStack<T>&);

/*********************
 * Array based stack
 ********************/
// Array Stack:
template <typename E>
class ArrayStack {
  enum { DEF_CAPACITY = 100 };	// default capacity
public:
  ArrayStack(int cap = DEF_CAPACITY); // Constructor
  ~ArrayStack();
  int size() const;		      // Number of items
  bool empty() const;		      // Empty?
  const E& top() const		      // The top element
    throw (StackEmpty);		      // Error if empty
  void push(const E& e)		      // push a new element
    throw (StackFull);		      // Error if full
  void pop()			      // Remove the top
    throw(StackEmpty);		      // Error if empty
public:
  friend std::ostream& operator<< <> (std::ostream&, const ArrayStack<E>&);
private:
  unsigned int capacity;	// stack capacity
  //E* S;				// Array of stack elements
  std::unique_ptr<E[]> S = std::unique_ptr<E[]>(new E[capacity]);
  int t;		// index of the top
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
  : capacity (cap), S(new E[cap]), t(-1) {}

template <typename E>
ArrayStack<E>::~ArrayStack() {
  // delete S;
}

template <typename E>
int ArrayStack<E>::size() const {
  return t+1;
}

template <typename E>
bool ArrayStack<E>::empty() const {
  return t < 0;
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) {
  if (empty())
    throw StackEmpty("Top of empty stack");
  return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) {
  if (size() == capacity)
    throw StackFull("Push to full stack");
  S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty) {
  if (empty())
    throw StackEmpty("Pop from empty stack");
  --t;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayStack<E>& ar) {
  int t = ar.t;
  os << "{ ";
  while (t >= 0) {
    os << ar.S[t] << ' ';
    t--;
  }
  os << '}';
  return os;
}


/*************************
 * Linked List based Stack
 *************************/
template <typename T>
class LinkedStack {
public:
  LinkedStack();
  int size() const;
  bool empty() const;
  const T& top() const throw(StackEmpty); // the top element
  void push(const T& e);
  void pop() throw(StackEmpty); 
public:
  friend std::ostream& operator<< <> (std::ostream&, const LinkedStack<T>&);
private:
  SLinkedList<T> S; 
  int n;
};

template <typename T>
LinkedStack<T>::LinkedStack() : S(), n(0) {} // Constructor

template <typename T>	       
int LinkedStack<T>::size() const { // What is the size?
  return n;
}

template <typename T>
bool LinkedStack<T>::empty() const { // Is it empty?
  return n == 0;
}

template <typename T>
const T& LinkedStack<T>::top() const throw (StackEmpty) { // first element
  if (empty()) throw StackEmpty("Top of empty stack");
  return S.front();
}

template <typename T>
void LinkedStack<T>::push(const T& e) { // push element to the front
  ++n;
  S.addFront(e);
}

template <typename T>
void LinkedStack<T>::pop() throw (StackEmpty) { // remove the first value
  if (empty()) throw StackEmpty("Pop from empty stack");
  --n;
  S.removeFront();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedStack<T>& ar) {
  os << "TOP->";
  os << ar.S;
  // os << " }";
  return os;
}

#endif
