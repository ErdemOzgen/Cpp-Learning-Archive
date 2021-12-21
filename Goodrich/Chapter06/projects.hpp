#ifndef VECTOR_CH06_HPP
#define VECTOR_CH06_HPP

#include <memory>
#include "exceptions.hpp"

/* Chapter 6, Problem 6.1 - GR C++ */
template <typename T> class ArrayVector;
template <typename T> std::ostream& operator<<(std::ostream&, const ArrayVector<T>&);

template <typename T>
class ArrayVector {
public:
  ArrayVector();		// Construct
  ArrayVector(size_t N);
  ArrayVector(const ArrayVector<T>& AV);
  size_t size() const;
  bool empty() const;
  T& operator[](int i);
  T& at(int i) throw (IndexOutOfBounds);
  void reserve(int N);
  void erase(int i);
  void insert(int i, const T& e);
  void insertBack(const T& e);	// Insert in the end
  void insertFront(const T& e);	// Insert in the front
  // housekeeping
  void debug();
public:				// friends
  friend std::ostream& operator<< <T>(std::ostream&, const ArrayVector<T>&);
private:
  size_t capacity;
  size_t n;
  size_t front;
  std::unique_ptr<T[]> A;
};

template <typename T>
ArrayVector<T>::ArrayVector()
  : capacity(0), n(0), front(0) {		// , A(NULL) {}
  A = NULL;
}

template <typename T>
ArrayVector<T>::ArrayVector(size_t N) 
  : capacity(N), n(0), front(0) {
  if (N < 2) N = 2;
  A = std::unique_ptr<T[]>(new T[N]);
}


template <typename T>
ArrayVector<T>::ArrayVector(const ArrayVector<T>& AV) {
  capacity = AV.capacity;
  n = AV.n;
  front = AV.front;
  std::unique_ptr<T[]> B = std::unique_ptr<T[]>(new T[AV.capacity]);
  for (int j = 0; j < AV.n; j++) {
    B[j] = AV.A[j];
  }
  A = std::move(B);
}


template <typename T>
size_t ArrayVector<T>::size() const {
  return n;
}

template <typename T>
bool ArrayVector<T>::empty() const {
  return (size() == 0);
}

template <typename T>
T& ArrayVector<T>::operator[] (int i) {
  return A[i];
}

template <typename T>
T& ArrayVector<T>::at(int i) throw (IndexOutOfBounds) {
  if (i < 0 || i >= size())
    throw IndexOutOfBounds("Illegal index in function at()");
  return A[i];
}

template <typename T>
void ArrayVector<T>::reserve(int N) {
  if (capacity >= N) return;
  std::unique_ptr<T[]> B = std::unique_ptr<T[]>(new  T[N]);
  for (int j = 0; j < n; j++)
    B[j] = A[(j+front) % capacity];
  A = std::move(B);
  capacity = N;
  front = 0;
}

template <typename T>
void ArrayVector<T>::erase(int i) {
  for (int j = i + 1; j < n; j++)
    A[j-1] = A[j];
  n--;
}

template <typename T>
void ArrayVector<T>::insert(int i, const T& e) {
  if (n >= capacity){
    int c = 2*capacity;
    (1 > c) ? reserve(1) : reserve(c);
  }
  for (int j = n - 1; j >= i; j--)
    A[j+1] = A[j];
  A[i] = e;
  n++;
}

template <typename T>
void ArrayVector<T>::insertBack(const T& e) { // Insert in the end
  if (n >= capacity) {
    int c = 2*capacity;
    (1 > c) ? reserve (1) : reserve (c);
  }
  A[(front+n)%capacity] = e;
  n++;
}

template <typename T>
void ArrayVector<T>::insertFront(const T& e) {
  if (n >= capacity) {
    int c = 2*capacity;
    (1 > c) ? reserve (1) : reserve (c);
  }
  if (front == 0) front = capacity - 1;
  else front--;
  A[front] = e;
  n++;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ArrayVector<T>& AV) {
  if (AV.capacity == 0) {
    os << "[ Zero Capacity! ]";
    return os;
  }
  // size_t end = (AV.front + AV.n) % AV.capacity;
  os << "[ ";
  
  for (size_t i = 0; i < AV.n; i++) {
    size_t index = (i+AV.front) % AV.capacity;
    os << index << ":";
    os << AV.A[index] << ' ';
  }
  os << ']';
  return os;
}

template <typename T>
void ArrayVector<T>::debug() {
  std::cout << "[ Capacity: " << capacity << "; ";
  std::cout << "Front: " << front << "; ";
  std::cout << "n: " << n << "; ";
  for (int i = 0; i < capacity; i++) {
    std::cout << A[i] << ' ';
  }
  std::cout << "]" << std::endl;
}

/* Chapter 6, Problem 6.2 - GR C++ */
template <typename T> class Node;
template <typename T> class DLL;
template <typename T> std::ostream& operator<<(std::ostream&, const DLL<T>&);
template <typename T> std::ostream& operator<<(std::ostream&, const Node<T>&);

template <typename T>
class Node {
private:
  T val;
  Node<T> *prev;
  Node<T> *next;

private:
  Node() {
    prev = NULL;
    next = NULL;
  }
  Node(Node<T> *prev, Node<T> *next) {
    this->prev = prev;
    this->next = next;
  }
  Node(Node<T> *prev, Node<T> *next, T val) {
    this->prev = prev;
    this->next = next;
    this->val = val;
  }
  ~Node() {
    this->next = NULL;
    this->prev = NULL;
  }

private:
  friend class DLL<T>;		// Give access to the DLL
  friend std::ostream& operator<< <T> (std::ostream& os, const Node<T>& n);
  friend std::ostream& operator<< <T> (std::ostream& os, const DLL<T>& d);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Node <T> & n) {
  os << n.val;
  return os;
}

template <typename T>
class DLL {
public:
  DLL();
  ~DLL();
  bool empty() const;		// Is it empty?
  size_t size() const;		// Size of the DLL
  T& front() const;		// get the front
  T& back() const;		// get the back
  T& operator[](int i);
  const T& operator[](int i) const;
  T& at(int i);
  const T& at(int i) const throw (IndexOutOfBounds); // element at(i)
  void insertBefore(Node <T>* node, const T& v) throw (LinkedListOutOfBounds); // Add before "node"
  void insertAfter(Node <T>* node, const T& v) throw (LinkedListOutOfBounds);  // Add after "node"
  void remove(Node <T>*node);		      // Remove "node"
  
public:
  Node<T> *head;
  Node<T> *tail;
  size_t elemNum;

public:
  // TODO: Declare COUT method
  friend std::ostream& operator<< <T> (std::ostream& os, const DLL<T>& d);
};

template <typename T>
DLL<T>::DLL() {
  head = new Node<T>;
  tail = new Node<T>(head, head);
  head->prev = tail;
  head->next = tail;
  elemNum = 0;
}

template <typename T>
DLL<T>::~DLL() {
  while (!empty()) {
    remove(head->next);
  }
  delete head;
  delete tail;
}

template<typename T>
bool DLL<T>::empty() const{
  return elemNum == 0;
  // return head->next == tail;
}

template <typename T>
T& DLL<T>::front() const {
  return head->next->val;
}

template <typename T>
T& DLL<T>::back() const {
  return tail->prev->val;
}

template <typename T>
T& DLL<T>::operator[](int i) {
  Node <T>*n = this->head;
  int counter = 0;
  while (counter > i) {
    n = n->next;
    counter++;
  }
  return n->next->val;
}

template <typename T>
const T& DLL<T>::operator[](int i) const {
  return const_cast<T&>(*this)[i];
}

template <typename T>
T& DLL<T>::at(int i) {
  return (*this)[i];
}

template <typename T>
const T& DLL<T>::at(int i) const throw (IndexOutOfBounds) {
  if (i < 0 || i >= elemNum) {
    throw IndexOutOfBounds("Illegal index in function at()");
  }
  // return const_cast<T&>(*this)[i];
  return const_cast<T&> (at(i));
}

template <typename T>
void DLL<T>:: insertBefore(Node <T>* node, const T& v) throw (LinkedListOutOfBounds) {
  if (node == this->head)
    throw LinkedListOutOfBounds("Cannot insert before head");
  Node<T> *n = new Node<T>(node->prev, node, v);
  n->prev->next = n;
  n->next->prev = n;  
  elemNum++;
}

template <typename T>
void DLL<T>::insertAfter(Node <T>* node, const T& v) throw (LinkedListOutOfBounds){
  if (node == this->tail)
    throw LinkedListOutOfBounds("Cannot insert after tail");
  Node<T> *n = new Node<T> (node, node->next, v);
  n->prev->next = n;
  n->next->prev = n;
  elemNum++;
}

template <typename T>
void DLL<T>::remove(Node<T> * n) {
  n->prev->next = n->next;
  n->next->prev = n->prev;
  delete n;
  elemNum--;
}

template <typename T> 
std::ostream& operator<<(std::ostream& os, const DLL<T>& d) {
  Node <T>* n = d.head;
  os << "HEAD<->";
  for (size_t i = 0; i < d.elemNum; i++) {
    os << n->next->val << "<->";
    n = n->next;
  }
  os << "TAIL";
  return os;
}

#endif
