struct Node {
    Node* next;
    int value;

    Node(int _value) {
        value = _value;
        next = nullptr;
    }
};


class Stack {
    private:
        Node* top;
        int height;

    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            if(height == 0) {
                top = newNode;
            } else {
                newNode->next = top;
                top = newNode;
            }
            height++;
        }

        Node* pop(int value) {
            if(height == 0) {
                return nullptr;
            }

            Node* temp = top;
            top = top->next;
            temp->next = nullptr;
            height--;

            return temp;
        }
};