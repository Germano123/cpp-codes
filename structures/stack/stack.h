#include "node.h"

class Stack {
    public:
        Stack();
        Stack(Node* first);
        virtual ~Stack();
        Node* Pop();
        void Push(Node* Node);
        int Count();
    private:
        Node* top;
        int count;
};