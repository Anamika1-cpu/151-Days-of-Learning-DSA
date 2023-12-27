#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Finding length of DLL
int findLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
// Insertion at Head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // LL is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty
        Node *newNode = new Node(data);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Insertion at tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // LL is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    // LL is not empty
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
// printing DLL
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
}
// Deletion of Node
void deletionFromHead(Node *&head, Node *&tail)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}
// Deletion of Node
void deletionFromTail(Node *&head, Node *&tail)
{
    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
}

// deletion  at position
void deleteAtPosition(Node *&head, int pos)
{
    int len = findLength(head);
    Node *temp = head;
    Node *tail = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
    if (pos == 1)
    {
        deletionFromHead(head, tail);
    }
    else if (pos == len)
    {
        deletionFromTail(head, tail);
    }
    else
    {
        Node *prevNode = NULL;
        Node *currNode = head;
        while (pos != 1)
        {
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node *nextNode = currNode->next;

        prevNode->next = nextNode;
        currNode->next = NULL;
        currNode->prev = NULL;
        nextNode->prev = prevNode;

        delete currNode;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 1);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 8);
    insertAtTail(head, tail, 9);
    cout << "This is the original Doubly Linked List" << endl;
    printLL(head);
    cout << endl;
    deletionFromHead(head, tail);
    cout << "Doubly Linked List after deletion from Head" << endl;
    printLL(head);
    cout << endl;
    int n = 2;
    deleteAtPosition(head, n);
    cout << "Doubly Linked List after deletion from position " << n << endl;
    printLL(head);
    return 0;
}