/*
 * =====================================================================================
 *
 *       Filename:  ListNode.hpp
 *
 *    Description:  Fig. 20.3 - Template ListNode Class Definition
 *
 *        Version:  1.0
 *        Created:  13/03/17 13:58:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

// forward declaration of class List required to announce that class
// List exists so it can be used in the friend declaration at line 13
template <typename NODETYPE>
class List;

template <typename NODETYPE>
class ListNode {
    friend class List<NODETYPE>;  // make List a friend

 public:
    explicit ListNode(const NODETYPE& info) : data(info), nextPtr(0) {}

    // return copy of data in node
    NODETYPE getData() const { return data; }

    // return pointer to next node
    ListNode<NODETYPE>* next() const { return nextPtr; }

 private:
    NODETYPE data;
    ListNode<NODETYPE> *nextPtr;
};
