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
Node *oddEvenList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *h1 = head;       // denoting the odd list
    Node *h2 = head->next; // denoting the even list
    Node *evenHead = h2;   // keeping track of even list to join at the end
    while (h2 && h2->next)
    {
        h1->next = h2->next;
        h2->next = h2->next->next;
        h1 = h1->next;
        h2 = h2->next;
    }
    h1->next = evenHead; // joining the LLs
    return head;
}

int main()
{
    Node *head = new Node();
    head->data = 4;

    head->next = new Node();
    head->next->data = 12;

    head->next->next = new Node();
    head->next->next->data = 0;

    head->next->next->next = new Node();
    head->next->next->next->data = 1;

    cout << "Original LinkedList " << endl;
    prinLinkedList(head);
    cout << endl;
    cout << "LinkedList after reaaranging nodes of Linked List" << endl;
    Node *newhead = oddEvenList(head);
    prinLinkedList(newhead);
    return 0;
}