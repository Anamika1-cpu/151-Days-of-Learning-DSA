#include <bits/stdc++.h>
using namespace std;

// creating a Node
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

void insertionAtHead(Node *&head, int data)
{
    // if Linked List is empty
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
void prinLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

void deleteNode(Node *&head, int x)
{
    // deletion from head
    if (x == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deletion from middle of ll
        Node *prev = NULL;
        Node *curr = head;
        while (x != 1)
        {
            prev = curr;
            curr = curr->next;
            x--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *head = NULL;
    insertionAtHead(head, 30);
    insertionAtHead(head, 40);
    insertionAtHead(head, 50);
    insertionAtHead(head, 60);
    cout << "Linked List before deletion" << endl;
    prinLinkedList(head);
    cout << endl;
    deleteNode(head, 2);
    cout << "Linked List after deletion" << endl;
    prinLinkedList(head);
    return 0;
}