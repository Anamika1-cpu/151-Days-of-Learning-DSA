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
void insertAtHead(Node *&head, int data)
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

void removeDuplicates(Node *head)
{
    // what we are trying to do here is that we created a Node temp to
    // traverse the LL and checking that if the temp->data is equal to the
    // temp->next->data if this is true this means we found the duplicate node,
    // so we will delete this duplicate by managing it's next pointer
    Node *temp = head;
    while (temp != NULL)
    {
        while (temp->next != NULL && temp->data == temp->next->data)
        {
            Node *toDelete = temp->next;
            Node *nextNode = toDelete->next;
            toDelete->next = NULL;
            temp->next = nextNode;
        }
        temp = temp->next;
    }
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    cout << "Linked list before Removing Duplicate" << endl;
    printLL(head);
    removeDuplicates(head);
    cout << "Linked list after Removing Duplicate" << endl;
    printLL(head);
    return 0;
}