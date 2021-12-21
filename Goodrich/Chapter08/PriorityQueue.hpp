#ifndef PRIORITY_QUEUE_ADT
#define PRIORITY_QUEUE_ADT

#include <list>
#include <stdexcept>

/* Comparators */
/*
bool operator<(const Point2D& p, const Point2D& q) {
  if (p.getX() == q.getX()) return p.getY() < q.getY();
  else return p.getX() < q.getX();
}
*/
/*
class LeftRight {
public:
  bool operator()(const Point2D& p, const Point2D& q) const {
    return p.getX() < q.getX();
  }
};

class BottomTop {
public:
  bool operator()(const Point2D& p, const Point2D& q) {
    return p.getY() < q.getY();
  }
};
*/
/*
template <typename E, typename C> // element and comparator
void printSmaller (const E& p, const E& q, const C& isLess) {
  cout << (isLess(p, q) ? p : q) << endl;
}
*/
/*
Point2D p(1.3, 5.7), q(2.5, 0.6);
LeftRight leftRight;
BottomTop bottomTop;
printSmaller(p, q, leftRight);
printSmaller(p, q, bottomTop);
*/
/*
template <typename E, typename C> // element and comparator
class PriorityQueueADT {
public:
  int size() const;
  bool isEmpty() const;
  void insert (const E& e);
  const E& min() const throw(QueueEmpty);		// Minimum element
  void removeMin() throw(QueueEmpty);
  
  private:
    std::list<E> L;
    C isLess;

};
*/

template <typename E, typename C>
class ListPriorityQueue {
public:
  int size() const;		// Size
  bool empty() const;		// Empty?
  void insert (const E& e);	// insert new element
  const E& min() const throw(std::runtime_error); // return the smallest
  void removeMin() throw(std::runtime_error);     // remove the smallest
private:
  std::list<E> L;
  C isLess;
};

template <typename E, typename C>
int ListPriorityQueue<E, C>::size() const {
  return L.size();
}

template <typename E, typename C>
bool ListPriorityQueue<E, C>::empty() const {
  return L.size() == 0;
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::insert(const E& e) {
  typename std::list<E>::iterator p; // This is an iterator
  p = L.begin();		     // Assign the iterator to the begin()
  while (p != L.end() && !isLess(e, *p)) ++p; // If in the end, or found greater stop
  L.insert(p, e);			      // ... and insert
}

template <typename E, typename C>
const E& ListPriorityQueue<E, C>::min() const throw (std::runtime_error) {
  if (empty()) throw std::runtime_error("No min in empty queue");
  return L.front();
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::removeMin() throw(std::runtime_error) {
  if (empty()) throw std::runtime_error("Cannot remove from empty queue");
  L.pop_front();
}

#endif
