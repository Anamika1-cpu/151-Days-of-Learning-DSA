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

void solve(Node *head, int &carry)
{
    if (!head)
        return;
    ;
    solve(head->next, carry);
    int prod = head->data * 2 + carry;
    head->data = prod % 10;
    carry = prod / 10;
}
Node *doubleIt(Node *head)
{
    int carry = 0;
    solve(head, carry);
    if (carry != 0)
    {
        Node *carryNode = new Node(carry);
        carryNode->next = head;
        head = carryNode;
    }
    return head;
}

int main()
{
    Node *head = new Node();
    head->data = 8;

    head->next = new Node();
    head->next->data = 8;

    head->next->next = new Node();
    head->next->next->data = 8;

    cout << "Original LinkedList " << endl;
    prinLinkedList(head);
    cout << endl;
    cout << "LinkedList after multiplying by 2 " << endl;
    Node *newhead = doubleIt(head);
    prinLinkedList(newhead);
    return 0;
}