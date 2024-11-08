#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    int n;  // Number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of nodes should be positive." << endl;
        return 1;
    }

    // Create the first node
    Node *head = new Node;
    Node *curr = head;

    // Ask the user to input data for each node
    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> curr->data;
        
        // If it's not the last node, create the next node
        if (i < n - 1) {
            curr->next = new Node;
            curr = curr->next;
        } else {
            curr->next = NULL;  // Last node points to NULL
        }
    }

    // Traversing the list and printing the data
    cout << "Traversing the list: " << endl;
    curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Deletion at the beginning of the list (i.e., removing head)
    cout << "Deletion at the beginning of the list: " << endl;
    Node *temp = head;
    head = head->next;  // New head after deletion
    delete temp;  // Delete the old head

    // Traversing the list after deletion
    cout << "Traversing the list after deletion: " << endl;
    curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Deallocate remaining nodes
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

