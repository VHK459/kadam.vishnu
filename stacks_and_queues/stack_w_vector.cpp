#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> _arr;  // Vector to store stack elements

public:
    // Push an element onto the stack
    void push(const T& value) {
        _arr.push_back(value);
    }

    // Pop the top element from the stack
    T pop() {
        if (is_empty()) {
            throw out_of_range("Stack underflow: Cannot pop from an empty stack");
        }
        T top_element = _arr.back();  // Get the top element
        _arr.pop_back();              // Remove the top element
        return top_element;
    }

    // Get the top element without removing it
    T peek() const {
        if (is_empty()) {
            throw out_of_range("Stack is empty");
        }
        return _arr.back();
    }

    // Check if the stack is empty
    bool is_empty() const {
        return _arr.empty();
    }

    // Get the size of the stack
    int size() const {
        return _arr.size();
    }

    // Print the stack (for debugging purposes)
    void print() const {
        cout << "Stack: ";
        for (const T& element : _arr) {
            cout << element << " ";
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
    stack.print();  // Output: Stack: 10 20 30

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
