#include <iostream>
#include "BSTree.h"
#include <fstream>

using namespace std;

/* Constructors */
/* Default constructor */
BSTree::BSTree()
{
    root = nullptr;
}
BSTree::~BSTree()
{
    while (root != nullptr)
    {
        remove(root->getData());
    }
}

/* Mutators */
/* Insert an item into the binary search tree. 
   Be sure to keep BST properties. 
   When an item is first inserted into the tree the count should be set to 1. 
   When adding a duplicate string (case sensitive), rather than adding another node, 
   the count variable should be incremented 
 */
void BSTree::insert(const string &newString)
{
    if (root == nullptr) {
        root = new Node(newString);
    }
    else {
        // bool found = false;
        Node* check = root;
        while (check != nullptr) {
            if (newString == check->getData()) {
                check->changeCount(1);
                check = nullptr;
                // found = true;
            }
            else if (newString < check->getData()) {
                if (check->getLeft() == nullptr) {
                    Node* tempNode = new Node(newString);
                    check->changeLeft(tempNode);
                    // found = true;
                    check = nullptr;
                }
                else {
                    check = check->getLeft();
                }
            }
            else {
                if (check->getRight() == nullptr) {
                    Node* tempNode = new Node(newString);
                    check->changeRight(tempNode);
                    check = nullptr;
                    // found = true;
                }
                else {
                    check = check->getRight();
                }
            }
        }
    }
}

/* Remove a specified string from the tree. 
   Be sure to maintain all bianry search tree properties. 
   If removing a node with a count greater than 1, just decrement the count, otherwise, 
   if the count is simply 1, remove the node. 
    You MUST follow the remove algorithm shown in the slides and discussed in class or else 
    your program will not pass the test functions. 
    When removing, 
        if removing a leaf node, simply remove the leaf. Otherwise, 
        if the node to remove has a left child, replace the node to remove with the largest 
        string value that is smaller than the current string to remove 
        (i.e. find the largest value in the left subtree of the node to remove). 
        If the node has no left child, replace the node to remove with the smallest value 
        larger than the current string to remove 
        (i.e. find the smallest value in the right subtree of the node to remove. 
 */
void BSTree::remove(const string &key)
{
    remove(key, root, root);
}

void BSTree::remove(const string &key, Node* parent, Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->getData() == key)
    {
        //duplicate
        if (node->getCount() > 1)
        {
            // cout << "duplicate" << endl;
            node->changeCount(-1);
            return;
        }
        //leaf
        if (node->getLeft() == nullptr && node->getRight() == nullptr)
        {
            // cout << "leaf node: " << node->getData() << endl;
            if (node == root)
            {
                root = nullptr;
            }
            if(parent->getLeft() == node)
            {
                parent->changeLeft(nullptr);
            }
            else
            {
                parent->changeRight(nullptr);
            }  
        }
        //only has right child
        else if (node->getLeft() == nullptr)
        {
            // cout << "no left child" << endl;
            if (root == node)
            {
                root = node->getRight();
                delete node;
                return;
            }
            if (parent->getLeft() ==node)
            {
                if (findMin(node->getRight()) == node->getRight())
                {
                    // cout << "checkdata: " << check->getData() << endl;
                    parent->changeLeft(node->getRight());
                }
                else
                {   
                    // cout << "checkValue: " << check->getData() << endl;
                    // cout << "created new node" << endl;
                    // cout << "findMin: " << findMin(check->getRight())->getData() << endl;
                    Node* newNode = new Node(findMin(node->getRight())->getData());
                    // cout << "newNode: " << newNode->getData() << endl;
                    // cout << "minCount: " << findMin(check->getRight())->getCount() << endl;
                    newNode->changeCount(findMin(node->getRight())->getCount() - 1);
                    // cout << "removing node" << endl;
                    remove(findMin(node->getRight())->getData(), root, root); 
                    // cout << "changing left and right" << endl;
                    newNode->changeLeft(node->getLeft());
                    newNode->changeRight(node->getRight());
                    // cout << "assigning parent to newNode" << endl;
                    parent->changeLeft(newNode);
                }
                
            }
            else
            {
                // Node* newNode = new Node(findMax(check->getLeft())->getData());
                // newNode->changeCount(findMax(check->getLeft())->getCount() - 1);
                // remove(findMax(check->getLeft())->getData(), root, root); 
                // newNode->changeLeft(check->getLeft());
                // newNode->changeRight(check->getRight());
                parent->changeRight(node->getRight());
            } 
        }
        //only has left
        else if (node->getRight() == nullptr)
        {
            // cout << "no right child" << endl;
            if (root == node)
            {
                root = node->getLeft();
                delete node;
                return;
            }
            if (parent->getLeft() == node)
            {
                if (findMax(node->getLeft()) == node->getLeft())
                {
                    parent->changeLeft(node->getLeft()); 
                }
                else
                {
                    Node* newNode = new Node(findMax(node->getLeft())->getData());
                    newNode->changeCount(findMax(node->getLeft())->getCount() - 1);
                    remove(findMax(node->getLeft())->getData(), root, root); 
                    newNode->changeLeft(node->getLeft());
                    newNode->changeRight(node->getRight());
                    parent->changeLeft(newNode);
                }
                
            }
            else
            {
                // Node* newNode = new Node(findMin(check->getLeft())->getData());
                // newNode->changeCount(findMin(check->getLeft())->getCount() - 1);
                // remove(findMax(check->getRight())->getData(), root, root); 
                // newNode->changeLeft(check->getLeft());
                // newNode->changeRight(check->getRight());
                parent->changeRight(node->getLeft());
            } 
        }
        //two children
        else 
        {
            // cout << "two children" << endl;
            // Node* replace;
            Node* newNode;
            if (node->getLeft() != nullptr)
            {
                // cout << "entered left" << endl;
                newNode = new Node(findMax(node->getLeft())->getData());
                Node* temp = findMax(node->getLeft());
                while (temp->getCount() != 1)
                {
                    temp->changeCount(-1);
                }
                newNode->changeCount(findMax(node->getLeft())->getCount() - 1);
                remove(findMax(node->getLeft())->getData(), root, root); 
                newNode->changeLeft(node->getLeft());
                newNode->changeRight(node->getRight());         
            }
            // else
            // {
            //     // cout << "entered right" << endl;
            //     newNode = new Node(findMin(node->getLeft())->getData());
            //     newNode->changeCount(findMin(node->getLeft())->getCount() - 1);
            //     while (findMin(node->getRight())->getCount() != 1)
            //     {

            //     }
            //     remove(findMin(node->getRight())->getData(), root, root); 
            //     newNode->changeLeft(node->getLeft());
            //     newNode->changeRight(node->getRight());

            // }  
            if (node == root)
            {
                root = newNode;
                // cout << "new root: " << root->getData() << endl;
            }
            else
            {
                if (parent->getLeft() == node)
                {
                    parent->changeLeft(newNode);
                }
                else
                {
                    parent->changeRight(newNode);
                }
            }
                   
        }
        delete node;
        return;

    }
    else if (key < node->getData())
    {
        remove(key, node, node->getLeft());
    }
    else
    {
        remove(key, node, node->getRight());
    }
    
    
    
}

Node* BSTree::findMin(Node* node)
{
    if (node->getLeft() == nullptr)
    {
        return node;
    }
    else
    {
        return findMin(node->getLeft());
        
    }  
}

Node* BSTree::findMax(Node* node)
{
    if (node->getRight() == nullptr)
    {
        return node;
    }
    else
    {
        return findMax(node->getRight());
    }
}

/* Accessors */
/* Search for a string in the binary search tree. 
   It should return true if the string is in the tree, and false otherwise. 
 */
bool BSTree::search(const string &key) const
{
    return search(key, root);
}

bool BSTree::search(const string &key, Node* check) const {
    if (check == nullptr)
    {
        return false;
    }
    if (key == check->getData()) {
        return true;
    }
    else if (key < check->getData()) {
        if (check->getLeft() != nullptr)
        {
            return search(key, check->getLeft());
        }
        else
        {
            return false;
        }
           
    }
    else {
        if (check->getRight() != nullptr)
        {
            return search(key, check->getRight());
        }
        else
        {
            return false;
        }         
    }
    return false;
}

/* Find and return the largest value in the tree. Return an empty string if the tree is empty */
string BSTree::largest() const
{
    if (root == nullptr) {
        return "";
    }
    Node* check = root;
    if (check->getRight() == nullptr) {
        return root->getData();
    }
    while (check->getRight() != nullptr) {
        check = check->getRight();
    }
    return check->getData();
}

/* Find and return the smallest value in the tree. Return an emtpy string if the tree is empty */
string BSTree::smallest() const
{
    if (root == nullptr) {
        return "";
    }
    Node* check = root;
    if (check->getLeft() == nullptr) {
        return root->getData();
    }
    while (check->getLeft() != nullptr) {
        check = check->getLeft();
    }
    return check->getData();
}

/* Compute and return the height of a particular string in the tree. 
   The height of a leaf node is 0 (count the number of edges on the longest path). 
   Return -1 if the string does not exist. 
 */
int BSTree::height(const string& key) const
{
    Node* check = root;
    // bool DNE = false;

    while (check != nullptr) {
        if (key == check->getData()) {
            break;
        }
        if (key < check->getData()) {
            if (check->getLeft() != nullptr)
            {
                check = check->getLeft();   
            }
            else
            {
                // DNE = true;
                check = nullptr;
            }           
        }
        else {
            if (check->getRight() != nullptr)
            {
                check = check->getRight();  
            }
            else
            {
                // DNE = true;
                check = nullptr;
            }
               
        }
    }

    if(check == nullptr)
    {
        return -1;
    }
    else
    {
        return height(check);
    }
    
}

int BSTree::height(Node* node) const
{
    if (node == nullptr)
    {
        return -1;
    }
    int leftH = height(node->getLeft());
    int rightH = height(node->getRight());
    if (leftH > rightH)
    {
        return 1 + leftH;
    }
    else
    {
        return 1 + rightH;
    }
    
}

/* Printing */
/* For all printing orders, each node should be displayed as follows:
   <string> (<count>)
   e.g. goodbye(1), Hello World(3)
   */
void BSTree::preOrder() const
{
    preOrder(root);
}

void BSTree::preOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->getData() << "(" << node->getCount() << ")" << ", ";
    if (node->getLeft() != nullptr)
    {
        preOrder(node->getLeft());
    }   
    if (node->getRight() != nullptr)
    {
        preOrder(node->getRight());
    } 
}

void BSTree::postOrder() const
{
    postOrder(root);
}

void BSTree::postOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    } 
    if(node->getLeft() != nullptr)
    {
        postOrder(node->getLeft());
    }
    else
    {
        if (node->getRight() == nullptr)
        {
            cout << node->getData() << "(" << node->getCount() << ")" << ", ";
            return;
        }
    }
    if (node->getRight() != nullptr)
    {
        postOrder(node->getRight());
    }
    else
    {
        cout << node->getData() << "(" << node->getCount() << ")" << ", ";
        return;
    }
    cout << node->getData() << "(" << node->getCount() << ")" << ", ";
}

void BSTree::inOrder() const
{
    inOrder(root);
}

void BSTree::inOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    } 
    if (node->getLeft() != nullptr)
    {
        inOrder(node->getLeft());
    }
    else
    {
        if (node->getRight() == nullptr)
        {
            cout << node->getData() << "(" << node->getCount() << ")" << ", ";
            return;
        }
    }
    cout << node->getData() << "(" << node->getCount() << ")" << ", ";
    Node* temp = node;
    if (node->getRight() != nullptr)
    {
        inOrder(node->getRight());
    }
    else
    {
        if (temp != node)
        {
            cout << node->getData() << "(" << node->getCount() << ")" << ", ";
            return;
        }
    }
}


// void BSTree::visualizeTree(const string &outputFilename){
//     ofstream outFS(outputFilename.c_str());
//     if(!outFS.is_open()){
//         cout<<"Error opening "<< outputFilename<<endl;
//         return;
//     }
//     outFS<<"digraph G {"<<endl;
//     visualizeTree(outFS,root);
//     outFS<<"}";
//     outFS.close();
//     string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
//     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//     system(command.c_str());
// }

// void BSTree::visualizeTree(ofstream & outFS, Node * node)
// {
//     if (node == nullptr)
//     {
//         return;
//     }
//     if (node->getLeft() != nullptr)
//     {
//         outFS << node->getData() << " -> " << node->getLeft()->getData() << endl;
//     }
//     if (node->getRight() != nullptr)
//     {
//         outFS << node->getData() << " -> " << node->getRight()->getData() << endl;
//     }

//      //<< "(" << node->getCount()<< ")" 
//     //  << ", " << node->getCount()
//     // return;
//     visualizeTree(outFS, node->getLeft());
//     visualizeTree(outFS, node->getRight());
// }
