#ifndef LIST_TEMPLATED_HPP
#define LIST_TEMPLATED_HPP

template <typename T>
class NodeList {		// node-based list
private:
  struct Node;
public:
  class Iterator;
public:
  NodeList();			   // default constructor
  size_t size() const;		   // list size
  bool empty() const;		   // is the list empty?
  Iterator begin() const;	   // beginning position
  Iterator end() const;		   // (just beyond) last position
  Iterator position() const;
  void insertFront(const T& e); // insert at front
  void insertBack(const T& e);  // insert at rear
  void insert(const Iterator& p, const T& e); // insert e before p
  void insert(const T e[], size_t elems);	 // Insert an array
  void eraseFront();				 // remove first
  void eraseBack();				 // remove last
  void erase(const Iterator& p);		 // remove p
  
  // housekeeping functions omitted...
  template <class U>
  friend std::ostream& operator<<(std::ostream&, const NodeList<U>&);
private:			// data members
  int     n;			// number of items
  Node*   header;		// head-of-list sentinel
  Node*   trailer;		// tail-of-list sentinel
  Node*   v;			// Current position
};

// Code Fragment: Node-class
template <typename T>
struct NodeList<T>::Node {		// a node of the list
  T elem;				// element value
  Node* prev;			// previous in list
  Node* next;			// next in list
};

// Code Fragment: Iterator-class
template <typename T>
class NodeList<T>::Iterator {	// an iterator for the list
public:				// 
  T& operator*();		// reference to the element
  bool operator==(const Iterator& p) const; // compare positions
  bool operator!=(const Iterator& p) const; // 
  Iterator& operator++();		    // move to next position
  Iterator& operator--();	// move to previous position
  friend class NodeList;	// give NodeList access
private:			// 
  Node* v;			// pointer to the node
  Iterator(Node* u);		// create from node
};

// Code Fragment: Iterator-methods
template <typename T>
NodeList<T>::Iterator::Iterator(Node* u)		// constructor from Node*
{ v = u; }

template <typename T>
T& NodeList<T>::Iterator::operator*()		// reference to the element
{ return v->elem; }

// compare positions
template <typename T>
bool NodeList<T>::Iterator::operator==(const Iterator& p) const
{ return v == p.v; }

template <typename T>
bool NodeList<T>::Iterator::operator!=(const Iterator& p) const
{ return v != p.v; }

// move to next position
template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator++()
{ v = v->next; return *this; }

// move to previous position
template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--()
{ v = v->prev; return *this; }

// Code Fragment: Simple
template <typename T>
NodeList<T>::NodeList() {		// constructor
  n = 0;			// initially empty
  header = new Node;				// create sentinels
  trailer = new Node;
  header->next = trailer;			// have them point to each other
  trailer->prev = header;
  v = header;
}

template <typename T>
size_t NodeList<T>::size() const 			// list size
{ return n; }

template <typename T>
bool NodeList<T>::empty() const 			// is the list empty?
{ return (n == 0); }

// Code Fragment: Begin-End
template <typename T>
typename NodeList<T>::Iterator NodeList<T>::begin() const	// begin position is first item
{ return Iterator(header->next); }

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end() const	// end position is just beyond last
{ return Iterator(trailer); }

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::position() const
{ return Iterator(v); }


// Code Fragment: Erase
template <typename T>
void NodeList<T>::erase(const Iterator& p) {	// remove p
  Node* v = p.v;				// node to remove
  Node* w = v->next;				// successor
  Node* u = v->prev;				// predecessor
  u->next = w;  w->prev = u;			// unlink p
  delete v;					// delete this node
  n--;						// one fewer element
}

template <typename T>
void NodeList<T>::eraseFront()			// remove first
{ erase(begin()); }

template <typename T>
void NodeList<T>::eraseBack()			// remove last
{ erase(--end()); }

// Code Fragment: Insert
template <typename T>		// insert e before p
void NodeList<T>::insert(const NodeList<T>::Iterator& p, const T& e) {
  Node* w = p.v;				// p's node
  Node* u = w->prev;				// p's predecessor
  Node* v = new Node;				// new node to insert
  v->elem = e;
  v->next = w;  w->prev = v;			// link in v before w
  v->prev = u;  u->next = v;			// link in v after u
  n++;
}

template <typename T>
void NodeList<T>::insertFront(const T& e)	// insert at front
{ insert(begin(), e); }

template <typename T>
void NodeList<T>::insertBack(const T& e)	// insert at rear
{ insert(end(), e); }

template <typename T>
void NodeList<T>::insert(const T e[], size_t elems) {
  for (size_t i = 0; i < elems; i++) {
    insertBack(e[i]);
  }
}

// 
template <typename T>
std::ostream& operator<<(std::ostream& os, const NodeList<T>& NL) {
  os << "[ ";
  for (typename NodeList<T>::Iterator it = NL.begin(); it != NL.end(); ++it) {
    os << *it << ' ';
  }
  //os << NL.n;
  os << ']';
  return os;
}

#endif
