#include<iostream>
using namespace std;

int main()
{
    // Define a struct 'Node' that represents an element of the linked list
    struct Node
    {
        int data;    // Stores the data for the node
        Node *next;  // Pointer to the next node in the list
    };

    Node *head = NULL;  // Initialize the head pointer

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Taking input for the nodes
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

    // Traversing the linked list and printing the data
    cout << "Traversing: " << endl;
    Node *curr = head;  // Start traversal from the head
    while (curr != NULL)  // Loop until the end of the list (NULL)
    {
        cout << curr->data << " ";  // Print the data of the current node
        curr = curr->next;  // Move to the next node
    }
    cout << endl;

    // Inserting a new node in the middle of the list
    cout << "Insertion at Mid: " << endl;
    int insertion, newValue;
    cout << "Enter the value after which you want to insert a new node: ";
    cin >> insertion;  // Input the value after which the new node should be inserted
    cout << "Enter the value for the new node: ";
    cin >> newValue;

    Node *ptr = head;  // Pointer to traverse the list to find the insertion point
    // Traverse the list to find the node where insertion needs to happen
    while (ptr != NULL && ptr->data != insertion)
    {
        ptr = ptr->next;  // Move to the next node
    }

    // If the insertion point is found
    if (ptr != NULL)
    {
        Node *newNode = new Node;  // Create a new node
        newNode->data = newValue;  // Set the data for the new node
        newNode->next = ptr->next;  // Link the new node to the next node in the list
        ptr->next = newNode;  // Link the previous node to the new node
    }
    else
    {
        cout << "Node with value " << insertion << " not found. Insertion failed." << endl;
    }

    // Traversing the linked list again after insertion
    cout << "Traversing after insertion: " << endl;
    Node *current = head;  // Start traversal from the head again
    while (current != NULL)
    {
        cout << current->data << " ";  // Print the data of each node
        current = current->next;  // Move to the next node
    }
    cout << endl;

    // Deleting the last node
    cout << "Deleting the last node." << endl;

    if (head == NULL)
    {
        cout << "The list is empty. No node to delete." << endl;
    }
    else if (head->next == NULL)
    {
        // If there's only one node
        delete head;
        head = NULL;
        cout << "Only one node was present. It has been deleted." << endl;
    }
    else
    {
        // Traverse to the second-last node
        Node *secondLast = head;
        while (secondLast->next->next != NULL)
        {
            secondLast = secondLast->next;
        }

        // Delete the last node
        delete secondLast->next;
        secondLast->next = NULL;
    }

    // Traversing the linked list again after deletion
    cout << "Traversing after deletion: " << endl;
    Node *temp = head;  // Start traversal from the head again
    while (temp != NULL)
    {
        cout << temp->data << " ";  // Print the data of each node
        temp = temp->next;  // Move to the next node
    }
    cout << endl;

    return 0;
}

