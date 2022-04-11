#include <iostream>
#include "IntList.h"

using namespace std;

    // Initializes an empty list with dummy head and dummy tail.
    IntList::IntList()
    {
        // IntNode* dummy = new IntNode(-1);
        dummyhead = new IntNode(-1);
        dummytail = new IntNode(-1);
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
    }


    // Deallocates all remaining dynamically allocated memory 
    // (all remaining IntNodes).
    //Collaborated with: Brandon Trieu
    IntList::~IntList()
    {
        while (dummyhead->next != dummytail)
        {
            pop_front();
        }
    }


    // Inserts a data value (within a new node) at the front end 
    // of the list. This must be an O(1) operation.
    void IntList::push_front(int value)
    {
        IntNode* front = new IntNode(value);
        if(dummyhead->next == dummytail)
        {
            dummyhead->next = front;
            front->next = dummytail;
            dummytail->prev = front;
            front->prev = dummyhead;
            // tail = front;
        }
        else
        {
            IntNode* temp = dummyhead->next;
            front->next = temp;
            temp->prev = front;
            front->prev = dummyhead;
            dummyhead->next = front;
        }
        
    }


    // Removes the node at the front end of the list (the node 
    // after the dummy head). Does nothing if the list is already 
    // empty. This must be an O(1) operation.
    void IntList::pop_front()
    {
        if (dummyhead->next == dummytail)
        {
            return;
        }
        IntNode* remove = dummyhead->next;
        if (dummyhead->next->next == dummytail)
        {
            // tail = head;
            dummyhead->next = dummytail;
            dummytail->prev = dummyhead;
        }
        else
        {
            dummyhead->next = dummyhead->next->next;
            dummyhead->next->prev = dummyhead;
        }
        delete remove;
    }


    // Inserts a data value (within a new node) at the back end of 
    // the list. This must be an O(1) operation.
    void IntList::push_back(int value)
    {
        IntNode* last = new IntNode(value);
        dummytail->prev->next = last;
        last->prev = dummytail->prev;
        last->next = dummytail;
        dummytail->prev = last;
        
        // last->prev = tail;
        // tail = last;
    }


    // Removes the node at the back end of the list (the node before 
    // the dummy tail). Does nothing if the list is already empty. 
    // This must be an O(1) operation.
    void IntList::pop_back()
    {
        if (dummyhead->next == dummytail)
        {
            return;
        }
        IntNode* remove = dummytail->prev;
        if (dummyhead->next->next == dummytail)
        {
            dummytail->prev = dummyhead;
            dummyhead->next = dummytail;
        }
        else
        {
            dummytail->prev = dummytail->prev->prev;
            dummytail->prev->next = dummytail;
        }
        
        delete remove;
    }


    // Returns true if the list does not store any data values (it only 
    // has dummy head and dummy tail), otherwise returns false.
    bool IntList::empty() const
    {
        if (dummytail->prev == dummyhead)
        {
            return true;
        }
        return false;
    }


    // A global friend function that outputs to the stream all of the 
    // integer values within the list on a single line, each separated 
    // by a space. This function does NOT send to the stream a newline 
    // or space at the end.
    ostream & operator<<(ostream &out, const IntList &rhs)
    {
        // if (rhs.head == rhs.tail)
        // {
        //     return out;
        // }
        // out << rhs.head->next->data;
        // IntList temp = rhs;
        // temp.head = rhs.head->next;
        // if (temp.head != nullptr)
        // {
        //     out << " ";
        // }
        // out << temp;

        for (IntNode* temp = rhs.dummyhead->next; temp != rhs.dummytail; temp = temp->next)
        {
            out << temp->data;
            if (temp->next != rhs.dummytail)
            {
                out << " ";
            }
        }
        return out;
    }


    // prints to a single line all of the int values stored in the list 
    // in REVERSE order, each separated by a space. This function does 
    // NOT output a newline or space at the end.
    void IntList::printReverse() const
    {
        for (IntNode* i = dummytail->prev; i != dummyhead; i = i->prev)
        {
            cout << i->data;
            if (i->prev != dummyhead)
            {
                cout << " ";
            }
        }
    }

