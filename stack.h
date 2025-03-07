#ifndef STACK_H
#define STACK_H
#include "node.h"


class Stack {
public:
    Stack();
    ~Stack();

    bool isEmpty();
    void push(char value); //add to the stack
    char pop(); //Remove and return top value from the stack

private:
    Node* top; //points to the top of the stack


};



#endif //STACK_H
