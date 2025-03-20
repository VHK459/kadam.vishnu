#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> queue1; // Main queue to store stack elements
    queue<int> queue2; // Helper queue for push operations

public:
    // Push an element onto the stack
    void push(int x) {
        // Add the new element to queue2
        queue2.push(x);

        // Move all elements from queue1 to queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        // Swap the names of queue1 and queue2
        swap(queue1, queue2);
    }

    // Remove and return the top element of the stack
    int pop() {
        if (queue1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Error value
        }
        int topElement = queue1.front();
        queue1.pop();
        return topElement;
    }

    // Return the top element of the stack without removing it
    int top() {
        if (queue1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Error value
        }
        return queue1.front();
    }

    // Check if the stack is empty
    bool empty() {
        return queue1.empty();
    }
};

int main() {
    StackUsingQueues stack;

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
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: No

    // Push another element
    stack.push(40);

    // Print the top element
    cout << "Top element: " << stack.top() << endl; // Output: 40

    return 0;
}
