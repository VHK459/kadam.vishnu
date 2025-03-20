#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;       // Pointer to the array storing stack elements
    int capacity;   // Maximum capacity of the stack
    int topIndex;   // Index of the top element

    // Helper function to resize the array
    void resize() {
        capacity *= 2; // Double the capacity
        int* newArr = new int[capacity];
        for (int i = 0; i <= topIndex; i++) {
            newArr[i] = arr[i]; // Copy elements to the new array
        }
        delete[] arr; // Free the old array
        arr = newArr; // Point to the new array
    }

public:
    // Constructor
    Stack(int initialCapacity = 10) : capacity(initialCapacity), topIndex(-1) {
        arr = new int[capacity]; // Allocate memory for the array
    }

    // Destructor
    ~Stack() {
        delete[] arr; // Free the allocated memory
    }

    // Push an element onto the stack
    void push(int x) {
        if (topIndex == capacity - 1) {
            resize(); // Resize the array if it's full
        }
        arr[++topIndex] = x; // Add the element and increment topIndex
    }

    // Remove and return the top element of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1; // Error value
        }
        return arr[topIndex--]; // Return the top element and decrement topIndex
    }

    // Return the top element of the stack without removing it
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Error value
        }
        return arr[topIndex]; // Return the top element
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Get the size of the stack
    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Print the top element
    cout << "Top element: " << stack.top() << endl; // Output: 30

    // Pop elements from the stack
    cout << "Popped element: " << stack.pop() << endl; // Output: 30
    cout << "Popped element: " << stack.pop() << endl; // Output: 20

    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: No

    // Print the size of the stack
    cout << "Stack size: " << stack.size() << endl; // Output: 1

    return 0;
}
