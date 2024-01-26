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

int findLength(Node *head)
{
    Node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
Node *swapNodes(Node *head, int k)
{
    int n = findLength(head);
    int end = n - k + 1;

    Node *temp1 = head;
    Node *temp2 = head;

    int i = 1;
    // saving the kth node from start
    while (i < k)
    {
        temp1 = temp1->next;
        i++;
    }
    Node *curr1 = temp1;
    i = 1;
    // saving the kth node from end
    while (i < end)
    {
        temp2 = temp2->next;
        i++;
    }
    Node *curr2 = temp2;

    // swapping the value of nodes
    int t = curr1->data;
    curr1->data = curr2->data;
    curr2->data = t;

    return head;
}

int main()
{
    Node *head = new Node();
    head->data = 4;

    head->next = new Node();
    head->next->data = 3;

    head->next->next = new Node();
    head->next->next->data = 2;

    cout << "Original LinkedList " << endl;
    prinLinkedList(head);
    cout << endl;
    int k = 1;
    cout << "Linked List after swapping the nodes by " << k << endl;
    Node *newhead = swapNodes(head, k);
    prinLinkedList(newhead);
    return 0;
}