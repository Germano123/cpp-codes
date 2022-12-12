class Node {
    public:
        // constructor
        Node();
        // constructor with next parameter
        Node(Node* nextNode);
        // deconstructor
        virtual ~Node();

        // get the pointer reference to the next node
        Node* GetNext();
        // set the reference to the pointer of the next node
        void SetNext(Node* node);

        // get the value of the node
        int GetValue();
        // set the value of the node
        void SetValue(int val);

    protected:
        // the next node value
        Node* next;
        // the value of the node
        int value;
};
