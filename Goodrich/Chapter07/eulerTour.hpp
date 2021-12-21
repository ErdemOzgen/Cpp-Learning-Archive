#ifndef EULER_TOUR_HPP
#define EULER_TOUR_HPP

template <typename E, typename R> // element and result type
class EulerTour {
protected:
  struct Result {
    R leftResult;		// result from left tree
    R rightResult;		// result from right tree
    R finalResult;		// combined result
  };
  typedef Tree<E> BinaryTree;	// The tree, has to be modified
  typedef typename BinaryTree::Position Position; // Position in the tree
protected:
  const BinaryTree* tree;	// Pointer to the tree
public:
  void initialize(const BinaryTree& T) { tree = &T; }
protected:
  virtual void visitExternal(const Position& p, Result& r) const {}
  virtual void visitLeft(const Position& p, Result& r) const {}
  virtual void visitBelow(const Position& p, Result& r) const {}
  virtual void visitRight(const Position& p, Result& r) const {}
  Result initResult() const { return Result(); }
  R result(const Result& r) const { return r.finalResult; }
protected:
  R eulerTour(const Position& p) const;
};

template <typename E, typename R>
R EulerTour<E,R>::eulerTour(const Position& p) const {
  Result r = initResult();
  if (p.isExternal()) {
    visitExternal(p, r);
  } else {
    visitLeft(p, r);
    r.leftResult = eulerTour(p.left());
    visitBelow(p, r);
    r.rightResult = eulerTour(p.right());
    visitRight(p, r);
  }
  return Result(r);
}

#endif
