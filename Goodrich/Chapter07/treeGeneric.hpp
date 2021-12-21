#ifndef GENERIC_TREE_HPP
#define GENERIC_TREE_HPP

#include "exceptions.hpp"

#include <list>			// Need that for position list in linked binary tree
#include <vector>		// Need that for vector-based binary tree

/** Properties of a binary tree **/
/*
 * 1. h + 1 <= n <= 2^(h+1) - 1
 * 2. 1 <= nE <= 2^h
 * 3. h <= nI <= 2^h - 1
 * 4. log(n+1) - 1 <= h <= n - 1
 */

// Binary tree using linked lists (sorta)
template <typename T>
class LinkedBinaryTree {
protected:
  // Basic node:
  struct Node {
    T elt;
    Node* par;
    Node* left;
    Node* right;
    Node() : elt(), par(NULL), left(NULL), right(NULL) {}
  };
public:
  // Position of the node:
  class Position {
  private:
    Node* v;
  public:
    Position(Node* _v = NULL) : v(_v) {}
    T& operator*() { return v->elt; }
    Position left() const { return Position(v->left); }
    Position right() const { return Position(v->right); }
    Position parent() const { return Position(v->parent); }
    bool isRoot() const { return v->par == NULL; }
    bool isExternal() const { return v->left == NULL && v->right == NULL; }
    friend class LinkedBinaryTree;
  };
  typedef std::list<Position> PositionList; // list of all positions
public:
  LinkedBinaryTree();
  int size() const;		// Number of nodes
  bool empty() const;		// Check if empty
  Position root() const;	// get the root
  PositionList positions() const; // list of all the nodes
  void addRoot();		  // add root (exception if not empty)
  void expandExternal(const Position& p) // expand external node
    throw (NodeNotExternalException);
  Position removeAboveExternal(const Position& p) // remove p and its parent
    throw (NodeNotExternalException);
public:
  /* Put housekeeping here */
protected:
  void preorder(Node* v, PositionList& pl) const; // Preorder traversal
private:
  Node* _root;
  int n;
};

template <typename T>
LinkedBinaryTree<T>::LinkedBinaryTree() : _root(NULL), n(0) {}

template <typename T>
int LinkedBinaryTree<T>::size() const { return n; }

template <typename T>
bool LinkedBinaryTree<T>::empty() const { return size() == 0; }

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::root() const {
  return Position(_root);
}

template <typename T>
void LinkedBinaryTree<T>::addRoot() { _root = new Node; n = 1; }

// Transform p from an external node into an internal node
// by creating two new external nodes and making them the
// left and right children of p, respectively; an error
// condition occurs if p is an internal node.
template <typename T>
void LinkedBinaryTree<T>::expandExternal(const Position& p)
  throw (NodeNotExternalException)
{
  if (!p.isExternal()) {
    throw NodeNotExternalException("Node is not external to expand it!");
  }

  Node* v = p.v;
  v->left = new Node;
  v->left->par = v;
  v->right = new Node;
  v->right->par = v;
  n += 2;
}

// Remove the external node p together with its parent q,
// replacing q with the sibling of p
// an error condition occurs if p is an internal node or p is the root.
template <typename T>
typename LinkedBinaryTree<T>::Position
LinkedBinaryTree<T>::removeAboveExternal(const Position& p)
  throw (NodeNotExternalException)
{
  if (!p.isExternal() || p.isRoot()) {
    throw NodeNotExternalException("Node has to be external (non-root)!");
  }
  Node* w = p.v; Node* v = w->par; // get p and the parent
  Node* sib = (w == v->left ? v->right : v->left);
  if (v == _root) {		// daddy is the root?
    _root = sib;		// make the other kid a daddy
    sib->par = NULL;
  } else {
    Node* gpar = v->par;	// w's (aka p's) granny
    if (v == gpar->left) gpar->left = sib; // if we are left, replace
    else gpar->right = sib;		   // if we are right replace as well
    sib->par = gpar;			   // granny is now a daddy (sick)
  }
  delete w; delete v;		// clear trash
  n-=2;				// lost two members of the tree
  return Position(sib);
}

template <typename T>
typename LinkedBinaryTree<T>::PositionList
LinkedBinaryTree<T>::positions() const {
  PositionList pl;
  preorder(_root, pl);
  return PositionList(pl);
}

template <typename T>
void LinkedBinaryTree<T>::preorder(Node* v, PositionList& pl) const {
  pl.push_back(Position(v));
  if (v->left != NULL)
    preorder(v->left, pl);
  if (v->right != NULL)
    preorder(v->right,pl);
}


/********************************************************************************/
template <typename T>
class VectorBinaryTree {
public:
  typedef T* Position;
public:
  VectorBinaryTree();
  std::size_t size() const;
  bool empty() const;
  Position root() const { return Position(positions.at(0)); }
  //  Position left() const { return 
  
private:
  // Root is implied as tje first element;
  std::vector<T> positions;		// Vector with all the elements
  // std::size_t n;		// Size of the tree
};

template <typename T>
VectorBinaryTree<T>::VectorBinaryTree() {
  positions = std::vector<T>();
}

#endif
