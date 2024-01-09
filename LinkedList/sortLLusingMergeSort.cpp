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
        mptr->next = list1;
    if (list2)
        mptr->next = list2;
    return ans->next;
}
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

Node *sortList(Node *head)
{
    if (head == 0 || head->next == 0)
    {
        return head;
    }
    // break in 2 halves using mid
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = 0;

    left = sortList(left);
    right = sortList(right);
    // merge both
    Node *mergedll = mergeTwoLists(left, right);
    return mergedll;
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 123);
    insertAtHead(head, 54);
    insertAtHead(head, 80);
    insertAtHead(head, 16);
    insertAtHead(head, 32);
    cout << "Linked list before sorting:" << endl;
    printLL(head);
    cout << "Linked list after sorting:" << endl;
    Node *ans = sortList(head);
    printLL(ans);
    return 0;
}