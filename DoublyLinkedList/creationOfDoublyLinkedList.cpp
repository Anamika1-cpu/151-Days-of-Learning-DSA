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

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

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

// Insertion at Position
void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    int len = findLength(head);
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (pos == len + 1)
    {
        insertAtHead(head, tail, data);
    }
    else
    {
        Node *newNode = new Node(data);
        Node *prevNode = NULL;
        Node *currNode = head;
        while (pos != 1)
        {
            prevNode = currNode;
            currNode = currNode->next;
            pos--;
        }
        prevNode->next = newNode;
        currNode->prev = newNode;
        newNode->next = currNode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 1);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 8);
    insertAtTail(head, tail, 9);
    insertAtPosition(head, tail, 100, 4);
    printLL(head);
    return 0;
}