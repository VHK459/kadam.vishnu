#include <iostream>

using namespace std;

// Node structure for Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete a node by value
    void deleteNode(int val) {
        Node* temp = head;
        while (temp && temp->data != val) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value not found!\n";
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } 
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } 
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Search for a value
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Display the list (Forward)
    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display the list (Backward)
    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtHead(5);

    cout << "Forward: ";
    dll.displayForward();

    cout << "Backward: ";
    dll.displayBackward();

    cout << "Deleting 20...\n";
    dll.deleteNode(20);

    cout << "After deletion:\n";
    dll.displayForward();

    cout << "Search 10: " << (dll.search(10) ? "Found" : "Not Found") << endl;
    cout << "Search 50: " << (dll.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}
