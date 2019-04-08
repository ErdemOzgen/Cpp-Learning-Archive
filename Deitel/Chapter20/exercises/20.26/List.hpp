/*
 * =====================================================================================
 *
 *       Filename:  List.hpp
 *
 *    Description:  Exercise 20.06 - Concatenating Lists
 *
 *        Version:  1.0
 *        Created:  13/03/17 14:02:39
 *       Revision:  17/03/17 16:22:07
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

    void insert(ListNode<NODETYPE>*, const NODETYPE &);
    void insertAtFront(const NODETYPE &);
    void insertAtBack(const NODETYPE &);
    bool removeFromFront();
    bool removeFromBack();
    bool remove(const NODETYPE &);
    void concatenate(List<NODETYPE> &);
    // is List empty
    bool isEmpty() const { return firstPtr == 0; }
    void print() const;
    // print sz of list
    int size() const { return sz; }

    // return pointer to first node
    ListNode<NODETYPE>* begin() const { return firstPtr; }
    // return pointer to last node
    ListNode<NODETYPE>* end() const { return lastPtr; }

 private:
    ListNode<NODETYPE> *firstPtr;  // pointer to first node
    ListNode<NODETYPE> *lastPtr;   // pointer to last node

    int sz;

    // utility function to allocate new node
    ListNode<NODETYPE> *getNewNode(const NODETYPE &);
};
// default constructor
template <typename NODETYPE>
List<NODETYPE>::List() : firstPtr(0), lastPtr(0), sz(0) {}
// destructor
template <typename NODETYPE>
List<NODETYPE>::~List() {
    if (!isEmpty()) {
        ListNode<NODETYPE> *currentPtr = firstPtr;

        // delete remaining nodes
        while (currentPtr != 0) {
            ListNode<NODETYPE> *tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }
}

/**
 * Insert node after given ListNode.
 * @param ListNode<NODETYPE>*
 * @param NODETYPE&
 */
template <typename NODETYPE>
void List<NODETYPE>::insert(ListNode<NODETYPE>* position, const NODETYPE &value) {
    if (position == nullptr) { return; }

    ListNode<NODETYPE> *newPtr = getNewNode(value);

    newPtr->nextPtr = position->nextPtr;

    position->nextPtr = newPtr;

    ++sz;
}  // end method insert

// insert Node at front of list
template <typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &value) {
    ListNode<NODETYPE> *newPtr = getNewNode(value);

    if (isEmpty()) {
        firstPtr = lastPtr = newPtr;  // new list only has one node
    } else {
        newPtr->nextPtr = firstPtr;  // point new node to previous list node
        firstPtr = newPtr;
    }
    ++sz;
}
// insert node at back of list
template <typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &value) {
    ListNode<NODETYPE> *newPtr = getNewNode(value);

    if (isEmpty()) {
        firstPtr = lastPtr = newPtr;  // new list has only one node
    } else {
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
    }
    ++sz;
}
// delete node from front of list
template <typename NODETYPE>
bool List<NODETYPE>::removeFromFront() {
    if (isEmpty()) {  // list is empty
        return false;
    } else {
        ListNode<NODETYPE> *tempPtr = firstPtr;

        if (firstPtr == lastPtr) {
            firstPtr = lastPtr = 0;  // no nodes remain after removal
        } else {
            firstPtr = firstPtr->nextPtr;  // point to previous 2nd node
        }

        // value = tempPtr->data;
        delete tempPtr;

        --sz;

        return true;
    }
}
// delete node from back of list
template <typename NODETYPE>
bool List<NODETYPE>::removeFromBack() {
    if (isEmpty()) {  // list is empty
        return false;
    } else {
        ListNode<NODETYPE> *tempPtr = lastPtr;

        if (firstPtr == lastPtr) {   // list has one element
            firstPtr = lastPtr = 0;  // no nodes remain after removal
        } else {
            ListNode<NODETYPE> *currentPtr = firstPtr;

            // locate second to last element
            while (currentPtr->nextPtr != lastPtr) {
                currentPtr = currentPtr->nextPtr;  // move to next node
            }

            lastPtr = currentPtr;     // remove last node
            currentPtr->nextPtr = 0;  // this is now the last node
        }

        // value = tempPtr->data;
        delete tempPtr;

        --sz;
        return true;
    }
}

/**
 * Removes the given node from the list.
 * @param NODETYPE&
 * @return bool
 */
template <typename NODETYPE>
bool List<NODETYPE>::remove(const NODETYPE &value) {
    if (begin()->getData() == value) { return removeFromFront(); }
    if (end()->getData() == value) { return removeFromBack(); }

    ListNode<NODETYPE>* prevNode = begin();
    ListNode<NODETYPE>* nextNode;

    // set prevNode to node before value to be deleted.
    while (prevNode != end()) {
        if (prevNode->next()->getData() == value) { break; }
        prevNode = prevNode->next();
    }

    // value not found
    if (prevNode == end()) { return false; }

    // set nextNode to node after value to be deleted
    nextNode = prevNode->next()->next();

    ListNode<NODETYPE>* current = prevNode->next();

    delete current;

    prevNode->nextPtr = nextNode;

    --sz;

    return true;

}  // end method remove

// concatenate new list to end of list
template <typename NODETYPE>
void List<NODETYPE>::concatenate(List<NODETYPE> &listSecond) {
    ListNode<NODETYPE> *currentPtr = listSecond.firstPtr;

    while (currentPtr != 0) {
        insertAtBack(currentPtr->getData());
        currentPtr = currentPtr->nextPtr;
    }
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

    while (currentPtr != 0) {
        std::cout << currentPtr->getData() << ' ';
        currentPtr = currentPtr->nextPtr;
    }
    std::cout << std::endl;
}
