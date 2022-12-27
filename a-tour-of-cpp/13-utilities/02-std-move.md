### ``std::move()``
- The choice between moving and copying is mostly **implicit**
- A compiler will prefer to **move** when an object is about to be **destroyed** (as in a return )
    - *because that’s assumed to be the simpler and more efficient operation.*
- However, sometimes we must be explicit.

```
void f1() {
    auto p = make_unique<int>(2);
    auto q = p; // error: we can't copy a unique_ptr
    // ...
}


void f2() {
    auto p = make_unique<int>(2);
    auto q = move(p); // p now holds nullptr
    
    cout << p; // crash... p does not have its value anymore.
    // ...
}
```

- I consider this use of `std::move()` to be too **error-prone** for widespread use.
- **Don’t use it** unless you can demonstrate significant and necessary *performance improvement*.
- Later maintenance may accidentally lead to unanticipated use of the moved-from object.

