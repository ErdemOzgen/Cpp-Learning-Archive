- `unordered_map` is the standard-library hashed containers (hash tables, hashed lookup);
- They are referred to as ***unordered*** because they **don’t require an ordering function*;

- STL provides a *default hash function* for `strings` as well as for other built-in and standard-library types.
- If necessary, you can provide your own.

- Possibly, the most common need for a *“custom” hash function* comes when we want an **unordered container** of one of our own types.
- A *hash function* is often provided as a **function object (functor)**

```
struct Record {
    string name;
    int product_code;
    // ...
};

// function object / functor
struct Rhash { // a hash function for Record
    size_t operator()(const Record& r) const {
        return hash<string>()(r.name) ^ hash<int>()(r.product_code);
    }
};


unordered_set<Record,Rhash> my_set; // set of Records using Rhash for lookup
```

- We can avoid *explicitly passing* the **hash operation** by defining it
as a specialization of the standard-library `hash`
```
namespace std { // make a hash function for Record
template<> struct hash<Record> {
    using argument_type = Record;
    using result_type = std::size_t;
    
    size_t operator()(const Record& r) const {
        return hash<string>()(r.name) ^ hash<int>()(r.product_code);
    }
};
}
```

Note the differences between a `map` and an `unordered_map`:
- A `map` requires an **ordering function** (the default is `<`) and yields an **ordered sequence**
- A `unordered_map` requires a **hash function** and **does not maintain an order among its elements**.

Given a good hash function, an `unordered_map` is *much faster* than a `map` for large containers.
However, the worst-case behavior of an `unordered_map` with a *poor hash function* is far worse than that of a `map`.
