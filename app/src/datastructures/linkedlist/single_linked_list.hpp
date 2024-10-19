#pragma once


namespace linkedlist {
    struct Node {  
        int value; 
        Node* next;
        
        Node(int _value): next(nullptr), value(_value) {}  
    };  


    class SinglyLinkedList {  
        private:  
            Node* head;
            Node* tail;
            int length;

        public:  

            SinglyLinkedList(int value);
            
            void append(int value);

            void prepend(int value);

            Node* get(int index);

            bool set(int index, int value);

            bool insert(int index, int value);

            Node* removeFirst();

            Node* removeLast();

            Node* remove(int index);

            void reverse();

            void print();
    };
}
