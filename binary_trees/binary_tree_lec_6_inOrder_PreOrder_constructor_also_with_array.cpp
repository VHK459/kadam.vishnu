#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
private:
    // Internal Node class
    class Node {
    public:
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* _root; // Pointer to the root of the tree

    // Helper function to recursively delete nodes
    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    // Constructor
    BinaryTree() : _root(nullptr) {}

    // Destructor
    ~BinaryTree() {
        clear(_root);
    }

    // Public methods for tree traversal
    void preorder() const {
        preorder(_root);
    }

    void inorder() const {
        inorder(_root);
    }

    void postorder() const {
        postorder(_root);
    }

    // Constructor that builds a tree from pre-order and in-order sequences
    BinaryTree(const T* preorder, const T* inorder, int size) {
        _root = buildTree(preorder, inorder, size);
    }

private:
    // Recursive helper functions for traversals
    void preorder(Node* node) const {
        if (node) {
            cout << node->data << " "; // Visit the root
            preorder(node->left);      // Traverse the left subtree
            preorder(node->right);     // Traverse the right subtree
        }
    }

    void inorder(Node* node) const {
        if (node) {
            inorder(node->left);      // Traverse the left subtree
            cout << node->data << " "; // Visit the root
            inorder(node->right);     // Traverse the right subtree
        }
    }

    void postorder(Node* node) const {
        if (node) {
            postorder(node->left);    // Traverse the left subtree
            postorder(node->right);   // Traverse the right subtree
            cout << node->data << " "; // Visit the root
        }
    }

    // Helper function to build a tree from pre-order and in-order sequences
    Node* buildTree(const T* preorder, const T* inorder, int size) {
        if (size == 0) return nullptr;

        // The first element in pre-order is the root
        T rootValue = preorder[0];
        Node* root = new Node(rootValue);

        // Find the root in the in-order sequence
        int rootIndex = 0;
        while (inorder[rootIndex] != rootValue) {
            rootIndex++;
        }

        // Recursively build the left and right subtrees
        root->left = buildTree(preorder + 1, inorder, rootIndex);
        root->right = buildTree(preorder + 1 + rootIndex, inorder + rootIndex + 1, size - rootIndex - 1);

        return root;
    }
};



template <class T>
class ArrayBinaryTree {
private:
    T* _array;
    int _size;

public:
    // Constructor
    ArrayBinaryTree(T* array, int size) : _array(array), _size(size) {}

    // Get the left child index
    int left(int i) const {
        int leftIndex = 2 * i + 1;
        return (leftIndex < _size) ? leftIndex : -1; // Return -1 if no left child
    }

    // Get the right child index
    int right(int i) const {
        int rightIndex = 2 * i + 2;
        return (rightIndex < _size) ? rightIndex : -1; // Return -1 if no right child
    }

    // Get the parent index
    int parent(int i) const {
        return (i > 0) ? (i - 1) / 2 : -1; // Return -1 if no parent
    }

    // Print the tree (for debugging)
    void print() const {
        for (int i = 0; i < _size; i++) {
            cout << _array[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    // Example for BinaryTree
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    BinaryTree<int> tree(preorder, inorder, size);

    cout << "Pre-order traversal: ";
    tree.preorder();
    cout << endl;

    cout << "In-order traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postorder();
    cout << endl;

    // Example for ArrayBinaryTree
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    ArrayBinaryTree<int> arrayTree(array, 7);

    cout << "Array representation of the tree: ";
    arrayTree.print();

    cout << "Left child of node 0: " << arrayTree.left(0) << endl;
    cout << "Right child of node 0: " << arrayTree.right(0) << endl;
    cout << "Parent of node 1: " << arrayTree.parent(1) << endl;

    return 0;
}


