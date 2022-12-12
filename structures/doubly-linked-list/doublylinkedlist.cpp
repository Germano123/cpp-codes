#include "doublylinkedlist.h"
#include "doublenode.h"
#include <iostream>

DoublyLinkedList:: DoublyLinkedList(){
    head = NULL;
    tail = NULL;
}

DoublyLinkedList:: DoublyLinkedList(DoubleNode* origin){
    head = origin;
    tail = origin;
    count = 1;
}

DoublyLinkedList:: ~DoublyLinkedList(){}

DoubleNode* DoublyLinkedList:: Get(int index) {
    // if index is below zero or higher than count, return null
    if (index < 0 || index > count) {
        return NULL;
    } else
    // if index is equal zero, return the first element
    if (index == 0) {
        return GetFirst();
    } else
    // if index is equal count, return the last element
    if (index == count) {
        return GetLast();
    }
    // else loop through all nodes
    else {
        int counter = 0;
        DoubleNode* node = head;
        while (counter <= index) {
            node = node->GetNext();
        }
        return node;
    }
}

DoubleNode* DoublyLinkedList:: GetFirst() {
    return head;
}

DoubleNode* DoublyLinkedList:: GetLast() {
    return tail;
}

void DoublyLinkedList::Push(DoubleNode* node) {
    // set the next node tail reference to the added node 
    tail->SetNext(node);
    // set the previous added node to the current tail
    node->SetPrevious(tail);
    // update the tail reference to the added node
    tail = node;
    // increment the list count
    count++;
    return;
}

void DoublyLinkedList::Remove(DoubleNode* node) {
    // variable to compare the node data
    DoubleNode* nodeLoop = head;
    // loop through all the nodes until find the equal one
    while (nodeLoop != node) {
        nodeLoop = nodeLoop->GetNext();
    }

    // reference to the node to remove
    DoubleNode* nodeBefore = nodeLoop->GetPrevious();
    // reference to the next node after the node to remove
    DoubleNode* nodeNext = nodeLoop->GetNext();
    // set the next node from the previous node
    nodeBefore->SetNext(nodeNext);
    // set the previous node from the next node
    nodeNext->SetPrevious(nodeBefore);
    // deconstruct the current node reference
    nodeLoop->SetNext(NULL);
    nodeLoop->SetPrevious(NULL);
    nodeLoop->~DoubleNode();
    // decrement the list count
    count--;
    return;
}

void DoublyLinkedList:: RemoveAt(int index){
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
    DoubleNode* nodeBefore = head;
    // loop until the previous node index to remove
    while (counter <= index-1) {
        // get the next node reference in the list
        nodeBefore = nodeBefore->GetNext();
        // increment the node counter
        counter++;
    }
    // reference to the node to remove
    DoubleNode* nodeToRemove = nodeBefore->GetNext();
    // reference to the next node after the node to remove
    DoubleNode* nodeNext = nodeToRemove->GetNext();
    // set the next node from the previous node
    nodeBefore->SetNext(nodeNext);
    // set the previous node from the next node
    nodeNext->SetPrevious(nodeBefore);
    // deconstruct the current node reference
    nodeToRemove->SetNext(NULL);
    nodeToRemove->SetPrevious(NULL);
    nodeToRemove->~DoubleNode();
    // decrement the list count
    count--;
    return;
}

void DoublyLinkedList:: RemoveLast() {
    // get reference to the last but one node
    DoubleNode* node = tail->GetPrevious();
    // set his next to null
    node->SetNext(NULL);
    // set the tail preivous to null
    tail->SetPrevious(NULL);
    // deconstruct the current tail node
    tail->~DoubleNode();
    // update the tail node reference
    tail = node;
    // decrement the list count
    count--;
    return;
}

void DoublyLinkedList:: RemoveFirst() {
    // get the reference to the second node
    DoubleNode* node = head->GetNext();
    // set the head node next to null
    head->SetNext(NULL);
    // set the second node previous to null
    node->SetPrevious(NULL);
    // deconstruct the current head
    head->~DoubleNode();
    // update the head reference to the second node
    head = node;
    // decrement the list count
    count--;
    return;
}

void DoublyLinkedList:: Clear() {
    // remove from last until the node count is zero
    while (count > 0) {
        RemoveLast();
    }
    return;
}

int DoublyLinkedList:: Count(){
    return count;
}
