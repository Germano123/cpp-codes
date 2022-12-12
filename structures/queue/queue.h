#include "node.h"

class Queue {
    public:
        // constructor
        Queue();
        // constructor with base node
        Queue(Node* origin);
        // deconstructor
        virtual ~Queue();
        // function to add a new node in the queue
        void Enqueue(Node* node);
        // function to remove one node from the queue
        Node* Dequeue();
        // function to retrieve how many nodes are still in the queue
        int Count();
    private:
        // variable to reference the first node in the queue
        Node* current;
        // variable to reference the last node in the queue
        Node* last;
        // variable to control how many nodes are in the queue
        int count;
};
