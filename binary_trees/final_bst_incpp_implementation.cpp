#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree {
private:
    // Internal Node class
    class Node {
    public:
        T data;
        Node* left;
        Node* right;
        Node* parent;

        Node(const T& value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root; // Root of the BST

    // Helper function to search for a value
    Node* search(Node* node, const T& value) const {
        while (node != nullptr && node->data != value) {
            if (value < node->data) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return node;
    }

    // Helper function to find the minimum node in a subtree
    Node* getMin(Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to replace one subtree with another
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v; // u is the root
        } else if (u == u->parent->left) {
            u->parent->left = v; // u is the left child
        } else {
            u->parent->right = v; // u is the right child
        }
        if (v != nullptr) {
            v->parent = u->parent; // Update v's parent
        }
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Destructor
    ~BinarySearchTree() {
        clear(root);
    }

    // Clear the tree (helper for destructor)
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // Search for a value in the BST
    bool search(const T& value) const {
        return search(root, value) != nullptr;
    }

    // Insert a new value into the BST
    void insert(const T& value) {
        Node* newNode = new Node(value);
        Node* parent = nullptr;
        Node* current = root;

        // Find the correct position for the new node
        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Insert the new node
        newNode->parent = parent;
        if (parent == nullptr) {
            root = newNode; // Tree was empty
        } else if (value < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    // Delete a value from the BST
    void remove(const T& value) {
        Node* z = root;
        while (z != nullptr && z->data != value) {
            if (value < z->data) {
                z = z->left;
            } else {
                z = z->right;
            }
        }

        if (z == nullptr) {
            return; // Value not found
        }

        if (z->left == nullptr) {
            transplant(z, z->right); // No left child
        } else if (z->right == nullptr) {
            transplant(z, z->left); // No right child
        } else {
            Node* y = getMin(z->right); // Find the successor
            if (y->parent != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }

        delete z; // Free the memory
    }

    // Print the BST (inorder traversal)
    void printInorder(Node* node) const {
        if (node != nullptr) {
            printInorder(node->left);
            cout << node->data << " ";
            printInorder(node->right);
        }
    }

    // Public function to print the BST
    void print() const {
        printInorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree<int> bst;

    // Insert elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Print the BST
    cout << "Inorder traversal: ";
    bst.print(); // Output: 20 30 40 50 60 70 80

    // Search for elements
    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl; // Output: Found
    cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not Found") << endl; // Output: Not Found

    // Delete elements
    bst.remove(20);
    cout << "Inorder traversal after deleting 20: ";
    bst.print(); // Output: 30 40 50 60 70 80

    bst.remove(30);
    cout << "Inorder traversal after deleting 30: ";
    bst.print(); // Output: 40 50 60 70 80

    bst.remove(50);
    cout << "Inorder traversal after deleting 50: ";
    bst.print(); // Output: 40 60 70 80

    return 0;
}
