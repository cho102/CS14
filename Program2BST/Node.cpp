#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string data) {
    left = nullptr;
    right = nullptr;
    count = 1;
    this->data = data;
}

Node* Node::getLeft() {
    return left;
}

Node* Node::getRight() {
    return right;
}

void Node::changeLeft(Node* newNode) {
    left = newNode;

}

void Node::changeRight(Node* newNode) {
    right = newNode;
}

string Node::getData() {
    return data;
}

int Node::getCount() {
    return count;
}

void Node::changeCount(int newCount) {
    count += newCount;
}