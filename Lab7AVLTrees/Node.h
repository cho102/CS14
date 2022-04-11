#ifndef __NODE_H__
#define __NODE_H__

#include <string>
using namespace std;

class Node {
    public:
        string data;
        int count;
        int height;
        Node* left;
        Node* right;
        // Node* parent;

    public:
        Node();
        Node(string data);
        void changeCount(int);
};

#endif