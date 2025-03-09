#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "queue.h"
#include <string>
using namespace std;

class ShuntingYard {
public:
    Queue* infixToPostfix(const string& infix); //Converts infix expression to postfix notation

private:
    int getPrecedence(char op); //Check for precedence level
    bool isRightAssociative(char op); //Only true if operator is right-associative
};





#endif