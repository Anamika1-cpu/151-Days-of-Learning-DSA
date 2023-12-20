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

int lengthOfLinkedList(Node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

int getMiddle(Node *head)
{
    int length = lengthOfLinkedList(head);
    int pos = (length / 2) + 1;

    int data = -1;
    Node *prev = NULL;
    Node *curr = head;
    while (pos != 1)
    {
        prev = curr;
        curr = curr->next;
        pos--;
    }
    data = curr->data;
    return data;
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    printLL(head);
    cout << "The middle of the above Linked List is " << endl;
    cout << getMiddle(head);
    return 0;
}