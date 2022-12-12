#include "node.h"

class SinglyLinkedList {
    public:
        SinglyLinkedList();
        SinglyLinkedList(Node* origin);
        ~SinglyLinkedList();
        
        Node* GetFirst();
        Node* GetLast();

        void Push(Node* node);
        void Remove(Node* node);
        void RemoveAt(int index);
        void RemoveLast();
        void RemoveFirst();
        void Clear();
        
        int Count();
    private:
        Node* head;
        Node* tail;
        int count;
};