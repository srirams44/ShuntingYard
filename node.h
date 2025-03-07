#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    Node(char value);
    char data; //So I can store operators and numbers
    Node* next;
    Node* left;
    Node* right;
};

#endif //NODE_H
