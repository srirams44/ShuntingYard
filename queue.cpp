#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue() { //Constructor to initliaze empty queue
    front = rear = nullptr;
}

Queue::~Queue() { //Free all nodes once queue is destroyed
    while (!isEmpty()) {
      //  dequeue(); //Remove all elements if not empty
    }
}

bool Queue::isEmpty() {
    return front == nullptr; //If front is nullptr, the queue is empty
}

void Queue::enqueue(char value) { //Add a value to the end of the queue
    Node* newNode = new Node(value); //Create a new node
    if (isEmpty()) {
        front = rear = newNode; //If the queue is empty, set the front and rear to the new node
    }
    else {
        rear->next = newNode; //Link the last node to the new node
        rear = newNode; //Update rear to the new node
    }
}

char Queue::dequeue() {
    if (isEmpty()) { //If queue is empty, return a null character
        cout << "Queue is empty." << endl;
        return '\0';
    }

    Node* temp = front; //Store front node
    char data = temp->data; //Get the data front node
    front = front->next; //move front to the to the next node
    delete temp; //delete the old front node

    if (front == nullptr) { //if queue becomes empty, update rear to nullptr
        rear = nullptr;
    }

    return data; //Return dequeued value
}