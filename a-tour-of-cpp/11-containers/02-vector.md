- When you *insert* a new element, its value is **copied** into the container.
- This makes for nice, compact containers with fast access.
- However, for people who care about memory sizes and run-time performance this is **critical**.

- If you have a *class hierarchy* that relies on `virtual` functions to get polymorphic behavior
- or if you class is considerably large
- **DO NOT store objects directly in a container.**
- Instead, store a pointer (or a smart pointer;).

- Just be careful when using *smart_pointers*, because vector must have the **ownership** of the pointer.
- **Then, vector deallocates the elements automatically when it is deallocated.**
