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
int getNthFromLast(Node *head, int n)
{
    Node *temp = head;
    int length = lengthOfLinkedList(head);
    if (n > length)
    {
        return -1;
    }
    for (int i = 1; i < length - n + 1; i++)
    {
        head = head->next;
    }
    return head->data;
}
int main()
{
    Node *tail = NULL;
    Node *head = NULL;
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);
    printLL(head);
    int n = 8;
    cout << "The last " << n << " element in linked list is " << endl;
    cout << getNthFromLast(head, n) << endl;
    return 0;
}