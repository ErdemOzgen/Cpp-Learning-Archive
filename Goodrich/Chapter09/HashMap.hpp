/************************************************************
 * @file HashMap.hpp
 * @author Zafar Takhirov
 * @date Feb. 28, 2015
 * @page
 *
 * @brief This file contains description of the Hash Map using separate chaining.
 *
 * This file contains hash map ADT using separate chaining.
 * It contains full working example from the book by
 * Goodrich and Tamassia "Data Structures and Algorithms
 * in C++
 * 
 * This is a test modification for GIT
 ***********************************************************/

#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <list>
#include <vector>

#include "MapEntry.hpp"
#include "exceptions.hpp"

/**
 * HashMap class with separate chaining.
 * The hash map is templated with 3 parameters:
 * @param K Key data type
 * @param V Value data type
 * @param H Hash comparator
 */
template <typename K, typename V, typename H>
class HashMap {
public:
  typedef Entry<K,V> Entry;	//!< @typedef key-value pair entry
  /** Iterator/Position class */
  class Iterator;		
public:
  HashMap (		     
    int capacity = 100		//!< Initial capacity of the hash map.
  );
  int size() const;
  bool empty() const;		
  Iterator find(const K& k);	// Find key
  Iterator put(
	       const K& k,			// [in] Key to be added
	       const V& v			// [in] Value to be added
	       ); // Add/Replace key-value pair @retval Iterator Position of the added/replaced pair 
  void erase(const K& k) throw (NonexistentElement);	// Remove usign key
  void erase(const Iterator& p);  // Remove using position iterator
  Iterator begin();		
  Iterator end();		
protected:
  /**
   * @typedef Bucket
   * @typedef BktArray
   */
  typedef std::list<Entry> Bucket;      //!< Bucket of entries
  typedef std::vector<Bucket> BktArray; //!< Bucket array
protected:
  Iterator finder(const K& k);	// Find utility
  Iterator inserter(
    const Iterator& p,			// [in] Position to be inserted at
    const Entry& e				// [in] Value to be inserted
  ); // Insert utility @retval Iterator Position of the value in the hash map
  void eraser(const Iterator& p); // Eraser utility
  /**
   * @typedef BItor
   * @typedef EItor
   */
  typedef typename BktArray::iterator BItor; //!< Bucket iterator
  typedef typename Bucket::iterator EItor;   //!< Entry iterator
  static void nextEntry(Iterator& p		/**< [in] Current position */)
  { ++p.ent; }							//!< Bucket's next entry
  static bool endOfBkt(const Iterator& p /**< [in] Current position */)
  { return p.ent == p.bkt->end(); }		 //!< end of bucket????
private:
  int n;						// @var Number of entries
  H hash;						// @var the hash comparator;
  BktArray B;					//!< @var bucket array
public:
  /** Iterator class identifies the position of an entry in a HashMap. */
  class Iterator {
  private:
    EItor ent;			//!< @var which entry
    BItor bkt;			//!< @var which bucket
    const BktArray* ba;	//!< @var which bucket array
  public:
    /** Default Iterator constructor.
     * @param a Bucket array
     * @param b Bucket itself
     * @param q Current entry, defaults to Entry iterator
     */
    Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
      : ent(q), bkt(b), ba(&a) { }
    Entry& operator*() const;		      
    Entry& operator*();			      
    bool operator==(const Iterator& p) const;
    Iterator& operator++();		      
    friend class HashMap; //!< Hash Map has to be a friend class to have access to internals
  };
};

/** @addtogroup iteratorGroup Iterator methods and declarations
 * @{
 */

/** Iterator indirection operator (const).
 * @returns Entry
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry&
HashMap<K,V,H>::Iterator::operator*() const {
  return *ent;
}

/** Iterator indirection operator.
 * @returns Entry
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry&
HashMap<K,V,H>::Iterator::operator*() {
  return *ent;
}

/** Iterator equality operator overloading.
 * @returns Boolean
 */
template <typename K, typename V, typename H>
bool HashMap<K,V,H>::Iterator::operator==(const Iterator& p) const {
  if (ba != p.ba || bkt != p.bkt) return false;
  else if (bkt == ba->end()) return true;
  else return ent == p.ent;
}

/** Iterator position increment operator overloading.
 * @returns Iterator
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator&
HashMap<K,V,H>::Iterator::operator++() {
  ++ent;			// Advance to the next entry in the bucket
  if (endOfBkt(*this)) {	// Is it the end of bucket?
    ++bkt;			// Go to next bucket
    while (bkt != ba->end() && bkt->empty) ++bkt; // find non-empty bucket
    if (bkt == ba->end()) return *this;		  // If the end of bucket array
    ent = bkt.begin();				  // first non empty bucket
  }
  return *this;  
}
/** @} */

/** @addtogroup hashMapMethodsGroup Hash Map member methods
 * @{
 */

/** First position 
 * @retval Iterator Position of the first entry
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::begin() {
  if (empty()) return end();	// Empty? return end
  BItor bkt = B.begin();	// otherwise search for an entry
  while (bkt->empty()) ++bkt;	// find non-empty bucket
  return Iterator(B, bkt, bkt->begin()); // return first bucket
}

/** End position
 * @retval Iterator Position after the last entry
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::end() {
  return Iterator(B, B.end());
}

/** Default constructor.
 * Sets n(0) and B(capacity)
 */
template <typename K, typename V, typename H>
HashMap<K,V,H>::HashMap(int capacity) : n(0), B(capacity) {}

/** Number of entries 
 * @returns Integer 
 */
template <typename K, typename V, typename H>
int HashMap<K,V,H>::size() const { return n; }

/** Check if empty 
 * @returns Boolean
 */
template <typename K, typename V, typename H>
bool HashMap<K,V,H>::empty() const { return size() == 0; }

/** Finder utility
 *
 * Operation:
 * -# Apply hash funcion on the key modulo array size
 * -# Add index to the beginning iterator (bkt)
 * -# Create iterator p initialized to the beginning og the bkt 
 * -# Run a while loop looking for the key
 * 
 * @param[in] k Key to be found
 * @retval Iterator Position that was found
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::finder(const K& k) {
  int i = // hash(k) % B.size();	// get hash index i
	H(k) % B.size();	// get hash index i
  BItor bkt = B.begin() + i;	// the ith bucket
  Iterator p(B, bkt, bkt->begin()); // start of ith bucket
  while (!endOfBkt(p) && (*p).key() != k) // search for k
	nextEntry(p);
  return p;						// return final position
}

/** Find key method.
 * 
 * Uses HashMap::finder() utility to search for a key.
 * @param[in] k Key to be found
 * @retval Iterator Position of the found key
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::find(const K& k) {
  Iterator p = finder(k);
  if (endOfBkt(p))
	return end();
  else
	return p;
}

/** Inserter utility
 * 
 * It invokes the STL list insert function to perform the insertion.
 * It also increments the count of the number of entries in the map
 * and returns an iterator to the insertion position
 * @param[in] p HashMap::Iterator / Position where the entry would be put
 * @param[in] e Entry to be inserted
 * @retval Iterator Position where the entry was put
 * @see HashMap::put
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::inserter(const Iterator& p, const Entry& e) {
  EItor ins = p.bkt->insert(p.ent, e); // insert before p
  n++;								   // One more entry
  return Iterator(B, p.bkt, ins);	   // return the position
}

/** Put key-value pair method
 *
 * Operation:
 * - Search for key in the map using HashMap::finder
 *   - If __not__ found, insert in the end of the bucket
 *   - Otherwise, replace the value of the found key with the new value
 *
 * @param[in] k Key to be added/replaces
 * @param[in] v New value
 * @retval Iterator Position of the key-value pair in the hash map
 * @see HashMap::inserter
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::put(const K& k, const V& v) {
  Iterator p = finder(k);
  if (endOfBkt(p)) {
	return inserter(p, Entry(k,v));
  } else {
	p.ent->setValue(v);
	return p;
  }
}

/** Eraser utility.
 *
 * Removes an entry at a given position by invoking the 
 * STL list erase function.
 * @param[in] p Position to be erased
 * @see erase(const Iterator& p)
 * @see erase(const K& k)
 */
template <typename K, typename V, typename H>
void HashMap<K,V,H>::eraser(const Iterator& p) {
  p.bkt->erase(p.ent);
  n--;
}

/** Erase method (using position)
 *
 * @param[in] p Position of an entry to be erased
 * @see eraser 
 * @see erase(const K& p)
 */
template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const Iterator& p) {
  eraser(p);
}

/** Erase method (using key)
 *
 * Operation:
 * -# Apply the finder utility to look up the key
 * -# if not found, throw an error
 * -# otherwise erase
 *
 * @throws NonexistentElement
 * @param[in] k Key of an entry to be erased
 * @see eraser 
 * @see erase(const Iterator& p)
 */
template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const K& k) throw (NonexistentElement) {
  Iterator p = finder(k);
  if (endOfBkt(p))
	throw NonexistentElement("Erase of nonexistent");
  eraser(p);
}
/** @} */

#endif
