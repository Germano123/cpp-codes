#include "stack.h"
#include <iostream>

Stack::Stack() {
    top = NULL;
}

Stack::Stack(Node* origin) {
    top = origin;
}

Stack::~Stack() {}

Node* Stack::Pop() {
    // get reference to the top node in the top position
    Node* node = top;
    // reference the next 
    top = node->getNext();
    // decrement the count amount of nodes
    count--;
    return node;
}

void Stack::Push(Node* node) {
    // set the added node next to the current top node
    node->setNext(top);
    // set the stack top node to the added node
    top = node;
    // increment the count amount of nodes
    count++;
    return;
}

int Stack:: Count() {
    return count;
}