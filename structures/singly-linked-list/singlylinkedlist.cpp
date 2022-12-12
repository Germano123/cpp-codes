#include <iostream>
#include "singlylinkedlist.h"

// region Constructors
SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
    tail = NULL;
    count = 0;
}

SinglyLinkedList::SinglyLinkedList(Node* node) {
    head = node;
    tail = node;
    count = 1;
}

SinglyLinkedList::~SinglyLinkedList() {}
// endregio desconstructor

// return the first node in the list
Node* SinglyLinkedList:: GetFirst() {
    return head;
}

// return the last node in the list
Node* SinglyLinkedList:: GetLast() {
    return tail;
}

void SinglyLinkedList::Push(Node* node) {
    // set the next from current tail to the added node
    tail->SetNext(node);
    // set the added node as the tail
    tail = node;
    // increment the list count
    count++;
    return;
}

void SinglyLinkedList:: RemoveLast() {
    // reference to the head node
    Node* node = head;
    // loop through all the nodes to get the last but one
    while (node->GetNext() != tail) {
        node = node->GetNext();
    }
    // set the reference to null
    node->SetNext(NULL);
    // delete the current tail
    tail->~Node();
    // set the tail reference to the last but one
    tail = node;
    // decrement the list count
    count--;
    return;
}

void SinglyLinkedList:: RemoveFirst() {
    // get reference to the current head
    Node* node = head;
    // set the head to the next in the list
    head = head->GetNext();
    // delete the old head
    node->~Node();
    // decrement the list count
    count--;
    return;
}

void SinglyLinkedList::Remove(Node* node) {
    // reference to the head node
    Node* node = head;
    // loop through all the nodes
    while (node->GetNext() != node) {
        node = node->GetNext();
    }
    //  decrement the list count
    count--;
    return;
}

void SinglyLinkedList::RemoveAt(int index) {
    // check if the index is positive
    if (index < 0)
        return;
    // check if index is 0 to remove the first node
    if (index == 0) {
        RemoveFirst();
        return;
    }
    // variable to count the next node interaction
    int counter = 0;
    // reference to the node before the node to remove
    Node* nodeBefore = head;
    // loop until the previous node index to remove
    while (counter <= index-1) {
        // get the next node reference in the list
        nodeBefore = nodeBefore->GetNext();
        // increment the node counter
        counter++;
    }
    // reference to the node to remove
    Node* nodeToRemove = nodeBefore->GetNext();
    // set the next node from the previous
    nodeBefore->SetNext(nodeToRemove->GetNext());
    // set the next node from node to remove to null
    nodeToRemove->SetNext(NULL);
    // deconstruct the current node reference
    nodeToRemove->~Node();
    //  decrement the list count
    count--;
    return;
}

void SinglyLinkedList::Clear() {
    // remove from last until the node count is zero
    while (count > 0) {
        RemoveLast();
    }
    return;
}

int SinglyLinkedList::Count() {
    return count;
}
