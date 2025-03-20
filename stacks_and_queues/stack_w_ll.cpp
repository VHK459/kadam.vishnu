#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    // Node class for the linked list
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* _top;  // Pointer to the top of the stack
    int _size;   // Number of elements in the stack

public:
    // Constructor
    Stack() : _top(nullptr), _size(0) {}

    // Destructor to free memory
    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }

    // Push an element onto the stack
    void push(const T& value) {
        Node* newNode = new Node(value);  // Create a new node
        newNode->next = _top;             // Link the new node to the current top
        _top = newNode;                   // Update the top to the new node
        _size++;                          // Increment the size
    }

    // Pop the top element from the stack
    T pop() {
        if (is_empty()) {
            throw out_of_range("Stack underflow: Cannot pop from an empty stack");
        }
        Node* temp = _top;        // Store the current top node
        T top_element = temp->data;  // Get the top element
        _top = _top->next;        // Move the top to the next node
        delete temp;              // Free the memory of the old top node
        _size--;                  // Decrement the size
        return top_element;
    }

    // Get the top element without removing it
    T peek() const {
        if (is_empty()) {
            throw out_of_range("Stack is empty");
        }
        return _top->data;
    }

    // Check if the stack is empty
    bool is_empty() const {
        return _top == nullptr;
    }

    // Get the size of the stack
    int size() const {
        return _size;
    }

    // Print the stack (for debugging purposes)
    void print() const {
        Node* current = _top;
        cout << "Stack: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();  // Output: Stack: 30 20 10

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;  // Output: 30

    // Pop elements from the stack
    cout << "Popped: " << stack.pop() << endl;  // Output: 30
    cout << "Popped: " << stack.pop() << endl;  // Output: 20
    stack.print();  // Output: Stack: 10

    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.is_empty() ? "Yes" : "No") << endl;  // Output: No

    return 0;
}
