#include "doublenode.h"

class DoublyLinkedList {
    public:
        DoublyLinkedList();
        DoublyLinkedList(DoubleNode* origin);
        virtual ~DoublyLinkedList();

        DoubleNode* GetFirst();
        DoubleNode* GetLast();

        void Push(DoubleNode* DoubleNode);
        void Remove(DoubleNode* DoubleNode);
        void RemoveAt(int index);
        void RemoveLast();
        void RemoveFirst();
        void Clear();

        int Count();
    private:
        DoubleNode* head;
        DoubleNode* tail;

        int count;
};