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

void prinLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

Node *sortedInsert(struct Node *head, int data)
{
    // Code here
    Node *newNode = new Node(data);
    if (head == NULL || data < head->data)
    {
        newNode->next = head;
        return newNode;
    }

    Node *current = head;

    while (current->next != NULL && current->next->data < data)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}
int main()
{
    Node *head = new Node();
    head->data = 12;

    head->next = new Node();
    head->next->data = 20;

    head->next->next = new Node();
    head->next->next->data = 25;

    head->next->next->next = new Node();
    head->next->next->next->data = 30;

       cout << "Original LinkedList " << endl;
    prinLinkedList(head);
    cout << endl;
    cout << "LinkedList after insertion" << endl;
    sortedInsert(head, 18);
    prinLinkedList(head);
    return 0;
}