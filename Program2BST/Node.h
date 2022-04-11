#ifndef __NODE_H__
#define __NODE_H__

#include <string>
using namespace std;

class Node {
    private:
            string data;
            int count;
            Node* left;
            Node* right;

    public:
            Node(string data);
            Node* getLeft();
            Node* getRight();
            void changeLeft(Node* newNode);
            void changeRight(Node* newNode);
            string getData();
            int getCount();
            void changeCount(int newCount);
};

#endif