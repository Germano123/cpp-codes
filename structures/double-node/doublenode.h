class DoubleNode {
    public:
        DoubleNode();
        DoubleNode(DoubleNode* next);
        DoubleNode(DoubleNode* next, DoubleNode* previous);
        virtual ~DoubleNode();
        
        DoubleNode* GetNext();
        DoubleNode* GetPrevious();

        void SetNext(DoubleNode* node);
        void SetPrevious(DoubleNode* node);
    private:
        DoubleNode* next;
        DoubleNode* previous;
};