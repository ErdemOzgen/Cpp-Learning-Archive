
#pragma once

template <typename T>
class Stack {
 public:
    explicit Stack(int = 10);  // default constructor (Stack size 10)
    ~Stack() {
        delete[] stackPtr;  // deallocate internal space for Stack
    }

    bool push(const T&);  // push an element onto the Stack
    bool pop(T&);         // pop an element off the Stack

    // determine whether Stack is empty
    bool isEmpty() const { return top == -1; }

    // determine whether Stack is full
    bool isFull() const { return top == size - 1; }

 private:
    int size;     // # of elements in the Stack
    int top;      // location of the top element (-1 means empty)
    T* stackPtr;  // pointer to internal representation of Stack
};

// constructor template
template <typename T>
Stack<T>::Stack(int s)
    : size(s > 0 ? s : 10),  // validate size
      top(-1),               // Stack initially empty
      stackPtr(new T[size])  // allocate memory for elements
{}
// push element onto Stack
// if successful return true; otherwise false
template <typename T>
bool Stack<T>::push(const T& pushValue) {
    if (!isFull()) {
        stackPtr[++top] = pushValue;  // place item onto Stack
        return true;
    }
    return false;
}
// pop element off of Stack
// if successful return true; otherwise false
template <typename T>
bool Stack<T>::pop(T& popValue) {
    if (!isEmpty()) {
        popValue = stackPtr[top--];  // remove item from Stack
        return true;
    }
    return false;
}
