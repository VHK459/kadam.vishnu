#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    // Internal Node class
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;  // Pointer to the first node
    Node* tail;  // Pointer to the last node
    int _length; // Variable to track the length of the list

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), _length(0) {}

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Append a node to the end of the list (O(1))
    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {  // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        _length++;  // Increment the length
    }

    // Prepend a node to the beginning of the list (O(1))
    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {  // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        _length++;  // Increment the length
    }

    // Remove the first occurrence of a node with the given value
    void remove(const T& value) {
        if (!head) return;  // If the list is empty

        // If the head node needs to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            _length--;  // Decrement the length

            if (!head) {  // If the list becomes empty
                tail = nullptr;
            }
            return;
        }

        // Traverse the list to find the node to delete
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        // If the node is found
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            _length--;  // Decrement the length

            // If the last node was deleted, update the tail
            if (!temp->next) {
                tail = temp;
            }
        }
    }

    // Remove the last node from the list
    void removeLast() {
        if (!head) return;  // If the list is empty

        if (head == tail) {  // If there's only one node
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        _length--;  // Decrement the length
    }

    // Remove the first node from the list
    void removeFirst() {
        if (!head) return;  // If the list is empty

        Node* temp = head;
        head = head->next;
        delete temp;
        _length--;  // Decrement the length

        if (!head) {  // If the list becomes empty
            tail = nullptr;
        }
    }

    // Get the length of the list
    int length() const {
        return _length;
    }

    // Print the list
    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list;

    // Append elements
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List after appending: ";
    list.print();  // Output: 10 20 30

    // Prepend elements
    list.prepend(5);
    list.prepend(1);
    cout << "List after prepending: ";
    list.print();  // Output: 1 5 10 20 30

    // Remove elements
    list.remove(10);
    cout << "List after removing 10: ";
    list.print();  // Output: 1 5 20 30

    // Remove first and last elements
    list.removeFirst();
    list.removeLast();
    cout << "List after removing first and last: ";
    list.print();  // Output: 5 20

    // Check length
    cout << "Length of the list: " << list.length() << endl;  // Output: 2

    return 0;
}
