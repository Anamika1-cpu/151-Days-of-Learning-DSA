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

void linkDelete(Node *head, int n, int m)
{
    if (head == NULL)
        return;
    Node *it = head;
    // we need to be on the mth node that's why m-1
    for (int i = 0; i < m - 1; i++)
    {
        // if m nodes are not available
        if (it == NULL)
            return;
        it = it->next;
    }
    // now it would be on mth node
    if (it == NULL)
        return;
    Node *mthNode = it;
    it = mthNode->next;
    for (int i = 0; i < n; i++)
    {
        if (it == NULL)
            break;
        Node *temp = it->next;
        delete it;
        it = temp;
    }
    mthNode->next = it;
    linkDelete(it, n, m); // recursive call
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
    int n = 2;
    int m = 3;
    linkDelete(head, n, m);
    cout << " Linked List after deleting " << n << " nodes after " << m << " nodes : " << endl;
    printLL(head);
    return 0;
}