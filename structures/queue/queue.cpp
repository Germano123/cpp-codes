#include "queue.h"
#include <iostream>

Queue::Queue() {
    current = NULL;
    last = NULL;
}

Queue::Queue(Node* node) {
    current = node;
    last = node;
}

void Queue:: Enqueue(Node* node) {
    // set last node reference to node added 
    last->SetNext(node);
    // update the last node in the queue
    last = node;
    // increment the count amount of nodes
    count++;
    return;
}

Node* Queue:: Dequeue() {
    // get reference to the current node
    Node* node = current;
    // update the current node in the queue
    current = current->GetNext();
    // decrement the count amount of nodes
    count--;
    // return the last current node
    return node;
}

int Queue:: Count() {
    return count;
}