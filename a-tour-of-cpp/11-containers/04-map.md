- The standard library offers a *balanced binary search tree* (usually, a *red-black tree*) called `map`
- It is a container of **pairs of values** optimized for lookup.
- We can use the same initializer as for vector and list

```
map<string,int> phone_book {
    {"David Hume",123456},
    {"Karl Popper",234567},
    {"Bertrand Arthur William Russell",345678}
};


int get_number(const string& s) {
    return phone_book[s]; // access the value based on the key s
}
```

- `map` is essentially the **lookup** we called the function above `get_number()`
- If a key isn’t found, it is entered into the map with a **default value** for its value
- The **default value** for an *integer type* is 0;

- The cost of a map lookup is *O(log(n))* where n is the number of elements in the map.