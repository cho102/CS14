#include <iostream>
using namespace std;

#ifndef _IntList
#define _IntList

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList
{
    public:
        IntList(); 
        ~IntList(); 
        void push_front(int value); 
        void pop_front(); 
        void push_back(int value); 
        void pop_back(); 
        bool empty() const; 
        friend ostream & operator<<(ostream &out, const IntList &rhs); 
        void printReverse() const; 

    private:
        IntNode* dummyhead;
        IntNode* dummytail;

};

#endif