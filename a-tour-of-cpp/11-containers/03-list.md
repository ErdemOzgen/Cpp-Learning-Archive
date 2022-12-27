- The standard library offers a doubly-linked list called `list`

- When all we want is a *sequence of elements*, we have a choice between using a `vector` and a `list`
**- Unless you have a reason not to, use a `vector`.**
- A vector performs better for *traversal* (e.g., `find()` and `count()`) and
- for *sorting* and *searching* (e.g., `sort()` and `equal_range()`

- The standard library also offers a **singly-linked** list called `forward_list`: