#include "stack.hpp"
using namespace stack;

Stack::Stack(int value) {
    Node* newNode = new Node(value);
    top = newNode;
    height = 1;
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    if(height == 0) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    height++;
}

Node* Stack::pop(int value) {
    if(height == 0) {
        return nullptr;
    }

    Node* temp = top;
    top = top->next;
    temp->next = nullptr;
    height--;

    return temp;
}