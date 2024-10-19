#include "doubly_linked_list.hpp"
using namespace doublyllist;


DoublyLinkedList::DoublyLinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

void append(int value) {

}

void prepend(int value) {

}

Node* get(int index) {
    return nullptr;
}

bool set(int index, int value) {
    return false;
}

bool insert(int index, int value)  {
    return false;
}

Node* removeFirst()  {
    return nullptr;
}

Node* removeLast() {
    return nullptr;
}

Node* remove(int index) {
    return nullptr;
}

void reverse() {
}