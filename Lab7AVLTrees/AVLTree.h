#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include <iostream>
#include "Node.h"
using namespace std;

class AVLTree {
    private: 
        Node* root;
        
    public:
        AVLTree();
        void insert(const string &); // Insert an item to the binary search tree and perform rotation if necessary.
        int balanceFactor(Node*); // Return the balance factor of a given node.
        void printBalanceFactors(); // Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.
        void visualizeTree(const string &); // Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.

    private:
        Node* findUnbalancedNode(Node*, Node*); // Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
        void rotate(Node*); // Implement four possible imbalance cases and update the parent of the given node.
        Node* rotateLeft(Node *); // Rotate the subtree to left at the given node and returns the new subroot.
        Node* rotateRight(Node *); // Rotate the subtree to right at the given node and returns the new subroot.
        void printBalanceFactors(Node *);
        void visualizeTree(ofstream &, Node *);
        int height(Node*) const;
        void changeHeight(Node*);
        Node* findParent(Node*);
};

#endif