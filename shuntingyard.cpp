#include "shuntingyard.h"
#include "stack.h"
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;


vector<string> split(const string& s) { //Split input strings into tokens
    vector<string> tokens; //Store seperated tokens
    string token;
    istringstream tokenStream(s);

    while (getline(tokenStream, token, ' ')) {
        if (!token.empty()) {
            //Skip empty tokens
            tokens.push_back(token);
        }
    }

    return tokens;

}

int ShuntingYard::getPrecedence(char op) {
    if (op == '^') {
        return 4;  // Highest precedence
    }
    else if (op == '*' || op == '/') {
        return 3;  // Multiplication and division precedence
    }
    else if (op == '+' || op == '-') {
        return 2;  // Addition and subtraction precedence
    }
    else {
        return 0;  // For parentheses and anything invalid
    }
}

bool ShuntingYard::isRightAssociative(char op) {
    return (op == '^'); //Only exponents are right-associative in this case
}

Queue* ShuntingYard::infixToPostfix(const string& infix) {
    Stack operatorStack; //STack to hold operatorss
    Queue* outputQueue = new Queue(); //Holds final postfix result
    vector<string> tokens = split(infix); //Split into tokens

    for (size_t i = 0; i < tokens.size(); ++i) {
        string token = tokens[i]; //Get the current token
        char c = token[0]; //Get first character

        if (isdigit(c)) { //Case 1: Number
            outputQueue->enqueue(c); //Send to output
        }
        else if (c == '(') { //Case 2: Left (
            operatorStack.push(c); //Push to stack
        }
        else if (c == ')') { //Case 3: Right )
            //Pop operators to output until a left ( is found
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                outputQueue->enqueue(operatorStack.pop());
            }
            operatorStack.pop(); //Discard left (
        }
        else { //Case 4: Operator
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                char topOperator = operatorStack.peek();
                int currentPrecedence = getPrecedence(c);
                int stackPrecedence = getPrecedence(topOperator);

                if ((currentPrecedence < stackPrecedence) or (currentPrecedence == stackPrecedence && !isRightAssociative(c))) { //Determine if we should pop stack operator
                    outputQueue->enqueue(operatorStack.pop());
                }
                else {
                    break; //Stop popping
                }
            }
            operatorStack.push(c); //Push current operator to stack
        }
    }

    while (!operatorStack.isEmpty()) { //Pop any remaining operators to output
        outputQueue->enqueue(operatorStack.pop());
    }
    return outputQueue;
}
