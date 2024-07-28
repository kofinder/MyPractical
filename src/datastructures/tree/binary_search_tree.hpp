#pragma once

namespace tree {
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int _value): value(_value), left(nullptr), right(nullptr) {}
    };


    class BinarySearchTree {   
        private:
            bool rContains(Node* currentNode, int value);
            Node* rInsert(Node* currentNode, int value);
            Node* rDelete(Node* currentNode, int value);

        public:
            Node* root;

            BinarySearchTree(): root(nullptr) { }
            bool insert(int value);
            bool contains(int value);
            int minValue(Node* currentNode);

    };
}
