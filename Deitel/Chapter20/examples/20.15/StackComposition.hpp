/*
 * =====================================================================================
 *
 *       Filename:  StackComposition.h
 *
 *    Description:  Fig. 20.15 - Template Stack class definition with composed
 *                  List object
 *
 *        Version:  1.0
 *        Created:  14/03/17 13:20:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "List.hpp"

template <typename STACKTYPE>
class StackComposition {
 public:
    // no constructor; List constructor does initialisation

    // push calls to stackList object's insertAtFront member function
    void push(const STACKTYPE &data) { stackList.insertAtFront(data); }
    // pop calls stackList object's removeFromFront member function
    bool pop(STACKTYPE &data) { return stackList.removeFromFront(data); }
    // isStackEmpty calls stackLit object's isEmpty member function
    bool isStackEmpty() const { return stackList.isEmpty(); }
    // printStack calls stackList object's print member function
    void printStack() const { stackList.print(); }

 private:
    List<STACKTYPE> stackList;
};
