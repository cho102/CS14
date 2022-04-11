#include "arithmeticExpression.h"
#include <fstream>
#include <sstream>
#include <stack>
#include <iostream>
using namespace std;

/* Helper function that returns an integer according to
the priority of the given operator. */
int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

/* Helper function that returns the postfix notation equivalent
       to the given infix expression */
string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}


    /* Calls the recursive visualizeTree function and generates the .png file using system call. */
void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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


    /* Initializes an empty tree and sets the infixExpression
    to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string & exp){
    infixExpression = exp;
    root = nullptr;
}

    /* Implementation of destrucor is optional.
       The destructor should deallocate all the nodes in the tree. */
    //~arithmeticExpression();

    /* Converts the infixExpression to its equivalent postfix string
       and then generates the tree and assigns the root node to the 
       root data field. The key for the first node is 'a', 'b' for the second node and so on. */

    //algorithm reference from: https://courses.cs.washington.edu/courses/cse326/03wi/assignments/hw2.html
void arithmeticExpression::buildTree(){
    char keyVal = 'a';
    stack <TreeNode*> st;
    string post = infix_to_postfix();

    for (unsigned i = 0; i < post.size(); ++i)
    {
        // cout << "i: " << post.at(i) << endl;
        if (post.at(i) == '+' || post.at(i) == '-' || post.at(i) == '*' || post.at(i) == '/')
        {
            // cout << "operator" << endl;
            // cout << "temp: " << st.top()->data << endl;
            TreeNode* temp = st.top();
            st.pop();
            // cout << "temp1: " << st.top()->data << endl;
            TreeNode* temp1 = st.top();
            st.pop();
            root = new TreeNode(post.at(i), keyVal);
            root->left = temp1;
            root->right = temp;
            st.push(root);
        }
        else
        {
            // cout << "num" << endl;
            TreeNode* temp3 = new TreeNode(post.at(i), keyVal);
            st.push(temp3);
        }
        ++keyVal;
        
    }

}

    /* Calls the recursive infix function. */
void arithmeticExpression::infix(){
    // cout << "(";
    infix(root);
    // cout << ")";
}

void arithmeticExpression::infix(TreeNode *node)
{
    if (node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/')
    {
        cout << "(";
    }
    
    if (node->left != nullptr)
    {
        infix(node->left);
    }
    else
    {
        cout << node->data;
        return;
    }
    cout << node->data;
    if (node->right != nullptr)
    {
        infix(node->right);
    }
    else
    {
        cout << node->data << ")";
        return;
    }
    cout << ")";
    
}


    /* Calls the recursive prefix function. */
void arithmeticExpression::prefix(){
    prefix(root);
}

void arithmeticExpression::prefix(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data;
    if (node->left != nullptr)
    {
        prefix(node->left);
    }   
    if (node->right != nullptr)
    {
        prefix(node->right);
    } 
}

    /* Calls the recursive postfix function. */
void arithmeticExpression::postfix(){
    // cout << infix_to_postfix();
    postfix(root);
}

void arithmeticExpression::postfix(TreeNode *node)
{
    if(node->left != nullptr)
    {
        postfix(node->left);
    }
    else
    {
        cout << node->data;
        return;
    }
    if (node->right != nullptr)
    {
        postfix(node->right);
    }
    else
    {
        cout << node->data;
        return;
    }
    cout << node->data;
    
    
}

// // /* Helper function for generating the dotty file. This is a recursive function. */
void arithmeticExpression::visualizeTree(ofstream & outFS, TreeNode * node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->left != nullptr)
    {
        outFS << node->key << " -> " << node->left->key << endl;
    }
    if (node->right != nullptr)
    {
        outFS << node->key << " -> " << node->right->key << endl;
    }
    // return;
    visualizeTree(outFS, node->left);
    visualizeTree(outFS, node->right);
}

