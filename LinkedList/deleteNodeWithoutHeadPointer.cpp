#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // check for empty node
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // check for empty node
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "\n";
}
void deleteNode(Node *del)
{
    // if the node which is being deleted is the last node
    if (del->next == NULL)
    {
        del = NULL;
        return;
    }
    // what we are doing here is that
    // copying the data from the next data to the previous node
    del->data = del->next->data;
    del->next = del->next->next;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 4);
    insertAtHead(head, tail, 2);
    insertAtTail(head, tail, 5);
    insertAtHead(head, tail, 11);
    insertAtHead(head, tail, 3);
    printLL(head);
    Node *todel = head->next;
    deleteNode(todel);
    printLL(head);
    return 0;
}