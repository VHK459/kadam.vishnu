#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    // Node class for the linked list
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* _front;  // Pointer to the front of the queue
    Node* _rear;   // Pointer to the rear of the queue
    int _size;     // Number of elements in the queue

public:
    // Constructor
    Queue() : _front(nullptr), _rear(nullptr), _size(0) {}

    // Destructor to free memory
    ~Queue() {
        while (!is_empty()) {
            dequeue();
        }
    }

    // Add an element to the rear of the queue
    void enqueue(const T& value) {
        Node* newNode = new Node(value);  // Create a new node
        if (is_empty()) {
            _front = _rear = newNode;  // If the queue is empty, set both front and rear to the new node
        } else {
            _rear->next = newNode;  // Link the new node to the rear
            _rear = newNode;        // Update the rear to the new node
        }
        _size++;  // Increment the size
    }

    // Remove and return the front element from the queue
    T dequeue() {
        if (is_empty()) {
            throw out_of_range("Queue underflow: Cannot dequeue from an empty queue");
        }
        Node* temp = _front;        // Store the current front node
        T front_element = temp->data;  // Get the front element
        _front = _front->next;      // Move the front to the next node
        delete temp;                // Free the memory of the old front node
        _size--;                    // Decrement the size

        if (is_empty()) {  // If the queue becomes empty, reset the rear
            _rear = nullptr;
        }
        return front_element;
    }

    // Get the front element without removing it
    T peek() const {
        if (is_empty()) {
            throw out_of_range("Queue is empty");
        }
        return _front->data;
    }

    // Check if the queue is empty
    bool is_empty() const {
        return _front == nullptr;
    }

    // Get the size of the queue
    int size() const {
        return _size;
    }

    // Print the queue (for debugging purposes)
    void print() const {
        Node* current = _front;
        cout << "Queue: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.print();  // Output: Queue: 10 20 30

    // Peek at the front element
    cout << "Front element: " << queue.peek() << endl;  // Output: 10

    // Dequeue elements
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: 10
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: 20
    queue.print();  // Output: Queue: 30

    // Check if the queue is empty
    cout << "Is queue empty? " << (queue.is_empty() ? "Yes" : "No") << endl;  // Output: No

    return 0;
}
