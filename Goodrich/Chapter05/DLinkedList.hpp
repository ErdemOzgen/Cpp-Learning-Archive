#ifndef D_LINKED_LIST_HPP
#define D_LINKED_LIST_HPP

// prototypes:
template <typename T> class DLinkedList;
template <typename T> std::ostream& operator<<(std::ostream&, const DLinkedList<T>&);

template <typename T>
class DNode {
private:
  T elem;			// element value
  DNode<T> *prev;	// prev item in the list
  DNode<T> *next;	// next item in the list

  friend class DLinkedList<T>;	// access to DLinkedList
  friend std::ostream& operator<< <T>(std::ostream&, const DLinkedList<T>&);
};

template <typename T>
class DLinkedList {
public:
  DLinkedList();				// Empty list constructor
  ~DLinkedList();				// Destructor
  bool empty() const;			// is the list empty?
  const T& front() const;		// get the front element
  const T& back() const;		// get the back element
  void addFront(const T& e);	// add to the front
  void addBack(const T& e);	// add to the back
  void removeFront();			// remove from the front
  void removeBack();			// remove from the back
private:
  DNode<T> *head;
  DNode<T> *tail;
private:
  friend std::ostream& operator<< <T>(std::ostream&, const DLinkedList<T>&);
protected:
  void add(DNode<T> *v, const T& e);	// add node before v
  void remove(DNode<T> *v);
};

template <typename T>
DLinkedList<T>::DLinkedList(){		// constructor
  head = new DNode<T>;
  tail = new DNode<T>;
  head->next = tail;
  // head->prev = tail;
  // tail->next = head;
  tail->prev = head;
}

template <typename T>
DLinkedList<T>::~DLinkedList() {	// destructor
  while (!empty())
    removeFront();
  delete head;
  delete tail;
}

template <typename T>
bool DLinkedList<T>::empty() const {			// empty?
  return head->next == tail;
}

template <typename T>
const T& DLinkedList<T>::front() const {		// front element
  return head->next->elem;
}

template <typename T>
const T& DLinkedList<T>::back() const {		// front element
  return tail->prev->elem;
}

// insert new node before v
template <typename T>
void DLinkedList<T>::add(DNode<T> *v, const T& e) {	
  DNode<T> *u = new DNode<T>;
  u->elem = e;	// New node with e
  u->next = v;
  u->prev = v->prev;
  v->prev->next = u;
  v->prev = u;
  // v->prev->next = v->prev = u;
}

template <typename T>
void DLinkedList<T>::addFront(const T& e) {
  add(head->next, e);
}

template <typename T>
void DLinkedList<T>::addBack(const T& e) {
  add(tail, e);
}

template <typename T>
void DLinkedList<T>::remove(DNode<T> *v) {
  // Save the pointers:
  DNode<T> *u = v->prev;
  DNode<T> *w = v->next;
  // Update the prev and next:
  u->next = w;
  w->prev = u;
  delete v;
}

template <typename T>
void DLinkedList<T>::removeFront() {
  DLinkedList<T>::remove(head->next);
}

template <typename T>
void DLinkedList<T>::removeBack() {
  DLinkedList<T>::remove(tail->prev);
}

//////////////////////////////////////
template <typename T>
std::ostream& operator<<(std::ostream& os, const DLinkedList<T>& DL) {
  DNode<T> *p = DL.head->next;
  os << "HEAD" << "<->";
  while (p != DL.tail) {
    os << p->elem << "<->";
    p = p->next;
  }
  // delete p;
  os << "TAIL";
  // os << "\t" << DL.head->next->prev->elem << endl;
  return os;
}

#endif
