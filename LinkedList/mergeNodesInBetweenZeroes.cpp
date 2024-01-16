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

Node *mergeNodes(Node *head)
{
    if (!head)
        return NULL;
    Node *fast = head->next;
    Node *slow = head;
    Node *newLastnode = NULL;
    int sum = 0;
    while (fast != NULL)
    {
        if (fast->data != 0)
        {
            sum += fast->data;
        }
        else
        {
            slow->data = sum;
            newLastnode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }
    Node *temp = newLastnode->next;
    newLastnode->next = NULL;
    // Deleting the remaining ll
    while (temp != NULL)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    return head;
}

int main()
{
    Node *head = new Node();
    head->data = 0;

    head->next = new Node();
    head->next->data = 4;

    head->next->next = new Node();
    head->next->next->data = 2;

    head->next->next->next = new Node();
    head->next->next->next->data = 0;

    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 10;

    head->next->next->next->next->next = new Node();
    head->next->next->next->next->next->data = 0;

    cout << "Original LinkedList " << endl;
    prinLinkedList(head);
    cout << endl;
    cout << "LinkedList after merging nodes of Linked List" << endl;
    Node *newhead = mergeNodes(head);
    prinLinkedList(newhead);
    return 0;
}