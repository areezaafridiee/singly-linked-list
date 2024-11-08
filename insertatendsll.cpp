#include<iostream>
using namespace std;

int main()
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head = NULL;  // Initialize the head pointer
    int n;

    // Ask the user for the number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Take user input for each node
    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;

        Node *newNode = new Node;  // Create a new node
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;  // If list is empty, new node is the head
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;  // Move to the last node
            }
            temp->next = newNode;  // Link the last node to the new node
        }
    }

    // Traversing and printing the linked list
    cout << "Traversing the list: " << endl;
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Inserting a new node at the end based on user input
    cout << "Insertion at the End: " << endl;
    int newValue;
    cout << "Enter the value to insert at the end: ";
    cin >> newValue;

    Node *newNode = new Node;  // Create a new node for the end
    newNode->data = newValue;
    newNode->next = NULL;

    // Traverse to the last node to insert the new node
    if (head == NULL)
    {
        head = newNode;  // If list was empty, the new node is now the head
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Traversing and printing the linked list after insertion at the end
    cout << "Traversing the list after insertion: " << endl;
    curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}

