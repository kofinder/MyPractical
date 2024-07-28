#pragma once

namespace doublyllist {
    struct Node {
        int value;
        Node* next;
        Node* prev;

        Node(int _value): value(_value), next(nullptr), prev(nullptr) {}
    };


    class DoublyLinkedList {
        private:
            Node* head;
            Node* tail;
            int length;

        public:
            DoublyLinkedList(int value);

            void append(int value) const;

            void prepend(int value) const;

            Node get(int index) const;

            bool set(int index, int value) const;

            bool insert(int index, int value) const;

            Node removeFirst() const;

            Node removeLast() const;

            Node remove(int index) const;

            void reverse() const;
    };
}

