#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;       // Pointer to the array storing queue elements
    int capacity;   // Maximum capacity of the queue
    int frontIndex; // Index of the front element
    int rearIndex;  // Index of the rear element
    int size;       // Current number of elements in the queue

    // Helper function to resize the array
    void resize() {
        capacity *= 2; // Double the capacity
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(frontIndex + i) % size]; // Copy elements to the new array
        }
        delete[] arr; // Free the old array
        arr = newArr; // Point to the new array
        frontIndex = 0;
        rearIndex = size - 1;
    }

public:
    // Constructor
    Queue(int initialCapacity = 10) : capacity(initialCapacity), frontIndex(0), rearIndex(-1), size(0) {
        arr = new int[capacity]; // Allocate memory for the array
    }

    // Destructor
    ~Queue() {
        delete[] arr; // Free the allocated memory
    }

    // Add an element to the queue
    void enqueue(int x) {
        if (size == capacity) {
            resize(); // Resize the array if it's full
        }
        rearIndex = (rearIndex + 1) % capacity; // Circular increment
        arr[rearIndex] = x; // Add the element
        size++; // Increment size
    }

    // Remove and return the front element of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return -1; // Error value
        }
        int frontElement = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity; // Circular increment
        size--; // Decrement size
        return frontElement;
    }

    // Return the front element of the queue without removing it
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Error value
        }
        return arr[frontIndex]; // Return the front element
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Get the size of the queue
    int getSize() {
        return size;
    }
};

int main() {
    Queue queue;

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
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl; // Output: No

    // Print the size of the queue
    cout << "Queue size: " << queue.getSize() << endl; // Output: 1

    return 0;
}
