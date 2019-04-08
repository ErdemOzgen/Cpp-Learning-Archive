/*
 * =====================================================================================
 *
 *       Filename:  TreeNode.h
 *
 *    Description:  Fig. 20.20 - Template TreeNode class definition
 *
 *        Version:  1.0
 *        Created:  14/03/17 15:43:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

// forward declaration of class Tree
template <typename NODETYPE>
class Tree;

// TreeNode class-template definition
template <typename NODETYPE>
class TreeNode {
    friend class Tree<NODETYPE>;

 public:
    explicit TreeNode(const NODETYPE &d) : leftPtr(0), data(d), rightPtr(0) {}

    // return copy of node's data
    NODETYPE getData() const { return data; }

 private:
    TreeNode<NODETYPE> *leftPtr;
    NODETYPE data;
    TreeNode<NODETYPE> *rightPtr;
};
