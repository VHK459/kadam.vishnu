#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heapArray; // Pointer to the array storing the heap
    int capacity;   // Maximum size of the heap
    int size;       // Current number of elements in the heap

    // Helper function to swap two elements
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Non-recursive heapify function
    void heapify(int index) {
        int largest = index; // Assume the current node is the largest
        while (true) {
            int left = 2 * index + 1;  // Left child index
            int right = 2 * index + 2; // Right child index

            // Check if the left child is larger than the current node
            if (left < size && heapArray[left] > heapArray[largest]) {
                largest = left;
            }

            // Check if the right child is larger than the current largest
            if (right < size && heapArray[right] > heapArray[largest]) {
                largest = right;
            }

            // If the largest is not the current node, swap and continue
            if (largest != index) {
                swap(heapArray[index], heapArray[largest]);
                index = largest; // Move to the largest child
            } else {
                break; // The heap property is satisfied
            }
        }
    }

public:
    // Constructor to initialize the heap
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        heapArray = new int[capacity]; // Dynamically allocate memory for the heap
    }

    // Destructor to free memory
    ~MaxHeap() {
        delete[] heapArray; // Free the dynamically allocated memory
    }

    // Insert a new element into the heap
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
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

    // Remove and return the maximum element (root)
    int extractMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1; // Error value
        }

        // The maximum element is at the root
        int max = heapArray[0];

        // Replace the root with the last element
        heapArray[0] = heapArray[size - 1];
        size--;

        // Fix the heap property by heapifying the root
        heapify(0);

        return max;
    }

    // Print the heap (for debugging)
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap(10); // Create a heap with capacity 10

    // Insert elements
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(40);

    cout << "Heap after insertions: ";
    heap.print();

    // Extract the maximum element
    cout << "Extracted max: " << heap.extractMax() << endl;
    cout << "Heap after extraction: ";
    heap.print();

    return 0;
}
