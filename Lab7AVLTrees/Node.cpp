#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string data) {
    left = nullptr;
    right = nullptr;
    count = 1;
    height = -1;
    this->data = data;
    // parent = nullptr;
}

void Node::changeCount(int num)
{
    count += num;
}