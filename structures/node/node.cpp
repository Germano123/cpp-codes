#include <iostream>
#include "node.h"

Node:: Node() {
    next = NULL;
}

Node:: Node(Node* nextNode) {
    next = nextNode;
}

Node:: ~Node() {
    next = NULL;
}

Node* Node:: getNext() {
    return next;
}

void Node:: setNext(Node* node) {
    next = node;
    return;
}

int Node:: getValue() {
    return value;
}

void Node:: setValue(int val) {
    value = val;
    return;
}