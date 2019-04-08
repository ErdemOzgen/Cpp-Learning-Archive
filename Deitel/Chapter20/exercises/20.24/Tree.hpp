/*
 * =====================================================================================
 *
 *       Filename:  Tree.hpp
 *
 *    Description:  Exercise 20.23 - Binary Tree Search
 *
 *        Version:  1.1
 *        Created:  14/03/17 15:47:02
 *       Revision:  07/02/18 19:31:47
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include <iostream>
#include <algorithm>
#include <queue>

#include "TreeNode.hpp"

// Tree class-template definition
template <typename NODETYPE>
class Tree {
 public:
        Tree();

        void insertNode(const NODETYPE &);
        void preOrderTraversal() const;
        void inOrderTraversal() const;
        void postOrderTraversal() const;
        void levelOrderTraversal() const;
        // determine the depth of the given tree
        static size_t depth(Tree<NODETYPE> tree) { return tree.depthHelper(tree.rootPtr); }

        TreeNode<NODETYPE>* binaryTreeSearch(const NODETYPE &) const;

 private:
        TreeNode<NODETYPE> *rootPtr;

        // utility functions
        void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);
        void preOrderHelper(TreeNode<NODETYPE> *) const;
        void inOrderHelper(TreeNode<NODETYPE> *) const;
        void postOrderHelper(TreeNode<NODETYPE> *) const;
        void levelOrderHelper(TreeNode<NODETYPE> *) const;
        size_t depthHelper(TreeNode<NODETYPE> *) const;
        TreeNode<NODETYPE>* searchHelper(TreeNode<NODETYPE> *, const NODETYPE &) const;
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
    if (*ptr == 0) {
        *ptr = new TreeNode<NODETYPE>(value);
    } else {
        // data to insert is less than data in current node
        if (value < (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
        } else {
            // data to insert is greater than data in current node
            if (value > (*ptr)->data) {
                insertNodeHelper(&((*ptr)->rightPtr), value);
            } else { // duplicate value ignored
                std::cout << value << " dup" << std::endl;
            }
        }
    }
}
// being preorder traversal of Tree
template <typename NODETYPE>
void Tree<NODETYPE>::preOrderTraversal() const {
    preOrderHelper(rootPtr);
    std::cout << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
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
/**
 * Level-Order binary tree traversal
 */
template <typename NODETYPE>
void Tree<NODETYPE>::levelOrderTraversal() const {
    levelOrderHelper(rootPtr);
    std::cout << std::endl;
}  // end method levelOrderTraversal

/**
 * Utility function to perform levelorder traversal of tree.
 * @param TreeNode<NODETYPE> *
 */
template <typename NODETYPE>
void Tree<NODETYPE>::levelOrderHelper(TreeNode<NODETYPE> *ptr) const {
    std::queue<TreeNode<NODETYPE>*> queue;

    if (ptr) { queue.push(ptr); }

    while (!queue.empty()) {
        // ensure front node is dequeued.
        TreeNode<NODETYPE>* temp = queue.front();
        queue.pop();

        std::cout << temp->getData() << std::endl;

        if (temp->leftPtr != nullptr) { queue.push(temp->leftPtr); }
        if (temp->rightPtr != nullptr) { queue.push(temp->rightPtr); }
    }
}  // end method levelOrderHelper

// utility function to return the depth of the given node
template <typename NODETYPE>
size_t Tree<NODETYPE>::depthHelper(TreeNode<NODETYPE> *ptr) const {
    // base case
    if (ptr == 0) {
        return 0;
    } else {
        size_t ldepth = depthHelper(ptr->leftPtr);
        size_t rdepth = depthHelper(ptr->rightPtr);

        if (ldepth <= rdepth) {
            return rdepth + 1;
        } else {
            return ldepth + 1;
        }
    }
}
/**
 * Searches the tree for given node.
 * @param NODETYPE &
 * @return TreeNode<NODETYPE>*
 */
template <typename NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::binaryTreeSearch(const NODETYPE &value) const {
    return searchHelper(rootPtr, value);
}  // end method binaryTreeSearch
/**
 * Searches the tree for the given node from the root.
 * @param TreeNode<NODETYPE>*
 * @param NODETYPE
 * @return TreeNode<NODETYPE>*
 */
template <typename NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::searchHelper(TreeNode<NODETYPE> *ptr, const NODETYPE &value) const {
    // base case
    if (ptr == nullptr || ptr->getData() == value) {
        return ptr;
    }

    // greater
    if (value > ptr->getData()) {
        return searchHelper(ptr->rightPtr, value);
    }

    // smaller
    return searchHelper(ptr->leftPtr, value);
}  // end method searchHelper
