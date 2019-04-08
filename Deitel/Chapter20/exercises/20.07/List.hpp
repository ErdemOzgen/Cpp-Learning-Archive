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

    void insertAtFront(const NODETYPE &);
    void insertAtBack(const NODETYPE &);
    bool removeFromFront(NODETYPE &);
    bool removeFromBack(NODETYPE &);
    void concatenate(List<NODETYPE> &);
    List<NODETYPE> merge(List<NODETYPE>&);
    bool isEmpty() const;
    void print() const;
    int size() const;

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
bool List<NODETYPE>::removeFromFront(NODETYPE &value) {
    if (isEmpty()) {  // list is empty
        return false;
    } else {
        ListNode<NODETYPE> *tempPtr = firstPtr;

        if (firstPtr == lastPtr) {
            firstPtr = lastPtr = 0;  // no nodes remain after removal
        } else {
            firstPtr = firstPtr->nextPtr;  // point to previous 2nd node
        }

        value = tempPtr->data;
        delete tempPtr;

        --sz;

        return true;
    }
}
// delete node from back of list
template <typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &value) {
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

        value = tempPtr->data;
        delete tempPtr;

        --sz;
        return true;
    }
}
// concatenate new list to end of list
template <typename NODETYPE>
void List<NODETYPE>::concatenate(List<NODETYPE> &listSecond) {
    ListNode<NODETYPE> *currentPtr = listSecond.firstPtr;

    while (currentPtr != 0) {
        insertAtBack(currentPtr->getData());
        currentPtr = currentPtr->nextPtr;
    }
}
// merge two ordered lists into a new ordered list and return
template<typename NODETYPE>
List<NODETYPE> List<NODETYPE>::merge(List<NODETYPE>& list2){
    List<NODETYPE> mergeList;

    ListNode<NODETYPE>* ptr1 = firstPtr;
    ListNode<NODETYPE>* ptr2 = list2.firstPtr;

    while (ptr1 != nullptr && ptr2 != nullptr) {
        // values equal
        if (ptr1->getData() == ptr2->getData()) {
            mergeList.insertAtBack(ptr1->getData());
            mergeList.insertAtBack(ptr2->getData());
            ptr1 = ptr1->nextPtr;
            ptr2 = ptr2->nextPtr;
        }
        // second bigger
        if (ptr1->getData() < ptr2->getData()) {
            mergeList.insertAtBack(ptr1->getData());
            ptr1 = ptr1->nextPtr;
        // bigger
        } else {
            mergeList.insertAtBack(ptr2->getData());
            ptr2 = ptr2->nextPtr;
        }

        // end of lists
        if (ptr1 == nullptr) {
            mergeList.insertAtBack(ptr2->getData());
            ptr2 = ptr2->nextPtr;
        }
        if (ptr2 == nullptr) {
            mergeList.insertAtBack(ptr1->getData());
            ptr1 = ptr1->nextPtr;
        }
    }

    return mergeList;
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

    while (currentPtr != 0) {
        std::cout << currentPtr->getData() << ' ';
        currentPtr = currentPtr->nextPtr;
    }
}
// print sz of list
template <typename NODETYPE>
int List<NODETYPE>::size() const {
    return sz;
}
