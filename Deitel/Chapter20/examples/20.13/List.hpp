/*
 * =====================================================================================
 *
 *       Filename:  List.h
 *
 *    Description:  Fig. 20.4 - Template List Class Definition
 *
 *        Version:  1.0
 *        Created:  13/03/17 14:02:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include <iostream>
#include "ListNode.hpp"

template <typename NODETYPE>
class List {
 public:
    List();
    ~List();

    void insertAtFront(const NODETYPE &);
    void insertAtBack(const NODETYPE &);
    bool removeFromFront(NODETYPE &);
    bool removeFromBack(NODETYPE &);
    bool isEmpty() const;
    void print() const;

 private:
    ListNode<NODETYPE> *firstPtr;  // pointer to first node
    ListNode<NODETYPE> *lastPtr;   // pointer to last node

    // utility function to allocate new node
    ListNode<NODETYPE> *getNewNode(const NODETYPE &);
};
// default constructor
template <typename NODETYPE>
List<NODETYPE>::List() : firstPtr(0), lastPtr(0) {}
// destructor
template <typename NODETYPE>
List<NODETYPE>::~List() {
    if (!isEmpty()) {
        std::cout << "Destroying Nodes...\n";
        ListNode<NODETYPE> *currentPtr = firstPtr;

        // delete remaining nodes
        while (currentPtr != 0) {
            ListNode<NODETYPE> *tempPtr = currentPtr;
            std::cout << tempPtr->data << '\n';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }
}
// insert Node at front of list
template <typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &value) {
    ListNode<NODETYPE> *newPtr = getNewNode(value);

    if (isEmpty())
        firstPtr = lastPtr = newPtr;  // new list only has one node
    else {
        newPtr->nextPtr = firstPtr;  // point new node to previous list node
        firstPtr = newPtr;
    }
}
// insert node at back of list
template <typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &value) {
    ListNode<NODETYPE> *newPtr = getNewNode(value);

    if (isEmpty())
        firstPtr = lastPtr = newPtr;  // new list has only one node
    else {
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
    }
}
// delete node from front of list
template <typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &value) {
    if (isEmpty())  // list is empty
        return false;
    else {
        ListNode<NODETYPE> *tempPtr = firstPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;  // no nodes remain after removal
        else
            firstPtr = firstPtr->nextPtr;  // point to previous 2nd node

        value = tempPtr->data;
        delete tempPtr;

        return true;
    }
}
// delete node from back of list
template <typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &value) {
    if (isEmpty())  // list is empty
        return false;
    else {
        ListNode<NODETYPE> *tempPtr = lastPtr;

        if (firstPtr == lastPtr)     // list has one element
            firstPtr = lastPtr = 0;  // no nodes remain after removal
        else {
            ListNode<NODETYPE> *currentPtr = firstPtr;

            // locate second to last element
            while (currentPtr->nextPtr != lastPtr)
                currentPtr = currentPtr->nextPtr;  // move to next node

            lastPtr = currentPtr;     // remove last node
            currentPtr->nextPtr = 0;  // this is now the last node
        }

        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}
// is List empty
template <typename NODETYPE>
bool List<NODETYPE>::isEmpty() const {
    return firstPtr == 0;
}
// return pointer to newly allocated node
template <typename NODETYPE>
ListNode<NODETYPE> *List<NODETYPE>::getNewNode(const NODETYPE &value) {
    return new ListNode<NODETYPE>(value);
}
// display contents of List
template <typename NODETYPE>
void List<NODETYPE>::print() const {
    if (isEmpty()) {
        std::cout << "The list is empty\n\n";
        return;
    }

    ListNode<NODETYPE> *currentPtr = firstPtr;

    std::cout << "The list is: ";

    while (currentPtr != 0) {
        std::cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextPtr;
    }

    std::cout << "\n\n";
}
