#include "doublenode.h"
#include <iostream>

#pragma Constructors
// constructor
DoubleNode:: DoubleNode() {
    next = NULL;
    previous = NULL;
}

DoubleNode:: DoubleNode(DoubleNode* next) {
    next = next;
    previous = NULL;
}

DoubleNode:: DoubleNode(DoubleNode* nextNode, DoubleNode* previousNode) {
    next = next;
    previous = previous;
}

DoubleNode:: ~DoubleNode() {
    next = NULL;
    previous = NULL;
}
#pragma endregion

#pragma Getters/Setters
DoubleNode* DoubleNode:: GetNext() {
    return next;
}

void DoubleNode:: SetNext(DoubleNode* node) {
    next = node;
}

DoubleNode* DoubleNode:: GetPrevious() {
    return previous;
}

void DoubleNode:: SetPrevious(DoubleNode* node) {
    previous = node;
}
#pragma endregion