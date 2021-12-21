#ifndef _SKIP_LIST_NODE_HPP_
#define _SKIP_LIST_NODE_HPP_

template<class T>
class SkipListNode {
public:
  SkipListNode(
			   const T& item = 0,
			   SkipListNode<T>* t = NULL,
			   SkipListNode<T>* b = NULL,
			   SkipListNode<T>* l = NULL,
			   SkipListNode<T>* r = NULL) {
	data = item;
	_top = t;
	_bottom = b;
	_left = l;
	_right = r;
  }
  // access to the other nodes
  SkipListNode<T>* top() { return _top; }
  SkipListNode<T>* bottom() { return _bottom; }
  SkipListNode<T>* left() { return _left; }
  SkipListNode<T>* right() { return _right; }
private:
  T data;
  SkipListNode<T>* _top;
  SkipListNode<T>* _bottom;
  SkipListNode<T>* _left;
  SkipListNode<T>* _right;
};

template <typename T>

#endif
