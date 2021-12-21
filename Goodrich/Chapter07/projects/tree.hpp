#ifndef LINKED_BINARY_TREE_HPP
#define LINKED_BINARY_TREE_HPP

#include <cstdlib>
#include <iostream>
#include <list>

template <typename T> class LinkedBinaryTree;
template <typename T> std::ostream& operator<<(std::ostream& os, const LinkedBinaryTree<T>& lbt);
template <typename T> std::ostream& operator<<(std::ostream& os, const typename LinkedBinaryTree<T>::Position& p);

template <typename T>
class LinkedBinaryTree {
protected:
  struct Node {			// a node of the tree
    T    elt;		// element value
    Node*   par;		// parent
    Node*   left;		// left child
    Node*   right;		// right child
    Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
  };
  
public:
  class Position {		// position in the tree
  private:			// 
    Node* v;			// pointer to the node
  public:
    Position(Node* _v = NULL) : v(_v) { } // constructor
    T& operator*()			  // get element
    { return v->elt; }			  // 
    Position left() const		  // get left child
    { return Position(v->left); }	  // 
    Position right() const		  // get right child
    { return Position(v->right); }	  // 
    Position parent() const		  // get parent
    { return Position(v->par); }	  // 
    bool isRoot() const			  // root of the tree?
    { return v->par == NULL; }		  // 
    bool isExternal() const		  // an external node?
    { return v->left == NULL && v->right == NULL; } //
    void add(T value);
    friend class LinkedBinaryTree; // give tree access
  public:
    //friend std::ostream& operator<< <T> (std::ostream& os, const LinkedBinaryTree<T>::Position& p);
    friend inline std::ostream& operator<<(std::ostream& os, const Position& p) {
      os << '[';
      if (!p.isExternal()){
	os << p.left();
      }
      os << ' ';
      os << *(Position(p));
      os << ' ';
      if (!p.isExternal()) {
	os << p.right();
      }
      os << ']';
	
      return os;
    }
    
    friend std::ostream& operator<< <T>(std::ostream& os, const LinkedBinaryTree<T>& lbt);
  };
  typedef std::list<Position> PositionList; // list of positions
public:					    // 
  LinkedBinaryTree();			    // constructor
  int size() const;			    // number of nodes
  bool empty() const;			    // is tree empty?
  Position root() const;		    // get the root
  PositionList positions() const;	    // list of nodes
  void addRoot();			    // add root to empty tree
  void expandExternal(const Position& p);   // expand external node
  Position removeAboveExternal(const Position& p); // remove p and parent
				// housekeeping functions omitted...
protected:			// local utilities
  void preorder(Node* v, PositionList& pl) const; // preorder utility
public:
  friend std::ostream& operator<< <T>(std::ostream& os, const LinkedBinaryTree<T>& lbt);
private:					  // 
  Node* _root;			// pointer to the root
  int n;			// number of nodes
};				// 

template <typename T>
LinkedBinaryTree<T>::LinkedBinaryTree() // constructor
  : _root(NULL), n(0) { }

template <typename T>
int LinkedBinaryTree<T>::size() const // number of nodes
{ return n; }

template <typename T>
bool LinkedBinaryTree<T>::empty() const // is tree empty?
{ return size() == 0; }

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::root() const // get the root
{ return Position(_root); }

template <typename T>
typename LinkedBinaryTree<T>::PositionList LinkedBinaryTree<T>::positions() const {
  PositionList pl;
  preorder(_root, pl);		// preorder traversal
  return PositionList(pl);	// return resulting list
}

template <typename T>
void LinkedBinaryTree<T>::addRoot() // add root to empty tree
{ _root = new Node; n = 1; }

template <typename T>
void LinkedBinaryTree<T>::expandExternal(const Position& p) {
  Node* v = p.v;		// p's node
  v->left = new Node;		// add a new left child
  v->left->par = v;		// v is its parent
  v->right = new Node;		// and a new right child
  v->right->par = v;		// v is its parent
  n += 2;			// two more nodes
}

template <typename T>
typename LinkedBinaryTree<T>::Position	// remove p and parent
LinkedBinaryTree<T>::removeAboveExternal(const Position& p) {
  Node* w = p.v;  Node* v = w->par; // get p's node and parent
  Node* sib = (w == v->left ?  v->right : v->left);
  if (v == _root) {		// child of root?
    _root = sib;		// ...make sibling root
    sib->par = NULL;
  }
  else {
    Node* gpar = v->par;		   // w's grandparent
    if (v == gpar->left) gpar->left = sib; // replace parent by sib
    else gpar->right = sib;
    sib->par = gpar;
  }
  delete w; delete v;		// delete removed nodes
  n -= 2;			// two fewer nodes
  return Position(sib);
}

// preorder traversal
template <typename T>
void LinkedBinaryTree<T>::preorder(Node* v, PositionList& pl) const {
  pl.push_back(Position(v));	// add this node
  if (v->left != NULL)		// traverse left subtree
    preorder(v->left, pl);
  if (v->right != NULL)		// traverse right subtree
    preorder(v->right, pl);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedBinaryTree<T>& lbt){
  os << lbt.root();
  os << std::endl;
  // os << *(lbt.root());
  return os;
}

/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const typename LinkedBinaryTree<T>::Position& p) {
  os << '[';
  if (!p.isExternal()){
    os << p.left();
  }
  os << ' ';
  os << *(Position(p));
  os << ' ';
  if (!p.isExternal()) {
    os << p.right();
  }
  os << ']';
	
  return os;
}
*/

#endif
