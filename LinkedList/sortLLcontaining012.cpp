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
Node *segregate(Node *head)
{
    Node *temp = head;
    int one = 0, two = 0, zero = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
        temp = temp->next;
    }
    temp = head;
    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node *head = new Node();
    head->data = 0;

    head->next = new Node();
    head->next->data = 1;

    head->next->next = new Node();
    head->next->next->data = 2;

    head->next->next->next = new Node();
    head->next->next->next->data = 0;

    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 1;
    head->next->next->next->next->next = new Node();
    head->next->next->next->next->next->data = 2;

    cout << "Original LinkedList " << endl;
    prinLinkedList(head);
    cout << endl;
    cout << "LinkedList after sorting" << endl;
    Node *newHead = segregate(head);
    prinLinkedList(newHead);
    return 0;
}