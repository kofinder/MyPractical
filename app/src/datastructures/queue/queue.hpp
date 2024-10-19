#pragma once

namespace queue {
    struct Node {
        Node* next;
        int value;

        Node(int _value): next(nullptr), value(_value) {}
    };

    class Queue {
        private:
            Node* first;
            Node* last;
            int length;

        public:
            Queue(int value);
            void enqueue(int value);
            Node* dequeue();
    };
}
