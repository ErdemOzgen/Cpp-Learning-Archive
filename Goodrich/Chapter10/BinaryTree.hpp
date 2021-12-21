#ifndef __BINARY_TREE_HPP__
#define __BINARY_TREE_HPP__

#include <list>
// #include <exception>

/** Binary tree ADT
 *
 * @tparam E The type of the elements in the tree
 *
 * @warning There are no housekeeping functions
 * @todo Finish up the housekeeping functions: destructor, copy constructor, assignment operator
 *
 * @warning There are no exceptions here
 * @todo Throw exceptions if out of bounds, etc...
 */
template <typename E>
class BinaryTree {
protected:
  struct Node {
	E elt;						//!< Element value
	Node* par;					//!< parent
	Node* left;					//!< left
	Node* right;				//!< right child
	Node() : elt(), par(NULL), left(NULL), right(NULL) {}
  };
public:
  class Position {
  private:
	Node* v;
  public:
	Position(Node* _v = NULL) : v(_v) { } //!< Constructor
	E& operator*() { return v->elt; }	  //!< Get element
	Position left() const { return Position(v->left); } //!< Get left child
	Position right() const { return Position(v->right); } //!< Get right child
	Position parent() const { return Position(v->par); }  //!< Get parent
	bool isRoot() const			//! is root node?
	{ return v->par == NULL && v->right == NULL; }
	bool isExternal() const		//! an external node?
	{ return v->left == NULL && v->right == NULL; }
	bool isInternal() const
	{ return !isExternal(); }
	friend class BinaryTree;	//!< get tree access
  };
  typedef std::list<Position> PositionList; //!< list of positions

public:
  BinaryTree();					//!< constructor
  int size() const;				//!< number of nodes
  bool empty() const;			//!< is tree empty?
  Position root() const;		//!< get the root
  PositionList positions() const; //!< list of nodes
  void addRoot();				  //!< add root to empty tree
  void expandExternal(const Position& p); //!< expand external node
  Position removeAboveExternal(const Position& p); //!< remove p and parent
  // housekeeping functions
  
protected:
  void preorder(Node* v, PositionList& pl) const; //!< preorder utility
private:
  Node* _root;					//!< Pointer to the root
  int n;						//!< number of nodes
};


template <typename E> BinaryTree<E>::BinaryTree() : _root(NULL), n(0) {}
template <typename E> int BinaryTree<E>::size() const { return n; }
template <typename E> bool BinaryTree<E>::empty() const { return size() == 0; }
template <typename E> typename BinaryTree<E>::Position BinaryTree<E>::root() const { return Position(_root); }
template <typename E> void BinaryTree<E>::addRoot() { _root = new Node; n = 1; }

template <typename E>
void BinaryTree<E>::expandExternal(const Position& p) {
  Node* v = p.v;
  v->left = new Node;
  v->left->par = v;
  v->right = new Node;
  v->right->par = v;
  n += 2;
}

/** Removes node and its parent
 *
 * @param p Node to be removed
 */
template <typename E>
typename BinaryTree<E>::Position BinaryTree<E>::removeAboveExternal(const Position& p) {
  Node* w = p.v;
  Node* v = w->par; // get p's node and parent
  Node* sib = (w == v->left ? v->right : v->left);
  if (v == _root) {
	_root = sib;
	sib->par = NULL;
  } else {
	Node* gpar = v->par;
	if (v == gpar->left) gpar->left = sib;
	else gpar->right = sib;
	sib->par = gpar;
  }
  delete w; delete v;
  n -= 2;
  return Position(sib);
}

template <typename E>
typename BinaryTree<E>::PositionList BinaryTree<E>::positions() const {
  PositionList pl;
  preorder(_root, pl);
  return PositionList(pl);
}

template <typename E>
void BinaryTree<E>::preorder(Node* v, PositionList& pl) const {
  pl.push_back(Position(v));	// Add this node
  if (v->left != NULL) preorder(v->left, pl); // Traverse left subtree
  if (v->right != NULL) preorder (v->right, pl); // Traverse the other subtree
  
}

#endif
