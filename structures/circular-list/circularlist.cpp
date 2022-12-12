#include "circularlist.h"
#include "node.h"
#include <iostream>

CircularList:: CircularList() {
    head = NULL;
    tail = NULL;
    return;
}

CircularList:: CircularList(Node* origin) {
    head = origin;
    tail = origin;
    count = 1;
    return;
}

CircularList:: ~CircularList() {
    head = NULL;
    tail = NULL;
}

Node* CircularList:: Get(int index) {
    // if index is negative, return null
    if (index < 0) {
        return NULL;
    } else
    // if index is equal 0, return the first element
    if (index == 0) {
        return head;
    } else
    // if the index is equal to the list count, return the last element
    if (index == count) {
        return tail;
    }
    // else loop through all the nodes
    else {
        // variable to count the iteration
        int counter = 0;
        // variable to iterate through nodes to get the node before the asked one
        Node* node = head;
        // loop through nodes until find an equal
        while (counter <= index) {
            node = node->GetNext();
            counter++;
        }
        return node;
    }
}

Node* CircularList:: GetFirst() {
    return head;
}

Node* CircularList:: GetLast() {
    return tail;
}

void CircularList:: Push(Node* node) {
    // set the added node as the last node
    tail->SetNext(node);
    // set the next node from added node as the first node
    node->SetNext(head);
    // increment the node count
    count++;
    return;
}

void CircularList:: Remove(Node* node) {
    // variable to iterate through nodes to get the node before the asked one
    Node* nodeBefore = head;
    // loop through nodes until find an equal
    while (nodeBefore->GetNext() != node) {
        nodeBefore = nodeBefore->GetNext();
    }
    // reference to node to remove
    Node* nodeToRemove = nodeBefore->GetNext();
    // set the next node from node before to the next node form node to remove
    nodeBefore->SetNext(nodeToRemove->GetNext());
    // set the next from node to remove to null
    nodeToRemove->SetNext(NULL);
    // deconstruct the node to remove
    nodeToRemove->~Node();
    // decrement the count of elements
    count--;
    return;
}

void CircularList::RemoveAt(int index) {
    // cant remove node outside the range
    if (index > count) {
        return;
    } else if(index == count) {
        RemoveLast();
        return;
    } else {
        Node* node = Get(index-1);
        Node* nodeToRemove = node->GetNext();
        
        node->SetNext(nodeToRemove->GetNext());
        
        nodeToRemove->SetNext(NULL);
        nodeToRemove->~Node();
    }
    // decrement the count of elements
    count--;
    return;
}

void CircularList::RemoveLast() {
    // reference to the node before the last one
    Node* nodeBefore = Get(count-1);
    // referente to the last node
    Node* nodeLast = tail;
    // set the next node from the last but one to the next from the last one
    nodeBefore->SetNext(nodeLast->GetNext());
    // set the next from the last to null
    nodeLast->SetNext(NULL);
    // deconstruct the last node
    nodeLast->~Node();
    // update the tail reference
    tail = nodeBefore;
    // decrement the count of elements
    count--;
    return;
}

void CircularList::RemoveFirst() {
    // reference to the current head node
    Node* node = head;
    // set the tail next node the second element
    tail->SetNext(node->GetNext());
    // set the second node as the new head
    head = node->GetNext();
    // set the removed node next to null
    node->SetNext(NULL);
    // deconstruct the node
    node->~Node();
    // decrement the count of elements
    count--;
    return;
}

int CircularList::Count() {
    return count;
}