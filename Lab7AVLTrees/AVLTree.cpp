#include <fstream>

#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree()
{
    root = nullptr;
}

// Insert an item to the binary search tree and perform rotation if necessary.
void AVLTree::insert(const string & newString)
{
    Node* tempNode = new Node(newString);
    if (root == nullptr) {
        root = tempNode;
    }
    else {
        Node* check = root;
        while (check != nullptr) {
            if (check->data == newString)
            {
                check->changeCount(1);
                return;
            }
            if (newString < check->data) {
                if (check->left == nullptr) {      
                    check->left = tempNode;
                    check = nullptr;
                }
                else {
                    check = check->left;
                }
            }
            else {
                if (check->right == nullptr) {
                    check->right = tempNode;
                    check = nullptr;
                }
                else {
                    check = check->right;
                }
            }
        }
    }
    changeHeight(root); //cout << "Call Changed Height" << endl; 
    visualizeTree("exp.dot");
    rotate(tempNode); //cout << "Call Rotate Node" << endl;
    visualizeTree("exp.dot");
    
}

void AVLTree::rotate(Node* tempNode)
{ 
    if (findUnbalancedNode(root, tempNode) != nullptr)
    {
        // cout << "unbalanced found" << endl;
        Node* nodeToRotate = findUnbalancedNode(root, tempNode); //cout << "nodeToRotate: " << nodeToRotate->data << endl;
        Node* parent = findParent(nodeToRotate); //cout << "parent: " << parent->data << endl;
        if (balanceFactor(nodeToRotate) == 2 && balanceFactor(nodeToRotate->left) == 1)
        {
            cout << "case1 : left left" << endl;
            if (parent == nodeToRotate)
            {
                root = rotateRight(nodeToRotate);
            }
            else if (parent->left == nodeToRotate)
            {
                parent->left = rotateRight(nodeToRotate);
            }
            else
            {
                parent->right = rotateRight(nodeToRotate);
            }
            
        }
        else 
        if (balanceFactor(nodeToRotate) == -2 && balanceFactor(nodeToRotate->right) == -1)
        {
            cout << "case2 : right right" << endl;
            if (parent == nodeToRotate)
            {
                root = rotateLeft(nodeToRotate);
            }
            else if (parent->left == nodeToRotate)
            {
                parent->left = rotateLeft(nodeToRotate);
            }
            else
            {
                parent->right = rotateLeft(nodeToRotate);
            }
        }
        else if (balanceFactor(nodeToRotate) == 2 && balanceFactor(nodeToRotate->left) == -1)
        {
            cout << "case3 : left right" << endl;
            nodeToRotate->left = rotateLeft(nodeToRotate->left);
            if (parent == nodeToRotate)
            {
                root = rotateRight(nodeToRotate);
            }
            else if (parent->left == nodeToRotate)
            {
                parent->left = rotateRight(nodeToRotate);
            }
            else
            {
                parent->right = rotateRight(nodeToRotate);
            }
        }
        else
        {
            cout << "case4 : right left" << endl;//<< "nodeToRotate: " << nodeToRotate->data << "; nodeToRotate->right: " << nodeToRotate->right->data << endl;
            nodeToRotate->right = rotateRight(nodeToRotate->right);
                if (parent == nodeToRotate)
                {
                    root = rotateLeft(nodeToRotate);
                }
                else if (parent->left == nodeToRotate)
                {
                    parent->left = rotateLeft(nodeToRotate);
                }
                else
                {
                    parent->right = rotateLeft(nodeToRotate);
                }
        }
        
    }
    changeHeight(root);
}

// Rotate the subtree to left at the given node and returns the new subroot.
Node* AVLTree::rotateLeft(Node *node)
{
    Node* change = node->right;
    Node* temp = change->left;
    change->left = node;
    node->right = temp;
    visualizeTree("exp.dot");
    return change;
}

// Rotate the subtree to right at the given node and returns the new subroot.
Node* AVLTree::rotateRight(Node *node)
{
    Node* change = node->left;
    Node* temp = change->right;
    
    change->right = node;
    node->left = temp;
    visualizeTree("exp.dot");
    return change;
}


Node* AVLTree::findUnbalancedNode(Node* temp, Node* key)
{
    Node* check = temp; //cout << "Called findUnbalancedNode" << endl << "check: " << check->data << " ; key: " << key->data << endl;
    Node* unbalanced = nullptr;
    if (root == key)
    {
        return nullptr;
    }
    while (check != nullptr)
    {
        // cout << "entered while loop" << endl << "check: " << check->data << " ; key: " << key->data << endl;
        if (check->data == key->data)
        {
            check = nullptr;
            return unbalanced;
        }
        if (balanceFactor(check) > 1)
        {
            unbalanced = check;
        }
        else if (balanceFactor(check) < -1)
        {
            unbalanced = check;
        }
        if (key->data < check->data)
        {
            check = check->left;
        }
        else
        {
            check = check->right;
        }                
    }
    // if (unbalanced != nullptr)
    // {
    //     cout << "unbalanced: " << unbalanced->data << endl;
    // }
    // else
    // {
    //     cout << "null" << endl;
    // }
    
    return unbalanced;
}
// Return the balance factor of a given node.       
int AVLTree::balanceFactor(Node* currNode)
{
    int left, right;
    if (currNode->left != nullptr)
    {
        left = currNode->left->height;
    }
    else
    {
        left = -1;
    }
    if (currNode->right != nullptr)
    {
        right = currNode->right->height;
    }
    else
    {
        right = -1;
    }
    
    return left-right;
}
// Traverse and print the tree in inorder notation. Print the string followed by 
//its balance factor in parentheses followed by a , and one space.
void AVLTree::printBalanceFactors()
{
    printBalanceFactors(root);
    cout << endl;
}

void AVLTree::printBalanceFactors(Node * node)
{
    if (node == nullptr)
    {
        return;
    } 
    if (node->left != nullptr)
    {
        printBalanceFactors(node->left);
    }
    else
    {
        if (node->right == nullptr)
        {
            cout << node->data << "(" << balanceFactor(node) << ")" << ", ";
            return;
        }
    }
    cout << node->data << "(" << balanceFactor(node) << ")" << ", ";
    Node* temp = node;
    if (node->right != nullptr)
    {
        printBalanceFactors(node->right);
    }
    else
    {
        if (temp != node)
        {
            cout << node->data << "(" << balanceFactor(node) << ")" << ", ";
            return;
        }
    }
    
}


int AVLTree::height(Node* node) const
{
    if (node == nullptr)
    {
        return -1;
    }
    int leftH = height(node->left);
    int rightH = height(node->right);
    if (leftH > rightH)
    {
        return 1 + leftH;
    }
    else
    {
        return 1 + rightH;
    } 
}
// Generate dotty file and visualize the tree 
//using dotty program. Call this function before and after rotation.
void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}
void AVLTree::changeHeight(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    node->height = height(node);
    changeHeight(node->left);
    changeHeight(node->right);
}

Node* AVLTree::findParent(Node* key)
{
    // cout << "entered findParent" << endl;
    if (key == root)
    {
        return root;
    }
    Node* temp = root;
    while (temp != nullptr)
    {
        if (key->data < temp->data)
        {
            if (temp->left == key)
            {
                return temp;
            }
            else
            {
                temp = temp->left;
            }  
        }
        else
        {
            if (temp->right == key)
            {
                // cout << "parentFound: " << temp->data << endl;
                return temp;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    return temp;
}