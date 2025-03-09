#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include "Node.h"
#include "Queue.h"
//#include "expressiontree.cpp"
#include <string>

using namespace std;

class ExpressionTree {
public:
    ExpressionTree(Queue* postfixQueue);
    ~ExpressionTree();

    string getInfix(); //Return infix notation
    string getPrefix(); //Return prefix notation
    string getPostfix(); //Return postfix notation
private:
    Node* root; //root node of tree

    void deleteTree(Node* node); //Helper function for destructor

    string infixTraversal(Node* node, bool isRoot); //Helper function for infix traversing - is root ensures that only parentheses are added only for non root operator nodes
    string prefixTraversal(Node* node); //Helper function for prefix traversing
    string postfixTraversal(Node* node); //Helper function for postfix traversing
};

#endif