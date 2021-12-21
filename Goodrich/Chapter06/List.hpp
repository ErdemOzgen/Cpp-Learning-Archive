#ifndef LIST_HPP
#define LIST_HPP

// Code Fragment: Class
typedef int Elem;		// list base element type

class NodeList {		// node-based list
private:
  struct Node;
public:
  class Iterator;
public:
  NodeList();			   // default constructor
  int size() const;		   // list size
  bool empty() const;		   // is the list empty?
  Iterator begin() const;	   // beginning position
  Iterator end() const;		   // (just beyond) last position
  void insertFront(const Elem& e); // insert at front
  void insertBack(const Elem& e);  // insert at rear
  void insert(const Iterator& p, const Elem& e); // insert e before p
  void insert(const Elem e[], size_t elems);			 // Insert an array
  void eraseFront();				 // remove first
  void eraseBack();				 // remove last
  void erase(const Iterator& p);		 // remove p
  // housekeeping functions omitted...
  friend std::ostream& operator<<(std::ostream&, const NodeList&);
private:			// data members
  int     n;			// number of items
  Node*   header;		// head-of-list sentinel
  Node*   trailer;		// tail-of-list sentinel
};

// Code Fragment: Node-class
struct NodeList::Node {		// a node of the list
  Elem elem;			// element value
  Node* prev;			// previous in list
  Node* next;			// next in list
};

// Code Fragment: Iterator-class
class NodeList::Iterator {	// an iterator for the list
public:				// 
  Elem& operator*();		// reference to the element
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
NodeList::Iterator::Iterator(Node* u)		// constructor from Node*
{ v = u; }

Elem& NodeList::Iterator::operator*()		// reference to the element
{ return v->elem; }
// compare positions
bool NodeList::Iterator::operator==(const Iterator& p) const
{ return v == p.v; }

bool NodeList::Iterator::operator!=(const Iterator& p) const
{ return v != p.v; }
// move to next position
NodeList::Iterator& NodeList::Iterator::operator++()
{ v = v->next; return *this; }
// move to previous position
NodeList::Iterator& NodeList::Iterator::operator--()
{ v = v->prev; return *this; }

// Code Fragment: Simple
NodeList::NodeList() {		// constructor
  n = 0;			// initially empty
  header = new Node;				// create sentinels
  trailer = new Node;
  header->next = trailer;			// have them point to each other
  trailer->prev = header;
}

int NodeList::size() const 			// list size
{ return n; }

bool NodeList::empty() const 			// is the list empty?
{ return (n == 0); }

// Code Fragment: Begin-End
NodeList::Iterator NodeList::begin() const	// begin position is first item
{ return Iterator(header->next); }

NodeList::Iterator NodeList::end() const	// end position is just beyond last
{ return Iterator(trailer); }

// Code Fragment: Erase
void NodeList::erase(const Iterator& p) {	// remove p
  Node* v = p.v;				// node to remove
  Node* w = v->next;				// successor
  Node* u = v->prev;				// predecessor
  u->next = w;  w->prev = u;			// unlink p
  delete v;					// delete this node
  n--;						// one fewer element
}

void NodeList::eraseFront()			// remove first
{ erase(begin()); }

void NodeList::eraseBack()			// remove last
{ erase(--end()); }

// Code Fragment: Insert
						// insert e before p
void NodeList::insert(const NodeList::Iterator& p, const Elem& e) {
  Node* w = p.v;				// p's node
  Node* u = w->prev;				// p's predecessor
  Node* v = new Node;				// new node to insert
  v->elem = e;
  v->next = w;  w->prev = v;			// link in v before w
  v->prev = u;  u->next = v;			// link in v after u
  n++;
}

void NodeList::insertFront(const Elem& e)	// insert at front
{ insert(begin(), e); }

void NodeList::insertBack(const Elem& e)	// insert at rear
{ insert(end(), e); }

void NodeList::insert(const Elem e[], size_t elems) {
  for (size_t i = 0; i < elems; i++) {
    insertBack(e[i]);
  }
}

// 
std::ostream& operator<<(std::ostream& os, const NodeList& NL) {
  os << "[ ";
  for (NodeList::Iterator it = NL.begin(); it != NL.end(); ++it) {
    os << *it << ' ';
  }
  //os << NL.n;
  os << ']';
  return os;
}

#endif
