#ifndef MAP_ENTRY_HPP
#define MAP_ENTRY_HPP

/** Entry data struct.
 * Entry data structure for keeping the key and
 * value of a hash map.
 */
template <typename K, typename V>
class Entry {
public:
  /** Default constructor */
  Entry(
	const K& k = K(),	//!< [in] Key
	const V& v = V()	//!< [in] Value
	) : _key(k), _value(v) { }
  const K& key() const { return _key; }	    //!< Get key @retval K& Internal key
  const V& value() const { return _value; } //!< Get value @retval V& Internal value
  void setKey(const K& k) { _key = k; }	    //!< Set key @param[in] k New key value
  void setValue(const V& v) { _value = v; } //!< Set value @param[in] v New value
private:
  K _key;				    //!< @var key
  V _value;				    //!< @var value
};
  
#endif
