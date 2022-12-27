#### Specialized Containers
-` T[N]`: Built-in array: a fixed-size continuously allocated sequence of `N` elements of type `T`; implicitly converts to a `T*`
- `array<T, N>`: A fixed-size continuously allocated sequence of `N` elements of type `T`; like the built-in array, but with most problems solved
- `bitset<N>`: A fixed-size sequence of `N` bits
- `vector<bool>`: A sequence of bits compactly stored in a specialization of `vector`
- `pair<T, U>`: Two elements of types `T` and `U`
- `tuple<T...>`: A sequence of an arbitrary number of elements of arbitrary types
- `basic_string<C>`: A sequence of characters of type C ; provides string operations
- `valarray<T>`: An array of numeric values of type T ; provides numeric operations
