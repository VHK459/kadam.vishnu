#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
private:
    // Node structure
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root; // Root of the BST

    // Helper function to insert a value into the BST
    Node* insert(Node* node, T value) {
        if (node == nullptr) {
            return new Node(value); // Create a new node if the current node is null
        }

        if (value < node->data) {
            node->left = insert(node->left, value); // Insert into the left subtree
        } else if (value > node->data) {
            node->right = insert(node->right, value); // Insert into the right subtree
        }

        return node; // Return the (unchanged) node pointer
    }

    // Helper function to search for a value in the BST
    bool search(Node* node, T value) const {
        if (node == nullptr) {
            return false; // Value not found
        }

        if (value == node->data) {
            return true; // Value found
        } else if (value < node->data) {
            return search(node->left, value); // Search in the left subtree
        } else {
            return search(node->right, value); // Search in the right subtree
        }
    }

    // Helper function to perform inorder traversal (left -> root -> right)
    void inorder(Node* node) const {
        if (node != nullptr) {
            inorder(node->left); // Traverse the left subtree
            cout << node->data << " "; // Visit the root
            inorder(node->right); // Traverse the right subtree
        }
    }

    // Helper function to find the minimum value in the BST
    Node* findMin(Node* node) const {
        while (node->left != nullptr) {
            node = node->left; // Keep moving to the leftmost node
        }
        return node;
    }

    // Helper function to delete a value from the BST
    Node* remove(Node* node, T value) {
        if (node == nullptr) {
            return nullptr; // Value not found
        }

        if (value < node->data) {
            node->left = remove(node->left, value); // Delete from the left subtree
        } else if (value > node->data) {
            node->right = remove(node->right, value); // Delete from the right subtree
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(node->right);
            node->data = temp->data; // Copy the inorder successor's data to this node
            node->right = remove(node->right, temp->data); // Delete the inorder successor
        }

        return node;
    }

    // Helper function to delete the entire tree (postorder traversal)
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left); // Delete the left subtree
            clear(node->right); // Delete the right subtree
            delete node; // Delete the current node
        }
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Destructor
    ~BinarySearchTree() {
        clear(root); // Delete the entire tree
    }

    // Public function to insert a value
    void insert(T value) {
        root = insert(root, value);
    }

    // Public function to search for a value
    bool search(T value) const {
        return search(root, value);
    }

    // Public function to perform inorder traversal
    void inorder() const {
        inorder(root);
        cout << endl;
    }

    // Public function to remove a value
    void remove(T value) {
        root = remove(root, value);
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

    // Inorder traversal (prints elements in sorted order)
    cout << "Inorder traversal: ";
    bst.inorder();

    // Search for elements
    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not Found") << endl;

    // Remove elements
    bst.remove(20);
    cout << "Inorder traversal after removing 20: ";
    bst.inorder();

    bst.remove(30);
    cout << "Inorder traversal after removing 30: ";
    bst.inorder();

    bst.remove(50);
    cout << "Inorder traversal after removing 50: ";
    bst.inorder();

    return 0;
}
