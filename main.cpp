#include <iostream>
#include "ShuntingYard.h"
#include "ExpressionTree.h"

using namespace std;

int main() {
    string infixExpr;

    // Get infix expression from user input
    cout << "Enter infix expression (with spaces between tokens): ";
    getline(cin, infixExpr);

    // Convert to postfix notation
    Queue* postfixQueue = ShuntingYard::infixToPostfix(infixExpr);

    // Display postfix result from Shunting Yard
    cout << "\nPostfix expression: ";
    Queue tempStorage;  // Temporary queue to preserve data
    while (!postfixQueue->isEmpty()) {
        char token = postfixQueue->dequeue();
        cout << token << " ";
        tempStorage.enqueue(token);
    }
    // Restore original queue for tree construction
    while (!tempStorage.isEmpty()) {
        postfixQueue->enqueue(tempStorage.dequeue());
    }

    // Build expression tree from postfix notation
    ExpressionTree exprTree(postfixQueue);

    string command;
    do {
        cout << "\nEnter command (infix/prefix/postfix/quit): ";
        cin >> command;

        if (command == "infix") {
            cout << "Infix notation: " << exprTree.getInfix() << endl;
        } else if (command == "prefix") {
            cout << "Prefix notation: " << exprTree.getPrefix() << endl;
        } else if (command == "postfix") {
            cout << "Postfix notation: " << exprTree.getPostfix() << endl;
        } else if (command != "quit") {
            cout << "Invalid command! Valid options: infix, prefix, postfix, quit\n";
        }
    } while (command != "quit");

    // Clean up memory
    delete postfixQueue;
    return 0;
}