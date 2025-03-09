#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "queue.h"
#include <string>
using namespace std;

class ShuntingYard {
public:
    static Queue* infixToPostfix(const string& infix); //Converts infix expression to postfix notation

private:
    static int getPrecedence(char op); //Check for precedence level
    static bool isRightAssociative(char op); //Only true if operator is right-associative
};





#endif