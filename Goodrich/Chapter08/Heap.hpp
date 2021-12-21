#ifndef HEAP_TREE_HPP
#define HEAP_TREE_HPP

#include <vector>

// Vector based complete binary tree
template <typename E>
class VectorCompleteTree {
private:
  std::vector<E> V;		// Tree constents
public:
  typedef typename std::vector<E>::iterator Position; // Position in the tree
protected:
  Position pos(int i) {		// map index to a position
    return V.begin() + i;
  }
  int idx(const Position& p) const { // map a position to index
    return p - V.begin();
  }
public:
  VectorCompleteTree() : V(1) {} // constructor
  int size() const { return V.size() - 1; } // Size of the tree
  Position left (const Position& p) { return pos(2*idx(p)); } // left position
  Position right (const Position& p) { return pos(2*idx(p)) + 1; } // right position
  Position parent (const Position& p) { return pos(idx(p) >> 1); } // parent position
  bool hasLeft ( const Position& p) const { return 2*idx(p) <= size(); } // Is there left?
  bool hasRight ( const Position& p) const { return 2*idx(p) + 1 <= size(); } // Is there right?
  bool isRoot ( const Position& p) const { return idx(p) == 1; } // Is root?
  Position root() { return pos(1); }				 // Get the root
  Position last() { return pos(size()); }			 // Get the last element
  void addLast(const E& e) { V.push_back(e); }			 // Add element to the end
  void removeLast() { V.pop_back(); }				 // Remove last element
  void swap(const Position& p, const Position& q) {		 // Swap two elementscV
    E e = *q;
    *q = *p;
    *p = e;
  }
};

template <typename E, typename C>
class HeapPriorityQueue {
public:
  HeapPriorityQueue() : T(VectorCompleteTree<E>()) {}; // Default constructor
  // HeapPriorityQueue(std::vector<E> L);		// Bottom-up constructor
public:
  int size() const;		// number of elements
  bool empty() const;		// is it empty?
  void insert (const E& e);	// insert element
  const E& min();		// minimum element
  void removeMin();		// remove minimum
private:
  VectorCompleteTree<E> T;	// priority queue constents
  C isLess;			// less than comparator

  typedef typename VectorCompleteTree<E>::Position Position;
};

template <typename E, typename C> // Number of elements
int HeapPriorityQueue<E,C>::size() const {
  return T.size();
}

template <typename E, typename C> // is it empty?
bool HeapPriorityQueue<E,C>::empty() const {
  return size() == 0;
}

template <typename E, typename C>
const E& HeapPriorityQueue<E,C>::min() {
  return *(T.root());
}

template <typename E, typename C>
void HeapPriorityQueue<E,C>::insert(const E& e) {
  T.addLast(e);			// Add e to heap
  Position v = T.last();	// e's position
  while (!T.isRoot(v)) {
    Position u = T.parent(v);
    if (!isLess(*v, *u)) break;	// if v in order, we're done
    T.swap(v, u);		// ... else swap with parent
    v = u;
  }
}

template <typename E, typename C> // remove minimum
void HeapPriorityQueue<E,C>::removeMin() {
  if (size() == 1)		// if only one element
    T.removeLast();		// get rid of it
  else {
    Position u = T.root();	// Root position
    T.swap(u, T.last());	// swap last with root
    T.removeLast();		// remove the last one
    while (T.hasLeft(u)) {	// down-heap bubbling
      Position v = T.left(u);
      if (T.hasRight(u) && isLess(*(T.right(u)), *v))
	v = T.right(u);		// v is u's smaller child
      if (isLess(*v, *u)) {	// is u out of order?
	T.swap(u, v);		// swap it
	u = v;
      }
    }
  }
}

/*
template <typename E, typename C>
HeapPriorityQueue<E,C>::HeapPriorityQueue(std::vector<E> L) { // Bottom-up constructor
  this.T = BottomUpHeap<E>(L);
}

template <typename E>
typename VectorCompleteTree<E> BottomUpHeap(std::vector<E> L, int begin, int n) {
  VectorCompleteTree<E> T;
  E e;
  if (begin > end) return T;	// Empty vector 
  e = L.at(begin);		// L.front()
  begin++;			// L.pop_front()
  
}
*/
#endif


