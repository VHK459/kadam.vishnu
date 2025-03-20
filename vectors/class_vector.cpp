#include <iostream>
using namespace std;

template <class T>
class Vector {
private:
    T* _arr;        // Pointer to the dynamic array
    int _capacity;  // Current capacity of the array
    int _size;      // Current number of elements in the array

    // Helper function to resize the array
    void revise_capacity(int new_cap) {
        T* new_arr = new T[new_cap];  // Create a new array with the new capacity
        for (int i = 0; i < _size; i++) {
            new_arr[i] = _arr[i];     // Copy elements from the old array to the new array
        }
        delete[] _arr;                // Free memory of the old array
        _arr = new_arr;               // Point to the new array
        _capacity = new_cap;          // Update the capacity
    }

public:
    // Constructor
    Vector(int cap = 1) {
        _arr = new T[cap];  // Allocate memory for the array
        _capacity = cap;    // Set initial capacity
        _size = 0;          // Initialize size to 0
    }

    // Destructor
    ~Vector() {
        delete[] _arr;  // Free memory when the object is destroyed
    }

    // Add an element to the end of the array
    void append(const T& elem) {
        if (_size == _capacity) {  // If the array is full, double its capacity
            revise_capacity(2 * _capacity);
        }
        _arr[_size] = elem;  // Add the element to the end
        _size++;             // Increment the size
    }

    // Remove and return the last element of the array
    T removeLast() {
        if (_size == 0) {
            throw out_of_range("Cannot remove from an empty vector");
        }
        T ret = _arr[_size - 1];  // Store the last element
        _size--;                  // Decrement the size

        // If the size is 1/4 of the capacity, shrink the array by half
        if (_size == _capacity / 4 && _capacity > 1) {
            revise_capacity(_capacity / 2);
        }

        return ret;  // Return the removed element
    }

    // Get the current size of the array
    int size() const {
        return _size;
    }

    // Get the current capacity of the array
    int capacity() const {
        return _capacity;
    }

    // Print the elements of the array
    void print() const {
        for (int i = 0; i < _size; i++) {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector<int> vec;  // Create a vector of integers

    // Append elements
    vec.append(10);
    vec.append(20);
    vec.append(30);
    vec.append(40);

    cout << "Vector after appending elements: ";
    vec.print();  // Output: 10 20 30 40

    // Remove the last element
    cout << "Removed element: " << vec.removeLast() << endl;  // Output: 40
    cout << "Vector after removing last element: ";
    vec.print();  // Output: 10 20 30

    // Check size and capacity
    cout << "Size: " << vec.size() << endl;      // Output: 3
    cout << "Capacity: " << vec.capacity() << endl;  // Output: 4

    return 0;
}
