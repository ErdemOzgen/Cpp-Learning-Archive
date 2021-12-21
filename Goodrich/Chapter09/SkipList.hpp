/************************************************************
 * @file SkipList.hpp
 * @author Zafar Takhirov
 * @date Mar. 21, 2015
 *
 * @brief This file contains description of the Skip LIst.
 *
 * The file describes the skip list. The choice of the higher
 * stck levels are implemented using coin flip method - if
 * the random returned is even, it is pushed up a stack,
 * otherwise it is not.
 ***********************************************************/
#ifndef SKIP_LIST_HPP
#define SKIP_LIST_HPP

#include "SkipListEntry.hpp"
#include "exceptions.hpp"

/**
 * Skip List class with coin flip based hierarchy.
 *
 * The implementation of the current skip list is based on
 * coin flip strategy - entries in the higher levels are 
 * determined by the coinflip on the entries of the lower 
 * levels. That way expected number of entries at level 
 * @f$i@f$ is @f$\lceil n/2^i \rceil@f$, where @f$i=0@f$ 
 * is the bootom level which has all the values.
 * The space complexity is expected to be at O(n)
 *
 * @tparam K Key data type
 * @tparam V Value data type
 * @tparam H Hash comparator
 */
template <typename K, typename V>
class SkipList {
public:
  typedef SkipListEntry<K,V> Entry;	//!< @typedef key-value pair entry
  /** Iterator/Position class */
  class Iterator;
public:
  SkipList() {};

public:							// Navigation
  Iterator after(Iterator p) { return p.right(); }
  Iterator before(Iterator p) { return p.left(); }
  Iterator above(Iterator p) { return p.top(); }
  Iterator below(Iterator p) { return p.bottom(); }
private:
  int n;						// size
  
public: // Iterator class definition:
  class Iterator {
  private:
	
  };
  
};


#endif
