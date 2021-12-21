#ifndef SKIP_LIST_ENTRY_HPP
#define SKIP_LIST_ENTRY_HPP

/** Entry data struct.
 * Entry data structure for keeping the key and
 * value of a skip list.
 */
template <typename K, typename V>
class SkipListEntry {
public:
  /** Default constructor */
  SkipListEntry(
    const K& k = K(),	//!< [in] Key
	const V& v = V(),	//!< [in] Value
	const SkipListEntry<K,V>& l = NULL,
	const SkipListEntry<K,V>& r = NULL,
	const SkipListEntry<K,V>& t = NULL,
	const SkipListEntry<K,V>& b = NULL
  ) : _key(k), _value(v), _left(l), _right(r), _top(t), _bottom(b) { }
  const K& key() const { return _key; }	    //!< Get key @retval K& Internal key
  const V& value() const { return _value; } //!< Get value @retval V& Internal value
  void setKey(const K& k) { _key = k; }	    //!< Set key @param[in] k New key value
  void setValue(const V& v) { _value = v; } //!< Set value @param[in] v New value
public:
  // Naviagation:
  SkipListEntry<K,V>* left () { return _left; }
  SkipListEntry<K,V>* right () { return _right; }
  SkipListEntry<K,V>* top () { return _top; }
  SkipListEntry<K,V>* bottom () { return _bottom; }
private:
  K _key;				    //!< @var key
  V _value;				    //!< @var value
  SkipListEntry<K,V>* _left;
  SkipListEntry<K,V>* _right;
  SkipListEntry<K,V>* _top;
  SkipListEntry<K,V>* _bottom;
};

#endif
