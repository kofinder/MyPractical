#include <iostream>
using namespace std;

struct Node {  
    int value; // Stored value in the node
    Node* next; // Pointer to the next node in the list
    
    // Constructor to initialize a Node with a given value  
    Node(int _value) {  
        value = _value;  
        next = nullptr;    // Initially, next pointer is set to nullptr  
    }  
};  

class SinglyLinkedList {  
    private:  
        Node* head;  // first node pointer in the list
        Node* tail;  // last node pointer in the list
        int length;  // Number of nodes in the list  

    public:  
        // Constructor to initialize the linked list with a single value  
        SinglyLinkedList(int value) {  
            Node* newNode = new Node(value); // Create a new node  
            head = newNode;                   // Set head to new node  
            tail = newNode;                   // Set tail to new node  
            length = 1;                       // Set initial length to 1  
        }  

        // Method to append a value to the end of the list  
        void append(int value) {  
            Node* newNode = new Node(value); // Create a new node  
            if(length == 0) {                 // If list is empty  
                head = newNode;               // Set head and tail to new node  
                tail = newNode;  
            } else {  
                tail->next = newNode;         // Link the last node to the new node  
                tail = newNode;               // Update tail to new node  
            }  
            length++;                         // Increment length  
        }  

        // Method to prepend a value to the beginning of the list  
        void prepend(int value) {  
            Node* newNode = new Node(value); // Create a new node  
            if(length == 0) {                 // If list is empty  
                head = newNode;               // Set head and tail to new node  
                tail = newNode;  
            } else {  
                newNode->next = head;         // Link new node to the current head  
                head = newNode;               // Update head to the new node  
            }  
            length++;                         // Increment length  
        }  

        // Method to retrieve a node at a specific index  
        Node* get(int index) {  
            if(index < 0 || index >= length) { // Check index bounds  
                return nullptr;                // Return null if out of bounds  
            }  

            Node* temp = head;                // Start from head  

            // Traverse the list to find the node at the specified index  
            for(int i = 0; i < index; i++) {  
                temp = temp->next;  
            }  

            return temp;                      // Return the found node  
        }  

        // Method to set a value at a specified index  
        bool set(int index, int value) {  
            Node* temp = get(index);         // Get the node at the index  
            if(temp == nullptr) {             // Check if the node exists  
                return false;                // Return false if not found  
            }  
            temp->value = value;              // Set the new value  
            return true;                     // Return true on success  
        }  

        // Method to insert a value at a specified index  
        bool insert(int index, int value) {  
            if(index < 0 || index > length) { // Check index bounds  
                return false;                // Return false if out of bounds  
            }  

            if(index == 0) {                 // Insert at the beginning  
                prepend(value);  
                return true;  
            }  

            if(index == length) {             // Insert at the end  
                append(value);  
                return true;  
            }  

            Node* newNode = new Node(value); // Create a new node  
            Node* temp = get(index);         // Get the node at the specified index  
            newNode->next = temp->next;      // Link new node to the next node  
            temp->next = newNode;            // Link the previous node to the new node  
            length++;                         // Increment length  

            return true;                     // Return true on success  
        }  

        // Method to remove the first node from the list  
        Node* removeFirst() {  
            if(length == 0) {                 // Check if the list is empty  
                return nullptr;               // Return null if empty  
            }  

            Node* temp = head;                // Store the current head  
            head = head->next;                // Move head to the next node  
            temp->next = nullptr;             // Disconnect the removed node  
            length--;                         // Decrement length  

            // Update tail if the list is now empty  
            if(length == 0) {  
                tail = nullptr;  
            }  

            return temp;                     // Return the removed node  
        }  

        // Method to remove the last node from the list  
        Node* removeLast() {  
            if(length == 0) {                 // Check if the list is empty  
                return nullptr;               // Return null if empty  
            }  

            Node* temp = head;                // Start from head  
            Node* prev = head;                // To keep track of the previous node  

            // Traverse to the last node  
            while(temp->next != nullptr) {  
                prev = temp;                  // Update prev to current node  
                temp = temp->next;            // Move to next node  
            }  

            tail = prev;                      // Update tail to previous node  
            tail->next = nullptr;             // Disconnect the last node  
            length--;                         // Decrement length  

            // Update head and tail if the list is now empty  
            if(length == 0) {  
                head = nullptr;  
                tail = nullptr;  
            }  

            return temp;                     // Return the removed node  
        }  

        // Method to remove a node at a specific index  
        Node* remove(int index) {  
            if(index < 0 || index >= length) { // Check index bounds  
                return nullptr;                // Return null if out of bounds  
            }  

            if(index == 0) {                 // Remove the first node  
                return removeFirst();  
            }  

            if(index == length - 1) {        // Remove the last node  
                return removeLast();  
            }  

            Node* prev = get(index - 1);     // Get the node before the one to be removed  
            Node* temp = prev->next;          // Get the target node  
            prev->next = temp->next;          // Bypass the target node  
            temp->next = nullptr;              // Disconnect the removed node  
            length--;                         // Decrement length  

            return temp;                     // Return the removed node  
        }  

        // Method to reverse the linked list  
        void reverse() {  
            Node* temp = head;                // Start from head  
            head = tail;                      // Set head to tail  
            tail = temp;                      // Set tail to the original head  

            Node* after = temp->next;         // After keeps track of the next node  
            Node* before = nullptr;           // Before tracks the previous node  

            // Reverse the pointers of all nodes  
            for(int i = 0; i < length; i++) {  
                after = temp->next;          // Save the next node  
                temp->next = before;         // Reverse the current node's pointer  
                before = temp;               // Update before to current node  
                temp = after;                // Move to the next node  
            }  
        }  

        // Method to print the linked list  
        void print() {  
            if(!head) {                       // Check if list is empty  
                cout << "LIST IS EMPTY" << endl; // Print message  
                return;  
            }  
            Node* temp = head;               // Start from head  
            // Print each value in the list  
            while(temp != nullptr) {  
                cout << temp->value << "->"; // Print the value followed by an arrow  
                temp = temp->next;           // Move to the next node  
            }  
            cout << "nullptr" << endl;       // Indicate end of list  
        }  
};  
