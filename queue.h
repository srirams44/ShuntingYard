#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

class Queue {
public:
    Queue();
    ~Queue();

    bool isEmpty(); //Check if queue is empty
    void enqueue(char value); //Add a value to the queue
    char dequeue(); //Remove and return the front value

private:
    Node* front;
    Node* rear;

};

#endif
