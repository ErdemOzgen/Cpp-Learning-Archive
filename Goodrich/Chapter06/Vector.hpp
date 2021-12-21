
#ifndef VECTOR_CH06_HPP
#define VECTOR_CH06_HPP

#include <memory>
#include "exceptions.hpp"

/* Chapter 6.1 - GR C++ */
template <typename T> class ArrayVector;
template <typename T> std::ostream& operator<<(std::ostream&, const ArrayVector<T>&);


template <typename T>
class ArrayVector {
public:
  ArrayVector();		// Construct
  size_t size() const;
  bool empty() const;
  T& operator[](int i);
  T& at(int i) throw (IndexOutOfBounds);
  void reserve(int N);
  void erase(int i);
  void insert(int i, const T& e);
  void insert(const T& e);	// Insert in the end
  // housekeeping?
public:				// friends
  friend std::ostream& operator<< <T> (std::ostream&, const ArrayVector<T>&);
private:
  int capacity;
  size_t n;
  // T* A;
  // std::unique_ptr<T[]> A = std::unique_ptr<T[]>(new T[capacity]);
  std::unique_ptr<T[]> A;
};

template <typename T>
ArrayVector<T>::ArrayVector()
  : capacity(0), n(0) {		// , A(NULL) {}
  A = NULL;
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
    B[j] = A[j];
  // if (A != NULL) delete [] A; /* Using smart ptr, so don't need that */
  // A = B; /* Smart ptr needs to use 'move' when going out of scope*/
  A = std::move(B);
  capacity = N;
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
void ArrayVector<T>::insert(const T& e) { // Insert in the end
  insert(n, e);
}


#endif
