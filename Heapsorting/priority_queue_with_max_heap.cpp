#include <iostream>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    T* heapArray; // Array to store the heap elements
    int capacity; // Maximum size of the priority queue
    int size;     // Current number of elements in the priority queue

    // Helper function to swap two elements
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    // Recursive heapify function to maintain the heap property
    void heapify(int index) {
        int largest = index;       // Initialize largest as root
        int left = 2 * index + 1;  // Left child
        int right = 2 * index + 2; // Right child

        // If left child is larger than root
        if (left < size && heapArray[left] > heapArray[largest]) {
            largest = left;
        }

        // If right child is larger than the largest so far
        if (right < size && heapArray[right] > heapArray[largest]) {
            largest = right;
        }

        // If the largest is not the root
        if (largest != index) {
            swap(heapArray[index], heapArray[largest]); // Swap the root with the largest
            heapify(largest); // Recursively heapify the affected subtree
        }
    }

public:
    // Constructor to initialize the priority queue
    PriorityQueue(int capacity) : capacity(capacity), size(0) {
        heapArray = new T[capacity]; // Dynamically allocate memory for the heap
    }

    // Destructor to free memory
    ~PriorityQueue() {
        delete[] heapArray; // Free the dynamically allocated memory
    }

    // Insert an element into the priority queue
    void insert(T value) {
        if (size == capacity) {
            cout << "Priority queue is full!" << endl;
            return;
        }

        // Add the new element at the end
        heapArray[size] = value;
        int current = size;
        size++;

        // Fix the heap property by moving the new element up
        while (current > 0 && heapArray[current] > heapArray[(current - 1) / 2]) {
            swap(heapArray[current], heapArray[(current - 1) / 2]);
            current = (current - 1) / 2; // Move to the parent
        }
    }

    // Remove and return the element with the highest priority
    T extractMax() {
        if (size == 0) {
            cout << "Priority queue is empty!" << endl;
            return T(); // Return default value for type T
        }

        // The maximum element is at the root
        T max = heapArray[0];

        // Replace the root with the last element
        heapArray[0] = heapArray[size - 1];
        size--;

        // Fix the heap property by heapifying the root
        heapify(0);

        return max;
    }

    // Get the element with the highest priority without removing it
    T peek() const {
        if (size == 0) {
            cout << "Priority queue is empty!" << endl;
            return T(); // Return default value for type T
        }
        return heapArray[0];
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get the current size of the priority queue
    int getSize() const {
        return size;
    }

    // Print the priority queue (for debugging)
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue<int> pq(10); // Create a priority queue with capacity 10

    // Insert elements
    pq.insert(10);
    pq.insert(20);
    pq.insert(15);
    pq.insert(30);
    pq.insert(40);

    cout << "Priority queue after insertions: ";
    pq.print();

    // Extract the element with the highest priority
    cout << "Extracted max: " << pq.extractMax() << endl;
    cout << "Priority queue after extraction: ";
    pq.print();

    // Peek at the element with the highest priority
    cout << "Peek at max: " << pq.peek() << endl;

    // Check if the priority queue is empty
    cout << "Is priority queue empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;

    // Get the current size of the priority queue
    cout << "Size of priority queue: " << pq.getSize() << endl;

    return 0;
}
