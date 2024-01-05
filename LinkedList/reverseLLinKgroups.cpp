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
int findLength(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
Node *reverseKGroup(Node *head, int k)
{
    if (head == NULL)
        return head;
    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode = NULL;
    int len = findLength(head);
    if (len < k)
    {
        return head;
    }
    int pos = 1;
    while (pos <= k && curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos++;
    }
    Node *recAns = NULL;
    if (nextNode != NULL)
    {
        recAns = reverseKGroup(nextNode, k);
        head->next = recAns;
    }
    return prev;
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    cout << "Original Linked List: " << endl;
    printLL(head);
    int k = 4;
    head = reverseKGroup(head, k);
    cout << " Linked List after reversing in group of " << k << " : " << endl;
    printLL(head);
    return 0;
}