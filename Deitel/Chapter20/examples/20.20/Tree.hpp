/*
 * =====================================================================================
 *
 *       Filename:  Tree.h
 *
 *    Description:  Fig. 20.21 - Template Tree class definition
 *
 *        Version:  1.0
 *        Created:  14/03/17 15:47:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "TreeNode.hpp"

#include <iostream>

// Tree class-template definition
template <typename NODETYPE>
class Tree {
 public:
    Tree();

    void insertNode(const NODETYPE &);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;

 private:
    TreeNode<NODETYPE> *rootPtr;

    // utility functions
    void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);
    void preOrderHelper(TreeNode<NODETYPE> *) const;
    void inOrderHelper(TreeNode<NODETYPE> *) const;
    void postOrderHelper(TreeNode<NODETYPE> *) const;
};

// constructor
template <typename NODETYPE>
Tree<NODETYPE>::Tree() {
    rootPtr = 0;  // indicate tree is initially empty
}
// insert node in tree
template <typename NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE &value) {
    insertNodeHelper(&rootPtr, value);
}
// utility function called by insertNoode; receives a pointer
// to a pointer so that the function can modify pointer's value
template <typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE> **ptr,
                                      const NODETYPE &value) {
    // subtree is empty; create new TreeNode containing value
    if (*ptr == 0)
        *ptr = new TreeNode<NODETYPE>(value);
    else {
        // data to insert is less than data in current node
        if (value < (*ptr)->data)
            insertNodeHelper(&((*ptr)->leftPtr), value);
        else {
            // data to insert is greater than data in current node
            if (value > (*ptr)->data)
                insertNodeHelper(&((*ptr)->rightPtr), value);
            else  // duplicate value ignored
                std::cout << value << " dup" << std::endl;
        }
    }
}
// being preorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::preOrderTraversal() const {
    preOrderHelper(rootPtr);
}
// utility function to perform preorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE> *ptr) const {
    if (ptr != 0) {
        std::cout << ptr->data << ' ';  // process node
        preOrderHelper(ptr->leftPtr);
        preOrderHelper(ptr->rightPtr);
    }
}
// begin inorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::inOrderTraversal() const {
    inOrderHelper(rootPtr);
}
// utility function to perform inorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE> *ptr) const {
    if (ptr != 0) {
        inOrderHelper(ptr->leftPtr);
        std::cout << ptr->data << ' ';
        inOrderHelper(ptr->rightPtr);
    }
}
// begin postorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::postOrderTraversal() const {
    postOrderHelper(rootPtr);
}
// utility function to perform postorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE> *ptr) const {
    if (ptr != 0) {
        postOrderHelper(ptr->leftPtr);
        postOrderHelper(ptr->rightPtr);
        std::cout << ptr->data << ' ';  // process node
    }
}
