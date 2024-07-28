#pragma once

namespace stack {
    struct Node {
        Node* next;
        int value;

        Node(int _value): next(nullptr), value(_value) {}
    };


    class Stack {
        private:
            Node* top;
            int height;

        public:
            Stack(int value);
            void push(int value);
            Node* pop(int value);
    };
}