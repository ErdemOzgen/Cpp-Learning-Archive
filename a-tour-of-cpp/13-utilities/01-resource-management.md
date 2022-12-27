### Resource Management

- To work with objects allocated in the *free store*, STL provides two *“smart pointers”* to help
manage objects (automatically deallocation):
- `unique_ptr` to represent unique ownership
- `shared_ptr` to represent shared ownership

The most basic use of these *“smart pointers”* is to **prevent memory leaks** caused by
careless programming (lack of deallocating the objects on free store).

```
void f(int i, int j) {
    X* ptr = new X; // allocate a new X on free store
    unique_ptr<X> smart_ptr {new X}; // allocate a new X on free store and give its pointer to unique_ptr
    // ...
    
    if (i < 99)
        throw some_exception();
    
    if (j < 100)
        return;
    
    delete ptr; // destroy ptr
}
```

- We forgot to delete `ptr` when `i < 99` and `j < 100`. Thus, we have a **memory leak** for these situations.
- On the other hand, the *smart pointer* `smart_ptr` automatically deallocates the resource memory
at the end of the scope (lifetime of it). Thus, we **don't** have memory leak.
- However, avoid **pointers**: prefer to use local variables instead;

When you really need the semantics of pointers:
- `unique_ptr` is a *very lightweight mechanism* with no space or
time overhead compared to correct use of a built-in pointer.
- Its further uses include passing *free-store* allocated objects in
and out of functions.
- `unique_ptr` is a handle to an individual object (or an array) that:
    - controls the lifetime of other objects (using RAII);
    - relies on move semantics to make return simple and efficient.

Concerning `shared_ptr`:
- It is similar to `unique_ptr except that it is **copied** rather than *moved*.
- Multiple `shared_ptr`s for an object share ownership of the object;
- that object is **destroyed** when the **last** of its `shared_ptr`s is destroyed.
- Use `shared_ptr` **only** if you actually need **shared** ownership.

Additional functions:
```
struct S {
    int i;
    string s;
    double d;
    // ...
}

auto p1 = make_shared<S>(1, "Ankh Morpork", 4.65); // p1 is a shared_ptr<S>
auto p2 = make_unique<S>(2,"Oz",7.62); // p2 is a unique_ptr<S>
```

- Using `make_shared()` is not just more convenient than separately making
an object using `new` and then passing it to a `shared_ptr`
- it is also notably **more efficient**
    - because it **does not need** a separate allocation for the use count that is essential in the implementation of a shared_ptr .
- Given `unique_ptr` and `shared_ptr`, we can implement a complete **“no naked `new`”** policy for many programs.
- However, these *“smart pointers”* are still conceptually *pointers*
    - it should be our second choice for management
    - **prefer containers and other types that manage their resources at a higher conceptual level.**
    

Where do we use *“smart pointers”* (such as `unique_ptr`) rather than resource handles with operations designed
specifically for the resource?
- When we share an object, we need pointers (or references) to refer to the shared object,
so a `shared_ptr` becomes the obvious choice (unless there is an obvious single owner).
- When we refer to a polymorphic object in classical object-oriented code,
we need a pointer (or a reference) because we don’t know the exact type of the object referred to
(or even its size), so `a unique_ptr` becomes the obvious choice.
- A shared polymorphic object typically requires `shared_ptr`.

