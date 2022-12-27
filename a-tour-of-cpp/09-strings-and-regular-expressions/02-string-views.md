A **string_view** is basically a (pointer, length) pair denoting a sequence of characters.
It gives access to a *contiguous sequence *of characters.

The characters can be stored in many possible ways, including:
  - std::string;
  - C-style string.


- A **string_view** is like a *pointer* or a *reference* in that it does not own the characters it points to.
- When returning a string_view, remember that it is very much like a pointer; it needs to point to something.
- One significant restriction of string_view is that it is a **read-only** view of its characters.
- The behavior of *out-of-range* access to a **string_view** is unspecified.
- If you want guaranteed range checking, use `at()`, which throws *out_of_range* for attempted *out-of-range* access.