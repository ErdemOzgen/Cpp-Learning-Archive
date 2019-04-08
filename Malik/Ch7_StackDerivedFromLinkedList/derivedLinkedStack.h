//Header file derivedLinkedStack.h

#ifndef H_derivedLinkedStack
#define H_derivedLinkedStack

#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

template<class Type>
class linkedStackType: public unorderedLinkedList<Type>
{
public:
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const Type& newItem);
    Type top() const;
    void pop();
};

template<class Type>
void linkedStackType<Type>::initializeStack()
{
    unorderedLinkedList<Type>::initializeList();
}

template<class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return unorderedLinkedList<Type>::isEmptyList();
}

template<class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

template<class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    unorderedLinkedList<Type>::insertFirst(newElement);
}

template<class Type>
Type linkedStackType<Type>::top() const
{
    return unorderedLinkedList<Type>::front();
}

template<class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;

    if (linkedListType<Type>::first != NULL)
    {
        temp = linkedListType<Type>::first;
        linkedListType<Type>::first = linkedListType<Type>::first->link;
        delete temp;
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

#endif
