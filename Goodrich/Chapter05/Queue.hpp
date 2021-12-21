#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "exceptions.hpp"
#include "CLinkedList.hpp"


/***********************************************
 * Queue data structures
 * 
 ***********************************************/

// template <typename T>
// class Queue {
// public:
//   int size() const;		// number of items in Queue
//   bool empty() const;		// empty?
//   const E& front() const throw (QueueEmpty); // front element
//   void enqueue (const T& e);		     // enque to the back
//   void dequeue () throw (QueueEmpty); // dequeue from front
// };

/***************
 * Prototypes:
 ***************/
template <typename T> class ArrayQueue;
template <typename T> class LinkedQueue;
template <typename T> std::ostream&operator<<(std::ostream&, const ArrayQueue<T>&);
template <typename T> std::ostream&operator<<(std::ostream&, const LinkedQueue<T>&);

/*********************
 * Array based stack
 ********************/
template <typename E>
class ArrayQueue {
  enum { DEF_CAPACITY = 100 };	// default capacity
public:
  ArrayQueue(int cap = DEF_CAPACITY); // Constructor
  unsigned int size() const;	      // Number of items
  bool empty() const;		      // Empty?
  const E& front() const	      // The front element
    throw (QueueEmpty);		      // Error if empty
  void enqueue(const E& e)	      // push a new element
    throw (QueueFull);		      // Error if full
  void dequeue()		      // Remove the top
    throw(QueueEmpty);		      // Error if empty
public:
  friend std::ostream& operator<< <> (std::ostream&, const ArrayQueue<E>&);
private:
  E* Q;				// Array of stack elements
  unsigned int capacity;	// stack capacity
  unsigned int f;		// front of the queue
  unsigned int r;		// rear of the queue
  unsigned int n;			// NUmber of elements
};

template <typename E>
ArrayQueue<E>::ArrayQueue(int cap)
  : Q(new E[cap]), capacity (cap), f(0), r(0), n(0) {}

template <typename E>
unsigned int ArrayQueue<E>::size() const {
  return n;
}

template <typename E>
bool ArrayQueue<E>::empty() const {
  return n == 0;
}

template <typename E>
const E& ArrayQueue<E>::front() const throw(QueueEmpty) {
  if (empty())
    throw QueueEmpty("Front of empty Queue");
  return Q[f];
}

template <typename E>
void ArrayQueue<E>::enqueue(const E& e) throw(QueueFull) {
  if (size() == capacity)
    throw QueueFull("Enqueue to full Queue");
  Q[r] = e;
  r = (r + 1) % capacity;
  n++;
}

template <typename E>
void ArrayQueue<E>::dequeue() throw(QueueEmpty) {
  if (empty())
    throw QueueEmpty("Dequeue from empty Queue");
  f = (f+1) % capacity;
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayQueue<E>& ar) {
  if (ar.empty()) {
    os << "EMPTY";
  } else {
    for (unsigned i = 0; i < ar.capacity; i++) {
      if (ar.f < ar.r) {  // case 2
        if (i >= ar.f && i < ar.r)
          os << ar.Q[i];
        else
          os << 'N';
      } else { // case 2
        if (i >= ar.r && i < ar.f)
          os << 'N';
        else
          os << ar.Q[i];
      }
      os << ' ';
    }
  }
  return os;
}

/*************************
 * Linked List based Queue
 *************************/
template <typename E>
class LinkedQueue {
public:
  LinkedQueue();		// Constructor
  unsigned int size() const;	// Number of items
  bool empty() const;		// Empty?
  const E& front() const	// The front element
    throw (QueueEmpty);		// Error if empty
  void enqueue(const E& e);	// push a new element
  void dequeue()		// Remove the top
    throw(QueueEmpty);		// Error if empty
public:
  friend std::ostream& operator<< <> (std::ostream&, const LinkedQueue<E>&);
private:
  CLinkedList<E> C;		// CLL of stack elements
  unsigned int n;		// NUmber of elements
};

template <typename E>
LinkedQueue<E>::LinkedQueue() : C(), n(0) {}

template <typename E>
unsigned int LinkedQueue<E>::size() const {return n;}

template <typename E>
bool LinkedQueue<E>::empty() const {return n==0;}

template <typename E>
const E& LinkedQueue<E>::front() const throw (QueueEmpty) {
  if (empty())
    throw QueueEmpty("Front of empty queue!");
  return C.front();
}

template <typename E>
void LinkedQueue<E>::enqueue(const E& e) {
  C.add(e);
  C.advance();			// move the cursor
  n++;
}

template <typename E>
void LinkedQueue<E>::dequeue() throw (QueueEmpty) {
  if (empty())
    throw QueueEmpty("Dequeue of empty queue!");
  C.remove();
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedQueue<E>& CLL) {
  os << CLL.C;
  return os;
}

#endif
