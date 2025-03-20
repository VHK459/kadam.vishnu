#include <iostream>
using namespace std;

// Function to recursively heapify a subtree rooted at index i
void heapify(int arr[], int size, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap the root with the largest
        heapify(arr, size, largest); // Recursively heapify the affected subtree
    }
}

// Function to build a max heap
void buildMaxHeap(int arr[], int size) {
    // Start from the last non-leaf node and heapify each node
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int size) {
    // Build the max heap
    buildMaxHeap(arr, size);

    // Extract elements one by one
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move the current root to the end
        heapify(arr, i, 0);   // Heapify the reduced heap
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    heapSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
