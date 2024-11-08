#include<iostream>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node *next;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Class representing the linked list
class LinkedList {
private:
    Node *head;  // Pointer to the head of the list

public:
    // Constructor to initialize the linked list
    LinkedList() {
        head = NULL;
    }

    // Function to insert nodes at the end of the list
    void insert(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to traverse and display the linked list
    void traverse() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        cout << "Traversing the list: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete the last node
    void deleteLastNode() {
        if (head == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        // If there is only one node
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Last node deleted." << endl;
            return;
        }

        // Traverse to the second last node
        Node *temp = head;
        while (temp->next != NULL && temp->next->next != NULL) {
            temp = temp->next;
        }

        // Delete the last node
        delete temp->next;
        temp->next = NULL;
        cout << "Last node deleted." << endl;
    }
};

int main() {
    LinkedList list;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Insert nodes based on user input
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        list.insert(val);
    }

    // Traverse the list before deletion
    list.traverse();

    // Deleting the last node
    list.deleteLastNode();

    // Traverse the list after deletion
    list.traverse();

    return 0;
}


