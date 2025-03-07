//
// Created by LilSriSri on 3/6/2025.
//

#include "stack.h"
#include <iostream>
using namespace std;


Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    //If empty, remove everything
}

bool Stack::isEmpty() { //Check if the stack is empty
    return top == nullptr; //If the top is nullptr, stack is empty
}

void Stack::push(char value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

char Stack::pop() { //Remove the top node and return its valie 
    if (isEmpty()) {
        //If stack is empty, throw an error
        cout << "Stack is empty." << endl;
        return '\0'; //Return null character if stack is empty
    }

    Node* temp = top; //Store the top node
    char data = temp->data; //Get the value of the top node
    top = top->next; //Move the top pointer to the next node
    delete temp; //Delete the temp variable
    return data; //Return the value of the "popped" node
}


