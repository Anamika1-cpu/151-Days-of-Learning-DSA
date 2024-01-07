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

Node *mergeTwoLists(Node *list1, Node *list2)
{
    // if one of the list empty then returning the other list
    if (list1 == 0)
        return list2;
    if (list2 == 0)
        return list1;
    Node *ans = new Node(-1);
    Node *mptr = ans;

    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            mptr->next = list1;
            mptr = list1;
            list1 = list1->next;
        }
        else
        {
            mptr->next = list2;
            mptr = list2;
            list2 = list2->next;
        }
    }
    if (list1)
    {
        mptr->next = list1;
    }
    if (list2)
    {
        mptr->next = list2;
    }
    return ans->next;
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 9);
    insertAtHead(head, 7);
    insertAtHead(head, 4);
    cout << "Original Linked Lists: " << endl;
    printLL(head);
    Node *head2 = NULL;
    insertAtHead(head2, 5);
    insertAtHead(head2, 2);
    insertAtHead(head2, 1);
    printLL(head2);
    Node *ans = mergeTwoLists(head, head2);
    cout << "Linked List after merging: " << endl;
    printLL(ans);
    return 0;
}