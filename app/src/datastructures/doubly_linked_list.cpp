struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int _value) {
        value = _value;
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void append(int value) {}

        void prepend(int value) {}

        Node get(int index) {}

        bool set(int index, int value) {}

        bool insert(int index, int value) {}

        Node removeFirst() {}

        Node removeLast() {}

        Node remove(int index) {}

        void reverse() {}
};