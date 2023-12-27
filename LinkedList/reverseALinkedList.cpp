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

void reverseLL(Node *&head)
{ // iterative method
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}
// recursive method
void RecreverseLL(Node *&prev, Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    Node *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    // recursion
    RecreverseLL(prev, curr);
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 11);
    insertAtHead(head, 3);
    cout << "Original Linked List: " << endl;
    printLL(head);
    reverseLL(head);
    cout << " Linked List after reversing: " << endl;
    printLL(head);
    return 0;
}