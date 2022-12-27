What are **iterators really?**
- Any particular iterator is an object of some type.
- What is common for all iterators is their semantics and the naming of their operations.
    - applying `++` to any **iterator** yields an iterator that refers to the **next element**.
    - Similarly, `*` yields the element to which the **iterator refers**.
        - In fact, any object that obeys a few simple rules like these is an iterator (Iterator is a concept)
    - Furthermore, users *rarely* need to know the **type** of a specific iterator;
        - each container *“knows”* its iterator types and makes them available under the conventional names iterator and const_iterator .