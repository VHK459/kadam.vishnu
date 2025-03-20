#include <iostream>
using namespace std;

// Template function to recursively heapify a subtree rooted at index i
template <typename T>
void heapify(T arr[], int size, int i) {
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

// Template function to build a max heap
template <typename T>
void buildMaxHeap(T arr[], int size) {
    // Start from the last non-leaf node and heapify each node
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

// Template function to perform heap sort
template <typename T>
void heapSort(T arr[], int size) {
    // Build the max heap
    buildMaxHeap(arr, size);

    // Extract elements one by one
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move the current root to the end
        heapify(arr, i, 0);   // Heapify the reduced heap
    }
}

// Template function to print an array
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example with integers
    int intArr[] = {12, 11, 13, 5, 6, 7};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Original integer array: ";
    printArray(intArr, intSize);

    heapSort(intArr, intSize);

    cout << "Sorted integer array: ";
    printArray(intArr, intSize);

    // Example with doubles
    double doubleArr[] = {12.5, 11.2, 13.7, 5.1, 6.9, 7.3};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

    cout << "Original double array: ";
    printArray(doubleArr, doubleSize);

    heapSort(doubleArr, doubleSize);

    cout << "Sorted double array: ";
    printArray(doubleArr, doubleSize);

    return 0;
}
