#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int val) : data(val), next(nullptr), bottom(nullptr) {}
};

// merging two sorted linked lists using recusrion
Node *mergeLists(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *result = nullptr;

    if (a->data < b->data)
    {
        result = a;
        result->bottom = mergeLists(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = mergeLists(a, b->bottom);
    }

    return result;
}

// Flattening the linked list
Node *flattenLinkedList(Node *root)
{
    if (!root || !root->next)
    {
        return root;
    }

    Node *mergedLL = mergeLists(root, flattenLinkedList(root->next));
    return mergedLL;
}

// Function to print the linked list
void printList(Node *node)
{
    while (node)
    {
        std::cout << node->data << " ";
        node = node->bottom;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating a sample linked list
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);
    head->next->next->bottom = new Node(22);

    // Flatten the linked list
    Node *flattenedList = flattenLinkedList(head);

    // Print the flattened linked list
    std::cout << "Flattened Linked List:" << std::endl;
    printList(flattenedList);

    return 0;
}
