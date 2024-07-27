struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int _value) {
        value = _value;
        left = nullptr;
        right = nullptr;
    }
};


class BinarySearchTree {   
    private:

        bool rContains(Node* currentNode, int value) {
            if(currentNode == nullptr) return false;

            if(currentNode->value == value) return true;

            if(value < currentNode->value) {
                return rContains(currentNode->left, value);
            } else {
                return rContains(currentNode->right, value);
            }
        }

        Node* rInsert(Node* currentNode, int value) {
            if(currentNode == nullptr) return new Node(value);
            if(value < currentNode->value) {
                currentNode->left = rInsert(currentNode->left, value);
            } else {
                currentNode->right = rInsert(currentNode->right, value);
            }
            return currentNode;
        }

        Node* rDelete(Node* currentNode, int value) {
            if(currentNode == nullptr) return nullptr;
            if(value < currentNode->value) {
                currentNode->left = rDelete(currentNode->left, value);
            } else {
                currentNode->right = rDelete(currentNode->right, value);
            }
            return currentNode;
        }

    public:
        Node* root;

        BinarySearchTree() {
            root = nullptr;
        }

        bool insert(int value) {
            Node* newNode = new Node(value);
            if(root == nullptr) {
                root = newNode;
                return false;
            }

            Node* temp = root;
            while(true) {
                if(newNode->value == temp->value) {
                    return false;
                }
                if(newNode->value < temp->value) {
                    if(temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if(temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        bool contains(int value) {
            Node* temp = root;
            while(temp != nullptr) {
                if(value < temp->value) {
                    temp = temp->left;
                } else if(value > temp->value) {
                    temp = temp->right;
                } else {
                    return true;
                }

                return false;
            }
        }   

        int minValue(Node* currentNode) {
            
            while(currentNode->left != nullptr) {
                currentNode = currentNode->left;
            }

            return currentNode->value;
        }     

};