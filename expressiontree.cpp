#include "ExpressionTree.h"
#include <sstream>


using namespace std;

struct NodeStack { //Node stack using linked list nodes, helps construct tree using postfix notation
    Node* top = nullptr;

    bool isEmpty() { //Check if stack is empty
        return top == nullptr;
    }

    void push(Node* node) { //Push node onto stack
        node->next = top; //Use next pointer for stack links
        top = node;
    }

    Node* pop() {
        //Pop node from stack
        if (isEmpty()) return nullptr;
        Node* temp = top;
        top = top->next;
        return temp;
    }
};

ExpressionTree::ExpressionTree(Queue* postfixQueue) { //Constructor builds tree from postfix queue
    root = nullptr;
    NodeStack nodeStack; //Stack to build tree

    while (!postfixQueue->isEmpty()) {
        char token = postfixQueue->dequeue(); //Get next token

        if (isdigit(token)) { //If token is a digit create leaf node
            nodeStack.push(new Node(token));
        }

        else {
            Node* newNode = new Node(token); //Create operator node
            newNode->right = nodeStack.pop(); //First pop is right child
            newNode->left = nodeStack.pop(); //Second pop is left child
            nodeStack.push(newNode); //Push subtree back to stack
        }
    }

    root = nodeStack.pop(); //Final node in stack is root of complete tree
}

ExpressionTree::~ExpressionTree() { //Destructor
    deleteTree(root); //Start recursive deletion
}

void ExpressionTree::deleteTree(Node* node) { //Recursive tree deletion helper
    if (node) {
        deleteTree(node->left); //Delete left subtree
        deleteTree(node->right); //Delete right subtree
        delete node; //Delete current node
    }
}

string ExpressionTree::infixTraversal(Node* node, bool isRoot) {
    if (!node) {
        return ""; //Base case
    }

    if (!node->left && node->right) { //If left node - number, return immediatly
        return string(1, node->data);
    }

    //return "(" + infixTraversal(node->left, false) + " " + node->data + " " + infixTraversal(node->right, false) + ")"; //Otherwise Otherwise combine left and right with paranthesis
    string left = infixTraversal(node->left, false);
    string right = infixTraversal(node->right, false);

    string result = left + " " + string(1, node->data) + " " + right;

    if (!isRoot) {
        result = '(' + result + ')';
    }
    return result;
}

string ExpressionTree::prefixTraversal(Node* node) {
    if (!node) {
        return "";
    }
    return string(1, node->data) + " " + prefixTraversal(node->left) + prefixTraversal(node->right); //Return operator followed by left and right
}

string ExpressionTree::postfixTraversal(Node* node) {
    if (!node) {
        return "";
    }
    return postfixTraversal(node->left )+ postfixTraversal(node->right) + " " + node->data; //Return left, then right, then operator
}

//Getter methods
string ExpressionTree::getInfix() {
    return infixTraversal(root, true);
}

string ExpressionTree::getPrefix() {
    return prefixTraversal(root);
}

string ExpressionTree::getPostfix() {
    return postfixTraversal(root);
}