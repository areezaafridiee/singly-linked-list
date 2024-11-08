#include<iostream>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize the node with a value
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Class representing the linked list
class LinkedList {
private:
    Node* head;  // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);  // Create a new node
        newNode->next = head;  // Point the new node's next to the current head
        head = newNode;  // Update the head to the new node
    }

    // Function to traverse and print the linked list
    void traverse() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Traversing the list: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, value;

    // Ask the user how many elements to insert
    cout << "Enter the number of elements to insert at the beginning: ";
    cin >> n;

    // Insert elements at the beginning
    for (int i = 0; i < n; i++) {
        cout << "Enter value to insert: ";
        cin >> value;
        list.insertAtBeginning(value);
    }

    // Traverse the list after insertions
    list.traverse();

    return 0;
}

