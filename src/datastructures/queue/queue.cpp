struct Node {
    Node* next;
    int value;

    Node(int _value) {
        value = _value;
    }

};

class Queue {
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(int value) {
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        void enqueue(int value) {
            Node* newNode = new Node(value);
            if(length == 0) {
                first = newNode;
                last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        Node* dequeue() {
            if(length == 0) {
                return nullptr;
            }

            Node* temp = first;
            if(length == 1) {
                first = nullptr;
                last = nullptr;
            } else {
                first = first->next;
                temp->next = nullptr;
            }

            length--;
            return temp;
        }
};
