#include "node.h"

class CircularList {
    public:
        CircularList();
        CircularList(Node* origin);
        virtual ~CircularList();

        Node* Get(int index);
        Node* GetFirst();
        Node* GetLast();

        void Push(Node* node);
        void Remove(Node* node);
        void RemoveAt(int index);
        void RemoveLast();
        void RemoveFirst();

        int Count();
    private:
        Node* head;
        Node* tail;
        int count;
};