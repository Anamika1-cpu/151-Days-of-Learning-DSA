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

Node *reverseLL(Node *&head)
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
    return head;
}
Node *addONe(Node *head)
{
    // reverse the LL
    head = reverseLL(head);
    // add 1
    int carry = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        int totalSum = carry + temp->data;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;

        if (carry == 0)
        {
            break; // if carry is 0. This means the addtion
            // is handled in single digit
        }
        temp = temp->next;
    }
    // processing the last node
    if (carry != 0)
    {
        int totalSum = carry + temp->data;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;
        if (carry != 0)
        {
            // after handling the last node,
            // and carry is left than we have to add a mnode in LL
            Node *newNode = new Node(carry);
            temp->next = newNode;
        }
    }
    head = reverseLL(head);
    return head;
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 0);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    cout << "Original Linked List: " << endl;
    printLL(head);
    Node *prev = NULL;
    Node *curr = head;
    head = addONe(head);
    cout << "Linked List after adding 1 in LL: " << endl;
    printLL(head);
    return 0;
}