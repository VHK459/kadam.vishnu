#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1; // Stack for enqueue operations
    stack<int> stack2; // Stack for dequeue operations

public:
    // Add an element to the queue
    void enqueue(int x) {
        stack1.push(x); // Push the new element onto stack1
    }

    // Remove and return the front element of the queue
    int dequeue() {
        if (stack2.empty()) {
            // Move all elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Error value
        }
        int frontElement = stack2.top();
        stack2.pop();
        return frontElement;
    }

    // Return the front element of the queue without removing it
    int front() {
        if (stack2.empty()) {
            // Move all elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Error value
        }
        return stack2.top();
    }

    // Check if the queue is empty
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStacks queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Print the front element
    cout << "Front element: " << queue.front() << endl; // Output: 10

    // Dequeue elements
    cout << "Dequeued element: " << queue.dequeue() << endl; // Output: 10
    cout << "Dequeued element: " << queue.dequeue() << endl; // Output: 20

    // Check if the queue is empty
    cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Output: No

    // Enqueue another element
    queue.enqueue(40);

    // Print the front element
    cout << "Front element: " << queue.front() << endl; // Output: 30

    return 0;
}
