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

int getLength(Node *head)
{
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}
Node *rotateRight(Node *head, int k)
{
    if (!head)
        return NULL;
    int len = getLength(head);
    if (k == 0)
        return head;
    int actualRotateK = (k % len);
    if (actualRotateK == 0)
    {
        return head;
    }
    int newLastNodePos = len - actualRotateK - 1;
    Node *newLastNode = head;

    for (int i = 0; i < newLastNodePos; i++)
    {
        newLastNode = newLastNode->next;
    }
    Node *newHead = newLastNode->next;
    newLastNode->next = nullptr;

    Node *it = newHead;
    while (it->next)
    {
        it = it->next;
    }
    it->next = head;
    return newHead;
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
    int k = 3;
    cout << "LinkedList after rotating by " << k << " elements" << endl;
    Node *newhead = rotateRight(head, k);
    prinLinkedList(newhead);
    return 0;
}